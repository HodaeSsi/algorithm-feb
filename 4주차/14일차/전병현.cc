#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

int n;
int board[21];
int temp[21];

inline int countline(int x) {
	int cnt = 0;
	while (x) {
		cnt += (x & 1);
		x >>= 1;
	}
	return cnt;
}

int sol(int flip) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int x = countline(board[i] ^ flip);
		cnt += min(x, n - x);
	}
	return cnt;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < n; j++) {
			board[i] <<= 1;
			board[i] |= (a[j] == 'T');
		}
	}
	int mini = 2147483647;
	for (int i = 0; i < (1 << n); i++) {
		mini = min(mini, sol(i));
	}
	cout << mini;
}
