#include <bits/stdc++.h>
using namespace std;

vector<int> v[100001];
bool visited[100001];
int n,m,k; 
int a,b; 
long long cnt[2];
bool flag = false;

void input(){
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        int aa,bb; cin >> aa >> bb;
        if(i == k){
            a = aa, b = bb;
            continue;
        }
        v[aa].push_back(bb);
        v[bb].push_back(aa);
    }
}

void dfs(int num, int t){
    cnt[t]++;
    if(flag) return;

    for(auto k : v[num]){
        if(t == 0 && k == b){
            flag = true;
            return;
        }
        if(!visited[k]){
            visited[k] = true;
            dfs(k, t);
        }
    }
}

long long solve(){
    visited[a] = true;
    dfs(a, 0);
    if(flag) return 0;

    for(int i=1;i<=n;i++) visited[i] = false;
    visited[b] = true;
    dfs(b, 1);

    // cout << cnt[0] << " " << cnt[1] << "\n";
    return cnt[0] * cnt[1];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    cout << solve();

    return 0;
}

// 해당 하는 간선의 두 점 a,b에 저장.
// 해당 간선은 연결 x, 나머지 간선들은 연결
// a에서 출발해서 dfs를 했는데 b가 나온다? -> 0
// a에서 출발해서 그룹 수 cnt_a에 저장, b에서 출발해서 그룹 수 cnt_b에 저장.
// 둘이 곱하고 출력.