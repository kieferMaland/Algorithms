import subprocess
import sys
import random
import matplotlib.pyplot as plt
import time
import numpy as np

def run_insertion_sort(executable, n, language="c"):
	command = []
	if language == "c":
		# Run the C program
		command = [f'../C/{executable}', str(n), '0']
	elif language == "python":
		# Run the Python script
		python_script_path = f'../Python/{executable}'
		command = [sys.executable, python_script_path, str(n)]
	elif language == "rust":
		# Run the Rust executable
		rust_executable_path = f'../Rust/insertion_sort_rust/target/release/{executable}'
		command = [rust_executable_path, str(n), '0']

	result = subprocess.run(command, capture_output=True, text=True)

	if result.returncode != 0:
		print(f'Error running {executable}: {result.stderr}')
		return None

	try:
		# Extract the execution time from the output
		return float(result.stdout.strip())
	except ValueError as e:
		print(f'Error parsing output from {executable}: {e}')
		return None

def plot_results(sizes, c_times, py_times, rust_times):
	plt.plot(sizes, c_times, label='C')
	plt.plot(sizes, py_times, label='Python')
	plt.plot(sizes, rust_times, label="Rust")
	# Assume benchmarking has determined that one operation takes 'avg_op_time' seconds
	avg_op_time = 0.0000001  # This is an example value, adjust it based on your benchmarks

	# Calculate the scaled worst-case scenario
	scaled_worst_case = [0.5 * x * (x - 1) * avg_op_time for x in sizes]
	plt.plot(sizes, scaled_worst_case, label='Theoretical Worst-Case (n^2)', linestyle='--')

	plt.xlabel('Array Size (n)')
	plt.ylabel('Execution Time (seconds)')
	plt.ylim(bottom=0, top=max(max(c_times), max(py_times)) * 1.1)  # Give a bit of space above the max

	plt.legend()
	plt.savefig('insertion_sort_comparison.png', dpi=300)

def main():
	sizes = np.linspace(10, 10000, num=100, dtype=int)
	c_times = []
	py_times = []
	rust_times = []

	for n in sizes:
		c_time = run_insertion_sort('out', n, language="c")
		py_time = run_insertion_sort('insertionSort.py', n, language="python")
		rust_time = run_insertion_sort('insertion_sort_rust', n, language="rust")

		c_times.append(c_time)
		py_times.append(py_time)
		rust_times.append(rust_time)

	plot_results(sizes, c_times, py_times, rust_times)

if __name__ == '__main__':
	main()
