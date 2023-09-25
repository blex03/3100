#include <stdio.h>
int main()
{
	int i, j, n;

	//We assume the smallest such n is no more than 1000000
	for(n=1; n<=1000000; n++)
	{
		//Use count to record the number of different ways of summing two positive cube numbers to n
		int count = 0;
		//TO DO
		//Fill in code below
	}
    n = 1729;

	//Do not change code below
    printf("%d is the solution:\n", n);
	for(i=1; i<=100; i++)
		for(j = i; j<= 100; j++)
			{
				if (i*i*i + j*j*j == n)
				{
					printf("%d * %d * %d + %d * %d * %d = %d\n", i, i, i, j, j, j, n);
                }
			}

	return 0;
	//Do not try to hard code the solution, that is not the way to learn.
}