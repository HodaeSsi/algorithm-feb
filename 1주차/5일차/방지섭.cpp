#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
int dp[1000][1000];
void input(){
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++) cin >> v[i];
    memset(dp, 0, sizeof(dp));
}

int card(int l, int r, int t){
    if(l > r) return 0;
    if(dp[l][r]) return dp[l][r];

    if(t % 2) return dp[l][r] = max(v[l] + card(l+1, r, t+1), v[r] + card(l, r-1, t+1));
    else return dp[l][r] = min(card(l+1, r, t+1), card(l, r-1, t+1));
}

void solve(){
    card(0, n-1, 1);
    cout << dp[0][n-1] << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--){
        input();
        solve();
    }

    return 0;
}