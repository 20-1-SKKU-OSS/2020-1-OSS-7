#include<stdio.h>

const int N = 16;
int answer = 0;
int mask;

void NQueenSol(int row, int chk1, int chk2, int chk3)
{
    if(row > N){
        ++answer;
        return;
    }
    int chk = ~(chk1|chk2|chk3)&mask;
    while(chk){
        int next_pos = chk&~(chk-2);
        NQueenSol(row+1, chk1+next_pos, (chk2+next_pos)<<1, (chk3+next_pos)>>1);
        chk &= ~next_pos;
    }
    return;
}

int main()
{
    int l, x;
    l = 1<<(N>>1); // 2^[N/2]
    mask = (1<<N+1)-2;
    for(x=1; x<l; x<<=1) // Run backtracking for left half in first row
        NQueenSol(2, x<<1, x<<2, x);
    answer <<= 1; // answer *= 2
    if(N&1) // If N is odd, run one more time for center in first row
        NQueenSol(2, x<<1, x<<2, x);
    printf("The Number of Solution of %d-Queen: %d\n", N, answer);
}