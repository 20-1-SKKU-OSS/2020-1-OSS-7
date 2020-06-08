#include <iostream>
#include <algorithm>
using namespace std;

int N;
int a[11]; //
int b[4]; //연산 받을 배열
int MAX = -1000000000;
int MIN = 1000000000;


void dfs(int index, int add, int sub, int multi, int divide, int total)
{

	if (index == N)
	{
		MAX = max(MAX, total);
		MIN = min(MIN, total);
	}
	if (add < b[0])
		dfs(index + 1, add + 1, sub, multi, divide, total + a[index]);
	if (sub < b[1])
		dfs(index + 1, add, sub + 1, multi, divide, total - a[index]);
	if (multi < b[2])
		dfs(index + 1, add, sub, multi + 1, divide, total * a[index]);
	if (divide < b[3])
		dfs(index + 1, add, sub, multi, divide + 1, total / a[index]);
}
int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i < 4; i++)
		cin >> b[i];

	dfs(1, 0, 0, 0, 0, a[0]);

	cout << MAX << endl;
	cout<< MIN << endl;
	return 0;
}
