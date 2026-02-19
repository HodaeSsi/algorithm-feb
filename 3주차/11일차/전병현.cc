//question : https://icpc.me/26093
#include <queue>
#include <algorithm>
#include <iostream>
#define INT_MAX 2147483647
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> llll;
typedef pair<int, int> ii;

int rate[100][10000];
priority_queue<pair<int, int>>pq[10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cin >> rate[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		pq[0].push({ rate[0][i], i });
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < k; j++) {
			// 다른경우
			auto top = pq[i - 1].top();
			if (top.second != j) {
				pq[i].push({ top.first + rate[i][j], j });
			}
			else {
				//같은경우
				pq[i - 1].pop();
				pq[i].push({ pq[i - 1].top().first + rate[i][j], j });
				pq[i - 1].push(top);
			}
		}
	}
	cout << pq[n - 1].top().first;
}
