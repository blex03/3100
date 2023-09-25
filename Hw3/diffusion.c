#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//TODO
//Implement the below function
//Simulate one particle moving n steps in random directions
//Use a random number generator to decide which way to go at every step
//When the particle stops at a final location, use the memory pointed to by grid to 
//record the number of particles that stop at this final location
//Feel free to declare, implement and use other functions when needed

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

	grid[((n + x) * (2 * n + 1) * (2 * n + 1)) + ((n + y) * (2 * n + 1)) + n + z]++; 

}

//TODO
//Implement the following function
//This function returns the fraction of particles that lie within the distance
//r*n from the origin (including particles exactly r*n away)
//The distance used here is Euclidean distance
//Note: you will not have access to math.h when submitting on Mimir
double density(int *grid, int n, double r, int m)
{
	int count = 0;

	for (int i = 0; i < (2 * n + 1) * (2 * n + 1) * (2 * n + 1); i++){
		int x = (i / ((2 * n + 1) * (2 * n + 1))) - n;
		int y = ((i - ((2 * n + 1) * (2 * n + 1) * (n + x))) / (2 * n + 1)) - n;
		int z = (i - ((2 * n + 1) * (2 * n + 1) * (n + x)) - ((2 * n + 1) * (y + n))) - n;

		int num = grid[i];
		double distance = x * x + y * y + z * z;

		double sqrt_dis = distance / 2;
		double root = 0;

		while(sqrt_dis != root){
			root = sqrt_dis;
			sqrt_dis = ((distance / root) + root) / 2;

		}


		if (sqrt_dis <= r * n){
			count += num;
		}
	}

	return (double)(count) / m;
}

//use this function to print results
void print_result(int *grid, int n, int m)
{
    printf("radius density\n");
    for(int k = 1; k <= 20; k++)
    {
        printf("%.2lf   %lf\n", 0.05*k, density(grid, n, 0.05*k, m));
    }
}

//TODO
//Finish the following function
//See the assignment decription on Piazza for more details
void diffusion(int n, int m)
{
	//fill in a few line of code below
	int *grid = calloc((2 * n + 1) * (2 * n + 1) * (2 * n + 1), sizeof(int));

	for(int i = 1; i<=m; i++) one_particle(grid, n);

	print_result(grid, n, m);
	//fill in some code below

	free(grid);


}

int main(int argc, char *argv[])
{
	
	if(argc != 3)
	{
		printf("Usage: %s n m\n", argv[0]);
		return 0; 
	}
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	assert(n >= 1 && n <=50);
	assert(m >= 1 && m <= 1000000);
	srand(12345);
	diffusion(n, m);
	return 0;
}