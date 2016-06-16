#include <iostream>
using namespace std;

// Recursive solution
int binary_search(int arr[],int l,int r,int x){
	if(r >= l){
		int mid = l + (r-l) / 2;

		if(arr[mid]==x) return mid;
		if(arr[mid]>x) return binary_search(arr,l,mid-1,x);

		return binary_search(arr,mid+1,r,x);
	}

	return -1;
}

// Iterative solution
int binary_search_iter(int arr[],int l,int r,int x){
	while(r>=l){
		int mid = l + (r-l) / 2;

		if(arr[mid]==x) return mid;
		if(arr[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}

int main(){
	
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	int n = sizeof(arr) / sizeof(arr[0]);

	int x = 10;

	int ans_recur = binary_search(arr, 0, n-1, x);
	int ans_iter  = binary_search_iter(arr,0,n-1,x);

	cout<<ans_recur<<endl;
	cout<<ans_iter<<endl;
	return 0;
}
