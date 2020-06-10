#include <iostream>
#include <queue>

using namespace std;

int arr[100][100];
int visited[100][100];
int N, M;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void bfs(int x, int y)
{
	queue < pair<int, int> > q;
	q.push(make_pair(x, y));
	int nx, ny;
	visited[x][y] = 1;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;

		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				if (visited[nx][ny] == 0 && arr[nx][ny] == 1)
				{
					q.push(make_pair(nx, ny));
					visited[nx][ny] = visited[x][y] + 1;
				}
			}
		}
		q.pop();
		
	}
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &arr[i][j]);

	bfs(0, 0);

	cout << visited[N - 1][M - 1];
	return 0;
}
