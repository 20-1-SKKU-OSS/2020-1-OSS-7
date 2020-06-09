#include <iostream>
#include <algorithm>
using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int main() {
	int len, ans, temp;
	ans = 0;
	cin >> len;
	int *arr_a, *arr_b;
	arr_a = new int[len];
	arr_b = new int[len];
	for (int i = 0; i < len; i++) {
		cin >> arr_a[i];
	}
	sort(arr_a, arr_a + len); // arr_a 오름차순 정렬
	for (int i = 0; i < len; i++) {
		cin >> arr_b[i];
	}
	sort(arr_b, arr_b + len, desc); // arr_b 내림차순 정렬
	for (int i = 0; i < len; i++) {
		temp = arr_a[i] * arr_b[i];
		ans += temp;
	}
	cout << ans;
}
