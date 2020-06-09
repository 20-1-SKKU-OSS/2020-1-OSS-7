#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M; //가로, 세로
int arr[8][8];
int arr2[8][8];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int result;
void bfs(void)
{
	int arr3[8][8];
	int number=0;
	queue <pair <int, int > > q;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			arr3[i][j] = arr2[i][j]; 
			if (arr3[i][j] == 2)
				q.push(make_pair(i, j)); 
		}
	while (!q.empty())
	{
		int ny, nx,x,y;
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			ny = y + dy[i];
			nx = x + dx[i];

			if (nx >= 0 && ny >=0 && nx<M && ny<N)
				if (arr3[ny][nx] == 0) {
					arr3[ny][nx] = 2; 
					q.push(make_pair(ny, nx)); 
				}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (arr3[i][j] == 0)
				number++;

	result = max(number, result);



}
void makewall(int cnt)
{
	if (cnt == 3)
	{
		bfs();
		return;
	}		
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if (arr2[i][j] == 0)
			{
				arr2[i][j] = 1; 
				makewall(cnt + 1);
				arr2[i][j] = 0;

			}

}


int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	for (int i = 0; i<N; i++)
		for (int j = 0; j<M; j++)
			if (arr[i][j] == 0) 
			{
				for (int m = 0; m < N; m++)
					for (int n = 0; n < M; n++)
						arr2[m][n] = arr[m][n];
				arr2[i][j] = 1;
				makewall(1);
				arr2[i][j] = 0; 
			}

	cout << result;
	return 0; 
}
