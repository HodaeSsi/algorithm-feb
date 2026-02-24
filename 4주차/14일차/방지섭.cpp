#include <bits/stdc++.h>
using namespace std;

int n;
bool A[20][20];
bool is_reverse[20]; // 뒤집어진 행
void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c; cin >> c;
            if(c == 'T') A[i][j] = true;
            else A[i][j] = false;
        }
    }
}

void solve()
{
    int ans = INT32_MAX;
    for(int i=0;i<(1<<n);i++){
        int temp = 1;
        int sum = 0;
        for(int j=0;j<n;j++){ // 비트가 1이면 해당 행을 뒤집기
            is_reverse[j] = false;
            if((i & temp) != 0) is_reverse[j] = true;
            temp *= 2;
        }

        // 각 열에 대해서 T,H 중 작은 걸 골라서 더하기. 여기서 행의 is_reverse가 true면 T는 H로 H는 T로 cnt해야함.
        for(int j=0;j<n;j++){ // 열
            vector<int> cnt(2, 0);
            for(int k=0;k<n;k++){ // 행
                if(is_reverse[k]) cnt[!A[k][j]]++;
                else cnt[A[k][j]]++;
            }
            sum += min(cnt[0], cnt[1]);
        }
        ans = min(ans, sum);
    }
    cout << ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}