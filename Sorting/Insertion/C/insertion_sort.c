#include <stdio.h>
#include <time.h>

// A sequence of n numbers <a_1, a_2, ... , a_n>
// Output A permutation (reordering) <a'_1, a'_2, ... , a'_n> such that a'_1 <= a'_2 <= ... <= a'_n.
void insertionSort(int arr[], int n){
    int i, key, j;
    // start at the second element and work through the list
    for (i=1; i < n; i++){
        key = arr[i];
        j = i - 1;
        
        /* Move elements of arr[0..i-1] (items to the left of the key), 
         * that are greater than the key, to one position ahead of their 
         * current position */
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        /* insert the key into its left sorted place or leave it be if
         * it is larger than (or equal to) all of its left neighbours */
        arr[j + 1] = key;
    }
}

// Function to print an array
void printArray(int arr[], int n){
    int i;
    for (i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Test
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Initial array: ");
    printArray(arr, n);
    
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    insertionSort(arr, n);
    end = clock();

    printf("Sorted array: ");
    printArray(arr, n);
    
    // CLOCKS_PER_SEC is a macro from <time.h>
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The algorithm took %f seconds to execute\n", cpu_time_used);

    return 0;
}
