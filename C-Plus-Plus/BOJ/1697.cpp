#include <iostream>
#include <queue>

#define MAX 1000000

using namespace std;
bool visit[1000001];

int N, K;
bool check;
int cnt;
int main(void)
{
	cin >> N >> K; 
	queue <int> q;
	q.push(N);
	int x;
	int result = 0;
	int seg = 1; 
	while (!q.empty())
	{
		for (int i = 0; i < seg; i++)
		{
			x = q.front();
			visit[x]=true;
			q.pop(); 

			if (x == K)
			{
				cout << result;
				return 0;
			}

			if (x - 1 >=0 && x-1<=MAX && !visit[x - 1])
			{
				cnt++;
				check = true;
				q.push(x - 1);
			}

			if (x + 1 <= MAX && !visit[x + 1])
			{
				cnt++;
				check = true;
				q.push(x + 1);
			}

			if (2 * x <= MAX && !visit[2 * x])
			{
				cnt++;
				check = true;
				q.push(2 * x);
			}

		}
		seg = cnt;
		cnt = 0;
		if (check)
			result++;
		check = false;

	}

	cout << result;
	return 0;

}
