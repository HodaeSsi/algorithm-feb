#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

string board[10001];
bool visited[10001][501];

int r, c;
bool dfs(int i, int j) {
	if (board[i][j] == 'x' || visited[i][j]) {
		return false;
	}
	visited[i][j] = true;
	if (j == c - 1)return true;
	for (int k = -1; k <= 1; k++) {
		int ni = i + k, nj = j + 1;
		if (ni >= 0 && ni < r && dfs(ni, nj))return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c;
	
	for (int i = 0; i < r; i++) {
		cin >> board[i];
	}

	int cnt = 0;

	for (int i = 0; i < r; i++) {
		if (dfs(i, 0))cnt++;
	}
	cout << cnt;
}
