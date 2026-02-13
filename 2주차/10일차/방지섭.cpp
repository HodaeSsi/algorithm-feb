#include <bits/stdc++.h>
using namespace std;

int n,m, A[1000][1000], dp[1000][1000][2];
void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){cin >> A[i][j]; dp[i][j][0] = dp[i][j][1] = INT32_MIN;}
}

void solve(){
    dp[0][0][0] = A[0][0];
    for(int i=0;i<m;i++){
        if(i != 0) dp[0][i][0] = dp[0][i-1][0] + A[0][i];
        dp[1][i][0] = dp[1][i][1] = dp[0][i][0] + A[1][i];
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<m-1;j++) dp[i][j+1][0] = max(dp[i][j+1][0], dp[i][j][0] + A[i][j+1]);
        for(int j=m-1;j>0;j--) dp[i][j-1][1] = max(dp[i][j-1][1], dp[i][j][1] + A[i][j-1]);
        if(i != n-1) for(int j=0;j<m;j++) dp[i+1][j][0] = dp[i+1][j][1] = (max(dp[i][j][0], dp[i][j][1]) + A[i+1][j]);
    }
    cout << max(dp[n-1][m-1][0], dp[n-1][m-1][1]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}