#include <iostream>
using namespace std;

int factorial (int n){
	return (n==0) ? 1 : n*factorial(n-1);
}

int main(){
	int num;
	cout << "Enter number = ";
	cin >> num;
	cout << "Factorial of number is = " << factorial(num);
	return 0;
}
	
