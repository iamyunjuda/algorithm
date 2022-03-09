//순열구현하기
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, s, e, m;
vector<int> rel[103];
queue<int> q;
int dist[103];
int cnt = 1;


int BFS(int st) {
	int tmp = st;
	q.push(st);


	while (!q.empty()) {
		
		int cur = q.front();
		
		q.pop(); 
	
		if (cur == e) {
			return dist[e];
		}

		for (int i = 0; i < rel[cur].size(); i++) {
			int nxt = rel[cur][i];
			if (!dist[nxt]) {
				q.push(nxt);
				dist[nxt] = dist[cur] + 1;
			
			}

		
		}
		
	
	}
	return -1;


}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> s >> e >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		rel[x].push_back(y);
		rel[y].push_back(x);

		
	}
	

	cout << BFS(s);


	return 0;



}