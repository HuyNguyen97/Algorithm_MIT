#include <iostream>
#include <vector>

using namespace std;

int heap_left_child(int i) {
	return (2 * i + 1);
}

int heap_right_child(int i) {
	return (2 * i + 2);
}

int heap_parent(int i) {
	return (i - 1) / 2;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void reHeapUp(vector<int>& arr, int pos) {
	int parent = heap_parent(pos);
	if (pos > 0 && arr[parent] < arr[pos]) {
		swap(arr[parent], arr[pos]);
		reHeapUp(arr, parent);
	}
}

void reHeapDown(vector<int>& arr, int pos) {
	int right_child = heap_right_child(pos);
	int left_child = heap_left_child(pos);
	int last_pos=arr.size();
	int large_child;
	if(pos<=last_pos){
		if(left_child<=last_pos && arr[left_child]<arr[right_child]){
			large_child=right_child;
		}
		else{
			large_child=left_child;
		}
		if(arr[pos]<arr[large_child]){
			swap(arr[pos],arr[large_child]);
			reHeapDown(arr, large_child);
		}
	}
}

void build_heap(vector<int>& arr, int walker){
	walker=1;
	while(walker<arr.size()){
		reHeapUp(arr,walker);
		walker++;
	}
}

int main() {
	vector<int> arr(15);
	int number_node;
	cin >> number_node;
	for (int i = 0; i < number_node; i++) {
		cin >> arr[i];
	}
	int walker=1;
	//cout<<arr[arr.size()]<<endl;
	build_heap(arr,walker);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	return 0;
}


