#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void quicksort(vector<int>& arr, int l, int r) {
	if(l>=r) return;
	int pivot = l; //choose first element as pivot
	int left = l;
	int right = r;
	while (left < right) {
		while (arr[left] <= arr[pivot] && left < right) { left++;} 
		while (arr[right] > arr[pivot]) { right--;}
		if (left < right) {
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}
	if(arr[pivot] > arr[right]){
		swap(arr[l],arr[right]);
	}     
	quicksort(arr, l, right - 1);
	quicksort(arr, right + 1,r);
}
int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//insertion_sort(arr);
	quicksort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
