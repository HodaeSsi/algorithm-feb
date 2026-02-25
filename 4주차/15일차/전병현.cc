#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

int group[100001];
pair<pair<int, int>, int> xs[100001];

set<pair<pair<int, int>, int>> s;

void add(int idx, int x0, int x1) {
	group[idx] = idx;
	xs[idx] = { {x0, x1}, idx };
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int x0, x1, y;
		cin >> x0 >> x1 >> y;
		add(i, x0, x1);
	}
	sort(xs, xs + n);
	int maxx2 = -1;
	int maxidx = -1;
	for (int i = 0; i < n; i++) {
		if (xs[i].first.first > maxx2) {
			maxx2 = xs[i].first.second;
			group[xs[i].second] = ++maxidx;
		}
		else {
			maxx2 = max(maxx2, xs[i].first.second);
			group[xs[i].second] = maxidx;
		}
	}
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		cout << (group[a - 1] == group[b - 1]) << "\n";;
	}
}
