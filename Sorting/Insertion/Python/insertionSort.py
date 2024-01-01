import time
import sys
import random

def insertion_sort(arr):
	
	for i in range(1, len(arr)):
		key = arr[i]
		j = i - 1
		
		while j>=0 and key < arr[j]:
			arr[j+1] = arr[j]
			j -= 1
		
		arr[j+1] = key

def generate_random_array(n):
    return [random.randint(0, 1000) for _ in range(n)]

def print_array(arr):
	print(" ".join(map(str, arr)))

# Test
if __name__ == '__main__':
	n = int(sys.argv[1]) if len(sys.argv) > 1 else 5
	arr = generate_random_array(n)
	# print(f'initial Array: {arr}')

	start_time = time.time()
	insertion_sort(arr)
	end_time = time.time()

	# print(f'Sorted Array: {arr}')

	print(f'{end_time - start_time:.10f}')