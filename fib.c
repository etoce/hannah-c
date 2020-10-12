#include <time.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int fibRecursive(unsigned int n) {
	if (n == 1 || n == 0) {
		return 1;
	} else {
		return fibRecursive(n - 1) + fibRecursive(n - 2);
	}
}

unsigned int fibMemo(unsigned int n, unsigned int *nums) {
	if (n == 1 || n == 0) {
		nums[n] = 1;
	} else {
		nums[n] = nums[n - 1] + nums[n - 2];
	}
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: fib <number>\n");
		exit(0);
	}
	unsigned int n = atoi(argv[1]);
	unsigned int *nums = malloc(n * sizeof(unsigned int));

	clock_t start = clock();
	for (int i = 0; i < n; i++) {
		nums[i] = fibRecursive(i);
		//fibMemo(i, nums);
	}
	clock_t end = clock();

	for (int i = 0; i < n; i++) {
		printf("%d\n", nums[i]);
	}
	printf("Computation of the first %u Fibonacci numbers completed in %d milliseconds.\n", n, (int)(end - start));
	
	free(nums);
}