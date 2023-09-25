#include <stdio.h>
#include <stdlib.h>

int oddSumHelp(int count, int bound, int value)
{
	//fill in your code below
	if (count == 0){
		if (value == 0) {
			return 1;
			
		} else {
			return 0;
		}
	}
	else if (value <= 0){
		return 0;
	}
	else if (bound <= 0){
		return 0;
	}

	int sum = (bound / 2) + 1;

	if (sum * sum >= value && (count - 1) * (count - 1) <= (value - bound)){
		oddSumHelp(count - 1, bound - 2, value - bound);
		printf("%d ", bound);
	} else {
		oddSumHelp(count, bound - 2, value);
	}
}

double two_d_random(int n)
{

	//Fill in code below
	//When deciding which way to go for the next step, generate a random number as follows.
	//r = rand() % 4;
	//Treat r = 0, 1, 2, 3 as up, right, down and left respectively.

	//The random walk should stop once the x coordinate or y coordinate reaches $-n$ or $n$. 
	//The function should return the fraction of the visited $(x, y)$ coordinates inside (not including) the square.

	int x = 0;
	int y = 0;
	int r;
	int count = 0;

	int num_coordinates = (n + n - 1) * (n + n - 1);
	int used_squares[2 * n + 1][2 * n + 1];               /*{{0, 0, 0, 1, 0}
											   				 {0, 0, 1, 1, 0}
											   				 {0, 0, 1, 1, 0}
															 {0, 0, 0, 1, 0}
															 {0, 0, 0, 0, 0}}*/

	for (int i = 0; i < 2 * n + 1; i++){
			for (int j = 0; j < 2 * n + 1; j++){
				used_squares[i][j] = 0;
			}
		}

	used_squares[n][n] = 1;

	while (abs(x) != n && abs(y) != n) {
		r = rand() % 4;
		switch (r) {
			case 0:
				y++; break;
			case 1:
				x++; break;
			case 2:
				y--; break;
			case 3:
				x--; break;
		}

	

		if (used_squares[y + n][x + n] == 0){
			used_squares[y + n][x + n] += 1;
			printf("(%d, %d): used_squares[%d][%d] = 1 \n", x, y, y + n, x + n);
			count++;
		}
	}
	
	double fraction = (double)(count) / num_coordinates;
	return fraction;	
}

int main() {
    //printf("%d", oddSumHelp(12, 29, 200));
	printf("%f", two_d_random(1));
    return 0;
}

/*1, 3, 5, 7, 9
16 in 4

if 5 (9) squared is greater than 16  and there are three numbers < 9 that add up to 16 - 9

0
0
1, 3, 5, 7, 9, 11, 13, 15, 17, 23, 47, 49*/
