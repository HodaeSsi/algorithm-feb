#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int parent[100001];
vector<tuple<int,int,int>> v; // x1, x2, num

int Find(int x) {
    int px=parent[x];
    if (x==px) return x;
    return parent[x]=Find(px);
}

void Union(int x, int y) {
    int px=Find(x);
    int py=Find(y);

    if (px!=py) {
        parent[px]=py;
    }
}

void chk(int cur,int nxt) {
    auto a=v[cur];
    auto b=v[nxt];

    if (get<1>(a)>=get<0>(b)) {
        Union(get<2>(a),get<2>(b));
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,q;
    cin>>n>>q;

    for (int i=0;i<n;i++) {
        int x1,x2,y;
        cin>>x1>>x2>>y;

        v.push_back({x1,x2,i+1});
    }

    sort(v.begin(),v.end());

    for (int i=0;i<=n;i++) {
        parent[i]=i;
    }

    int maxIdx=0;
    for (int i=1;i<n;i++) {
        chk(maxIdx,i);

        if (get<1>(v[i])>get<1>(v[maxIdx])) maxIdx=i;
    }

    for (int i=0;i<q;i++) {
        int a,b;
        cin>>a>>b;

        if (Find(a)==Find(b)) cout<<"1\n";
        else cout<<"0\n";
    }
}
