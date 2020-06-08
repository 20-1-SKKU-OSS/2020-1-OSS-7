#include <iostream>
using namespace std;

int main (){
	int num, j, h, cnt;
	cnt = 0;
	cin >> num >> j >> h;
	if ( j == h){
		cout << "-1";
		return 0;
	}
	while (1) {
		j = (j + 1) / 2;
		h = (h + 1) / 2;
		cnt++;
		if (j == h) {
			break;
		}
	}
	cout << cnt;
}
