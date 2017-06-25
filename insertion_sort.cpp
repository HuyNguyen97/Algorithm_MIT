#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void insertion_sort(vector<int>& arr) {
	for (int i = 1; i < arr.size(); i++) {
		int walker=i;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[walker] < arr[j]) {
				swap(arr[walker], arr[j]);
				walker=j;
			}
		}
	}
}

int main() {
	vector<int> arr(10);
	for(int i=0;i<10;i++){
		cin>>arr[i];
	}
	insertion_sort(arr);
	for(int i=0;i<10;i++){
		cout<< arr[i]<<" ";
	}
	return 0;
}
