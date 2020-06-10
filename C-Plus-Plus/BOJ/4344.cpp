#include<iostream>
#include<math.h>

using namespace std;

int main() {
	int stdNum;
	int sum;
	int stdCnt;
	double average;
	double stdRatio;
	while (1) {
		sum = 0;
		stdCnt = 0;
		cin >> stdNum;
		if (stdNum == 0) {
			break;
		}
		int *score = new int[stdNum];
		if (!score) {
			return 0;
		}
		for (int i = 0; i < stdNum; i++) {
			cin >> score[i];
			sum += score[i];
		}
		average = (double)sum / stdNum;
		for (int i = 0; i < stdNum; i++) {
			if (average < score[i])
				stdCnt++;
		}
		stdRatio = ((double)stdCnt / stdNum) * 100;
		cout.precision(3);
		cout << fixed << stdRatio << "%" << endl;
	}
	return 0;
}

