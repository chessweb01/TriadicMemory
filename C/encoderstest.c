#include <stdio.h>
#include <stdlib.h>

#include "triadicmemory.h"
#include "encoders.h"

int main(int argc, char* argv[]) 
{
	/*
		Test with n = 10000, p = 10, xmin = -10.0, xmax = 10.0
	*/

	SDR* sdr = sdr_new(10000);

	printf("Testing Real2SDR / SDR2Real\n\n");

	for (double x = -10.0; x <= 10.0; x += 0.01) {

		printf("value before encoding to sdr: %.2f\nsdr: ", x);
		
		Real2SDR(sdr, x, 10000, 10, -10.0, 10.0);

		sdr_print(sdr);

		double tmp = SDR2Real(sdr, 10000, 10, -10.0, 10.0);

		printf("value after decoding from sdr: %.2f (%f)\n\n", tmp, tmp);
	}

	printf("Testing Int2SDR / SDR2Int\n\n");

	for (int x = 0; x <= 267; x++) {

		printf("value before encoding to sdr: %i\nsdr: ", x);

		Int2SDR(sdr, x, 10000, 10, 0, 267);

		sdr_print(sdr);

		printf("value after decoding from sdr: %i\n\n", SDR2Int(sdr, 10000, 10, 0, 267));
	}

	sdr_delete(sdr);

	return 0;
}