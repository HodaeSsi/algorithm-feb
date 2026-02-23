#include <bits/stdc++.h>
using namespace std;

long long n,k;
vector<pair<long long,long long>> v;

void input()
{
    cin >> n;
    v.resize(n + 1);
    for (long long i = 1; i <= n; i++)
    {
        long long a, b;
        cin >> a >> b;
        v[i] = {a,b};
    }
    cin >> k;
}

// leap node에 도착할 때까지 자식 상황에 따라 num을 깎으면서 순회.
void dfs(long long num, long long idx){
    if(v[idx].first == -1 && v[idx].second == -1) cout << idx; // 자식 없음 -> 출력
    else if(v[idx].first == -1 && v[idx].second != -1) dfs(num, v[idx].second); // 오른쪽 자식만 있음 -> 그대로 내려감
    else if(v[idx].first != -1 && v[idx].second == -1) dfs(num, v[idx].first); // 왼쪽 자신만 있음 -> 그대로 내려감
    else{ // 자식이 둘임. -> 홀수면 왼쪽, 짝수면 오른쪽으로 감.
        if(num % 2) dfs(num/2+1, v[idx].first);
        else dfs(num/2, v[idx].second);
    }
}

void solve()
{
    dfs(k, 1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}