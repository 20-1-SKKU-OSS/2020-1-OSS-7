#include <iostream>
using namespace std;

int factorial (int n){
	if(n == 0){
		int ans = 0;
		return ans;
	}
	else{
		return n * factorial(n-1);
	}
}

int main(){
	int num, res;
	cout << "Enter number = ";
	cin >> num;
	cout << "Factorial of number is = " << factorial(num);
	return 0;
}
	
