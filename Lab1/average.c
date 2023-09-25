#include <stdio.h>

int main(){

    double x, total;
    int num;

    total = 0;
    num = 1;
    
    while (scanf("%lf", &x) == 1){
        total = total + x;
        double average = total / num;

        num++; 
        printf("Total=%f Average=%f\n", total, average);
    }
    return 0;
}