#include <iostream>
using namespace std;

long long int arr[100]={0};

int main(){

	// precompute fibo upto 10^5
	arr[0]	= 1;
	arr[1]	= 1;

	for(int i=2;i<100;i++)	arr[i]	= arr[i-1] + arr[i-2];

	cout<<arr[99]<<endl; // fibo number at 99 in O(1)

	return 0;
}