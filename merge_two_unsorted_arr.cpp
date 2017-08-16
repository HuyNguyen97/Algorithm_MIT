#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Merging two unsorted arrays in sorted order
using namespace std;
bool myfunction (int i,int j) { return (i>j); }
int main() {
	int n1, n2;
	cin>>n1>>n2;
	int count = 0;
	int input;
	vector<int> myvector1;
	vector<int> myvector2;
	while (count < n1 && cin >> input ) {
		myvector1.push_back(input);
		count++;
	}
	count =0;
	while (count < n2 && cin >> input ) {
		myvector2.push_back(input);
		myvector1.push_back(myvector2[count]);
		count++;
	}
	sort(myvector1.begin(),myvector1.end(), myfunction);
	for(int i=0; i<myvector1.size();i++){
		cout<<myvector1[i]<<" ";
	}
	return 0;
}
