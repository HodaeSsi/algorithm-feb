#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int m, n, k;

vector<vector<int>> e;

int group[100001];

int bfs(int n, int gid) {
	queue<int> q;
	q.push(n);
	int cnt = 0;
	while (q.size()) {
		int nn = q.front();
		q.pop();
		if (group[nn]) {
			continue;
		}
		cnt++;
		group[nn] = gid;
		for (auto x : e[nn]) {
			if (group[x] == 0) {
				q.push(x);
			}
		}
	}
	return cnt;
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		e.push_back(vector<int>());
	}
	int x, y;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (i == k - 1) {
			x = a - 1;
			y = b - 1;
		}
		else {
			e[a - 1].push_back(b - 1);
			e[b - 1].push_back(a - 1);
		}
	}
	long long int xc, yc;
	xc = bfs(x, 1);
	yc = bfs(y, 2);

	cout << xc*yc;
}