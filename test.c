#include <stdio.h>
// #include <stdlib.h>

// Everything in type float (%f)

// Declarations
// Swap: contains two parameters of type "float pointer"
// Swaps the contents of each pointer with each other. No return value
void swap(float *a, float *b);
void print_arr(float arr[], int len);
void selection_sort(float arr[], int len);
void bubble_sort(float arr[], int len);
void insertion_sort(float arr[], int len);
void heap_sort(float arr[], int len);
void heapify(int parent_node, int len, float arr[]);
void quick_sort(float arr[], int lower_bound, int upper_bound);
void divide(int lower_bound, int comparitor, int partition);

int main()
{
    float nums[14] = {10, 35, 1, 38, 2, 13, 39, 4, 34, 3, 36, 37, 5, 6};
    int len = 14;
    quick_sort(nums, 0, len - 1);

    printf("Sorted Array:\n");
    print_arr(nums, len);
    return 0;
}

void quick_sort(float arr[], int lower_bound, int upper_bound)
{
    // define comparitor as the lower bound to iterate through the sorted position of the upper bound (pivot)
    int comparitor = lower_bound;
    // define the static lower bound so that we have a lower bound for recursive calls on the left split
    int static_lower_bound = lower_bound;

    // loop to iterate through array comparing upper_bound (pivot) with each element
    while (comparitor < upper_bound)
    {

        // move each element smaller than upper_bound to position lower than lower_bound
        if (arr[comparitor] < arr[upper_bound])
        {
            swap(&arr[lower_bound], &arr[comparitor]);
            lower_bound++;
        }

        comparitor++;
    }

    // move upper_bound (pivot) to correct position (pivot is now sorted)
    swap(&arr[lower_bound], &arr[upper_bound]);

    // recursivly call quick_sort on left and right sub_arrays as long as they are unsorted
    // base case for left and right is slightly different

    // condition to define base case for right split:
    if (upper_bound - lower_bound > 1)
    {
        // recursivly call quicksort on upper half of array
        // lower_bound = lower_bound + 1
        // upper_bound = upper_bound
        quick_sort(arr, lower_bound + 1, upper_bound);
    }

    // condition to define base case for left split:
    if (lower_bound - static_lower_bound > 1)
    {
        // recursivly call quicksort on lower half of array
        // lower_bound = static_lower_bound
        // upper_bound = lower_bound - 1
        quick_sort(arr, static_lower_bound, lower_bound - 1);
    }
}

void divide(int lower_bound, int comparitor, int partition)
{
}

void heap_sort(float arr[], int len)
{
    // parent node array counter
    int counter = (len / 2) - 1;

    // Loop to heapify all parent nodes except for the top node (0) starting with the last one (arr[len / 2])
    while (counter > 0)
    {
        heapify(counter, len, arr);
        counter--;
    }

    // sub-array-length
    int sub_array_len = len;

    // Loop to heapify top node, swap first and last until, and decrement the sub array until the whole array is sorted
    while (sub_array_len > 1)
    {
        heapify(0, sub_array_len, arr);

        // swap first and last element of sub array
        swap(&arr[0], &arr[sub_array_len - 1]);

        // decrement sub_array_len
        sub_array_len--;
    }
}

void heapify(int parent_node, int len, float arr[])
{
    // loop to heapify node
    while (parent_node < len / 2)
    {
        // define child nodes
        int child_1 = (parent_node * 2) + 1;
        int child_2 = (parent_node * 2) + 2;
        int large_child;

        // define largest child node (or conditionally select largest child node)
        if (arr[child_1] > arr[child_2] || child_2 >= len)
        {
            large_child = child_1;
        }
        else
        {
            large_child = child_2;
        }

        // compare largest child node with parent node
        // if child is less than parent: break out of loop - exit function
        if (arr[large_child] < arr[parent_node])
        {
            parent_node = large_child;
            continue;
        }

        // swap child and parent (else that doesn't need to be in conditional block)
        swap(&arr[large_child], &arr[parent_node]);

        // assign parent_node as swaped child node
        parent_node = large_child;
    }
}

void insertion_sort(float arr[], int len) // Uses a variable to store extra item so that a seris of overwrites can be achieved
{
    // Parent loop to increment through entire array swapping neighbor elements if unsorted
    for (int i = 0; i < len - 1; i++)
    {
        float key = arr[i];
        int j = i - 1;

        // Child loop iterates through sorted items until most recently added item is in its' sequential place
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubble_sort(float arr[], int len)
{
    // Parent while loop that tests whether or not child loop completed without any swaps and also decrementing the end number
    _Bool swapped;
    for (int i = len; i > 0; i--)
    {
        swapped = 0;
        // Child for loop that iterates over entire sub-array sorting each pair of consecutive elements
        for (int j = 0; j < i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0)
        {
            break;
        }
    }
}

void selection_sort(float arr[], int len)
{
    // Three variables:
    // 1. Counter for parent loop (main array)
    // 2. Counter for child loop (sub-array)
    // 3. min_value of sub-array

    for (int i = 0; i < len - 1; i++)
    {
        int min_value = i;                // Define minimum value (3) of sub-array as parent loop counter (1)
        for (int j = i + 1; j < len; j++) // Define child loop counter (2) as minimum value of sub-array
        {
            // Iterate through entire sub-array testing each element against currect minimum value
            if (arr[j] < arr[min_value])
            {
                min_value = j; // assigns min_value as position of min value
            }
        }
        if (min_value != i) // Executes swap except when array postion at "i" counter already contains min_value
        {
            swap(&arr[i], &arr[min_value]);
        }
    }
}

void swap(float *a, float *b)
{
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print_arr(float arr[], int len)
{
    for (int j = 0; j < len; j++)
    {
        printf("%f  ", arr[j]);
    }
}

// Extra:

/*
void quick_sort(float array[], int lower_bound, int upper_bound)
 {
     int left_counter = lower_bound;
     int right_counter = upper_bound;
     int pivot = array[(lower_bound + upper_bound / 2)];

    while (left_counter <= right_counter)
    {
        while (array[left_counter] < pivot)
        {
            left_counter++;
        }

        while (array[right_counter] > pivot)
        {
            right_counter--;
        }

        if (left_counter <= right_counter)
        {
            swap(&array[left_counter], &array[right_counter]);
            left_counter++;
            right_counter--;
        }
    }

    // condition to define base case for left split:
    if (lower_bound < right_counter)
    {
        // recursivly call quicksort on lower half of array
        quick_sort(array, lower_bound, right_counter);
    }

    // condition to define base case for right split:
    if (left_counter < upper_bound)
    {
        // recursivly call quicksort on upper half of array
        quick_sort(array, left_counter, upper_bound);
    }
}










*/