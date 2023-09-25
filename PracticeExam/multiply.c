#include <stdio.h>
int multiply(int a, int b){
    int res = 0;
    while (b > 0){
        if (b % 2 == 1){
            res += a;
        }

        a = a << 1;
        b = b >> 1;
    }
    return res; 

}

int main(){
    printf("%d\n", multiply(2, 3));
} 