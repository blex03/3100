#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i;

	printf("n = ");
	scanf("%d", &n);

	int m = n;
	double pi = 0.;
    double fraction = 1;
	//TODO
	//add code below 
    for (i = 0; i <= m; i++){
        pi += ((4 / ((8 * (double)i) + 1)) - (2 / ((8 * (double)i) + 4)) - (1 / ((8 * (double)i) + 5)) - (1 / ((8 * (double)i) + 6))) * (1 / fraction);
        fraction = fraction * 16;
    }

	printf("PI = %.10f\n", pi);
	return 0;
}