#include <iostream>
using namespace std;

int factorial (int n){
	if(n == 0){
		int ans = 1;
		return ans;
	}
	else{
		return n * factorial(n-1);
	}
}

int main(){
	int num;
	cout << "Enter number = ";
	cin >> num;
	cout << "Factorial of number is = " << factorial(num);
	return 0;
}
	
