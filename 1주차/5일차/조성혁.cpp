#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2e9

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		vector<int> v(n + 1);
		vector<int> cumsum(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> v[i];

			cumsum[i] = cumsum[i - 1] + v[i];
		}

		vector<vector<int>> dp(n + 2, vector<int>(n + 2));

		// dp[i][j] = sum[i..j] - min(dp[i+1][j], dp[i][j-1]), i, j 가 카드 범위일 때 현재 사람이 얻을 수 있는 점수의 최댓값
		for (int gap = 0; gap <= n; gap++) {
			for (int i = 1; i <= n; i++) {
				if (i + gap <= n) {
					dp[i][i + gap] = cumsum[i + gap] - cumsum[i - 1] - min(dp[i + 1][i + gap], dp[i][i + gap - 1]);
				}
			}
		}

		cout << dp[1][n] << "\n";
	}
}
