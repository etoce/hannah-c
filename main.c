#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int gcf(unsigned int x, unsigned int y) {
	while (x ^ y) {
		if (x > y) {
			x = x - y;
		} else {
			y = y - x;
		}
	}
	return x;
}

unsigned int collatz(unsigned int x) {
	unsigned int steps = 0;
	unsigned int n = x;
	while (n > 1) {
		if (n % 2 == 1) {
			n = 3 * n + 1;
		} else {
			n = n / 2;
		}
		steps++;
	}
	return steps;
}

unsigned int isPrime(unsigned int n, unsigned int *knownPrimes, unsigned int numKnownPrimes) {
	for (int i = 0; knownPrimes[i] * knownPrimes[i] <= n && i < numKnownPrimes; i++) {
		if (n % knownPrimes[i] == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	clock_t start = clock();
	unsigned int numberOfPrimesToFind = 2000000;
	unsigned int *primes = malloc(numberOfPrimesToFind * sizeof(unsigned int));
	unsigned int n = 2;
	unsigned int primesFound = 0;
	while (primesFound < numberOfPrimesToFind) {
		if (isPrime(n, primes, primesFound)) {
			primes[primesFound] = n;
			primesFound++;
			//printf("%u ", n);
		}
		n++;
	}
	//printf("\n");
	clock_t end = clock();
	
	printf("Found %u primes. Biggest one was %u.\n", primesFound, primes[numberOfPrimesToFind - 1]);
	printf("This took %d milliseconds.\n", (int)(end - start));

	free(primes);
}