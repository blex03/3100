#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
//account for negative numbers
void one_particle(int *grid, int n)
{
	int x = 0;
	int y = 0;
	int z = 0;
	int r;

	for (int i = 0; i < n; i++){
		r = rand() % 6;

		switch (r) {
			case 0:
				x--; break;
			case 1:
				x++; break;
			case 2:
				y++; break;
			case 3:
				y--; break;
			case 4:
				z++; break;
			case 5:
				z--; break;
		}
	}

	grid[(x * (1 + n) * (1 + n) + 1) + (y * (1 + n)) + z]++; 

}

int main()
{
	//fill in a few line of code below
	int *grid = calloc(10 * 10 * 10, sizeof(int));

	for(int i = 1; i<=1000000; i++) one_particle(grid, 10);

	//fill in some code below

	free(grid);

    return 0;
}