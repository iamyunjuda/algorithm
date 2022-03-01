#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 16
using namespace std;

int dx[] = { 1,1,0 }; //가로 , 대각, 세로
int dy[] = { 0,1,1 };
int map[MAX][MAX];
bool chk[MAX][MAX];
queue<pair<pair<int,int>,int>> q;
int cnt = 0;
int N;
bool possible(int x, int y, int state) {
	switch (state) {
	case 0:
		//가로일때
		if (chk[x][y] == true) {
			return false;
		}
		else {
			return true;
		}
		break;

	case 1:
		//대각선
		if (!chk[x][y] && !chk[x][y - 1] && !chk[x - 1][y]) {
			return true;

		}
		else return false;
		break;

	case 2:
		//세로
		if (chk[x][y]) return false;
		else return true;
		break;
	}

}


void DFS(int x, int y, int state) {
	
	q.push({ { x, y },state });

	while (!q.empty()) {
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int cstate = q.front().second;
		q.pop();
		if (cstate == 0) {
		//가로일때
			for (int i = 0; i < 2; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				int nstate = i;
				
				if (nx >= N || nx < 0 || ny >= N || ny < 0) continue;
				

				bool isPossible = possible(nx, ny, nstate);
				if (nx == N - 1 && ny == N - 1 && isPossible) {
					cnt++;
					continue;
				}
				if(!isPossible) continue;
				q.push({ {nx, ny}, nstate });

				
			}
		
		}
		else if (cstate == 1) {
		//대각선일때
					//가로일때
			for (int i = 0; i < 3; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				int nstate = i;

				if (nx >= N || nx < 0 || ny >= N || ny < 0) continue;


				bool isPossible = possible(nx, ny, nstate);
				if (nx == N - 1 && ny == N - 1 && isPossible) {
					cnt++;
					continue;
				}
				if (!isPossible) continue;
				q.push({ {nx, ny}, nstate });


			}
		
		
		
		}
		else
		{
			//세로일때
			for (int i = 1; i < 3; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				int nstate = i;

				if (nx >= N || nx < 0 || ny >= N || ny < 0) continue;


				bool isPossible = possible(nx, ny, nstate);
				if (nx == N - 1 && ny == N - 1 && isPossible) {
					cnt++;
					continue;
				}
				if (!isPossible) continue;
				q.push({ {nx, ny}, nstate });


			}
		
		
		}

		
	
	
	}

	



}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int k;
			cin >> k;
			map[j][i] = k;
			if (k == 1) chk[j][i] = true;

		}
	
	}


	DFS(1, 0,0);
	cout << cnt;


}