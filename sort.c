#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

unsigned int* bubblesort(unsigned int *arr, int start, int end) {
	for (int i = end; i >= start; i--) {
		for (int j = 0; j < i - 1; j++) {
			if (arr[j] > arr[j+1]) {
				unsigned int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	return arr;
}

unsigned int* quicksort(unsigned int *arr, int start, int end) {
	//printf("quicksort(%u, %u)\n", start, end);
	if (end - start <= 1) {
		return arr;
	}
	int pivot = arr[start];
	int left = start;
	int right = end;
	while (left < right) {
		do {} while (arr[--right] >= pivot && right >= 0);
		do {} while (arr[++left] < pivot);
		if (left < right) {
			//printf("swapping %u with %u, left=%u, right=%u\n", arr[left], arr[right], left, right);
			unsigned int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}
	int pivotSpot = start;
	do {} while (arr[++pivotSpot] < pivot && pivotSpot < end);
	pivotSpot--;
	//printf("~swapping %u with %u, start=%u, pivotSpot=%u\n", arr[start], arr[pivotSpot], start, pivotSpot);
	arr[start] = arr[pivotSpot];
	arr[pivotSpot] = pivot;
	quicksort(arr, start, pivotSpot);
	quicksort(arr, pivotSpot + 1, end);
	return arr;
}

unsigned int* randomArray(unsigned int *output, unsigned int numElements) {
	for (int i = 0; i < numElements; i++) {
		output[i] = rand();
	}
	return output;
}

int isSorted(unsigned int *arr, unsigned int numElements) {
	unsigned int last = arr[0];
	for (int i = 1; i < numElements; i++) {
		if (last > arr[i]) {
			return 0;
		}
		last = arr[i];
	}
	return 1;
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("Usage: a <array-size> <bubble|quick>\n");
		exit(0);
	}
	char *sortingType = argv[2];
	unsigned int arraySize = atoi(argv[1]);
	unsigned int *nums = malloc(arraySize * sizeof(unsigned int));
	randomArray(nums, arraySize);

	clock_t start = clock();
	if (!strcmp("bubble", sortingType)) {
		bubblesort(nums, 0, arraySize);
	} else if (!strcmp("quick", sortingType)) {
		quicksort(nums, 0, arraySize);
	} else {
		printf("Invalid sorting method.\n");
		exit(0);
	}
	clock_t end = clock();

	if (isSorted(nums, arraySize)) {
		printf("Sorting of %u elements completed in %u milliseconds.\n", arraySize, (unsigned int)(end - start));
	} else {
		printf("Sorting failed?! :(\n");
	}
	
	free(nums);
}