#include <iostream>

#define INF 1e9

using namespace std;

int edges[501][501]; // edges[i][j]: i->j의 간선 존재
int dist[501][501];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edges[a][b] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else if (edges[i][j]) dist[i][j] = 1;
			else dist[i][j] = INF;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	// 특정 노드 x에 대하여 다른 노드들(y)과 dist[x][y] 또는 dist[y][x]가 존재하면 판별 가능
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		bool able = true;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;

			if (dist[i][j] == INF && dist[j][i] == INF) {
				able = false;
				break;
			}
		}

		if (able) {
			ans++;
		}
	}

	cout << ans;
}
