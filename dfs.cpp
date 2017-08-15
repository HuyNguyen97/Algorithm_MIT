#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define UNVISITED 0
#define VISITED 1
#define TRUE 1
#define FALSE 0

long long N = 100000;
using namespace std;

int n, m;

bool compare(int a, int b){
	if(a>b) return true;
}

void dfs(vector<vector<int> > &G, int root) {
	bool visited[100];
	for (int i = 0; i < 100; i++) {
		visited[i] = false;
	}
	stack<int> st;
	st.push(root);
	int u;
	while (!st.empty()) {
		u = st.top();
		st.pop();
		if (visited[u] == false) {
			cout << "Visiting " << u << endl;;
			visited[u] = true;
		}
		for (int i = 0; i < G[u].size(); i++) {
			if (visited[G[u][i]] == false) {
				int next = G[u][i];
				st.push(next);
			}
		}
	}
}

void bfs(vector<vector<int> > &G, int root){
		
}
int main() {
	int s;
	int e;
	int number_vertex;
	int number_edge;
	cin>>num
	vector<vector<int> > G(18, vector<int>());
	for (int i = 0; i <25; i++) {
		cin >> s;
		cin >> e;
		G[s].push_back(e);
		G[e].push_back(s);
	}

	for (int i = 0; i < G.size(); i++) {
		sort(G[i].begin(), G[i].end(), compare);
	}
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < G[i].size(); j++) {
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
	
	dfs(G, 0);

	return 0;
}

