#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
int main(int argc, char* argv[]) {
		if (argc < 3){
				printf("Usage: %s <array_size> <print_arrays>\n", argv[0]);
        printf("       <print_arrays> - 0 for no, 1 for yes\n");
				return 1;
		}

		int n = atoi(argv[1]); // Convert argument to integer
    int print_arrays = atoi(argv[2]); // Convert print flag to integer

		if (n <= 0) {
			 printf("Please enter a positive integer for the array size.\n");
			 return 1;
		}

		// Seed the random number generator
		srand(time(NULL));

		// Dynamically allocate memory for the array
		int* arr = malloc(n * sizeof(int));
		if(arr == NULL){
			perror("Memory allocation failed");
			return 1;
		}

		// Fill the array with random numbers
		for (int i = 0; i<n; i++){
			arr[i] = rand() % 1000;
		}

		if (print_arrays) {
        printf("Initial array: ");
        printArray(arr, n);
    }
		
		clock_t start, end;
		double cpu_time_used;

		start = clock();
		insertionSort(arr, n);
		end = clock();

		if (print_arrays) {
        printf("Sorted array: ");
        printArray(arr, n);
    }
		
		// CLOCKS_PER_SEC is a macro from <time.h>
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("The algorithm took %f seconds to execute\n", cpu_time_used);

		// Clean up
		free(arr);
		return 0;
}
