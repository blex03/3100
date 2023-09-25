#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n;

	printf("n = ");
	scanf("%d", &n);

	int m = n;

	//TODO
	//add code below
    

    while (n != 4 && n != 1){
        int sum = 0;
        while (n > 0){
            sum += (n % 10) * (n % 10);
            n = floor(n / 10);
        }
        n = sum;
        printf("%d\n", n);
    }

	if (n == 1){
        printf("%d is a happy number.\n", m);

    }   else {
        printf("%d is NOT a happy number.\n", m);
    }

	return 0;
}