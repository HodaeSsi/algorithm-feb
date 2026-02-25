#include <bits/stdc++.h>
using namespace std;

struct node{
    int x1, x2, y, idx;

    bool operator<(const node other) const{
        if(x1 == other.x1) return x2 < other.x2;
        return x1 < other.x1;
    }
};

int n,q;
vector<node> v;
int group[100000];
void input(){
    cin >> n >> q;        
    v.resize(n);
    for(int i=0;i<n;i++){
        int a,b,c; cin >> a >> b >> c;
        v[i] = {a,b,c,i};
    }                  
    sort(v.begin(), v.end());
}

void solve(){
    int cur_end = v[0].x2, cur_group_idx = 0;
    group[v[0].idx] = cur_group_idx;
    for(int i=1;i<n;i++){
        if(cur_end < v[i].x1) ++cur_group_idx;
        group[v[i].idx] = cur_group_idx;
        cur_end = max(cur_end, v[i].x2);
    }
    for(int i=0;i<q;i++){
        int a,b; cin >> a >> b;
        a--, b--;
        if(group[a] == group[b]) cout << "1\n";
        else cout << "0\n"; 
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}