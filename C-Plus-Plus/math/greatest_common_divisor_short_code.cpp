#include<stdio.h>

int gcd(int x, int y){ return y?gcd(y,x%y):x; }

int main()
{
    int a, b;
    printf("Input two integers:");
    scanf("%d%d", &a, &b);
    printf("\n");
    printf("GCD(%d,%d) = %d\n", a, b, gcd(a,b));
}