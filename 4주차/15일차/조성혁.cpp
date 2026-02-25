#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <queue>

using namespace std;

int parent[100001];

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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,q;
    cin>>n>>q;

    vector<tuple<int,int,int>> v; // x1, x2, y
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq; // x좌표, command(1이면 삭제, 0이면 삽입), 통나무 번호
    v.push_back({0,0,0}); // 보정
    for (int i=1;i<=n;i++) {
        int x1,x2,y;
        cin>>x1>>x2>>y;

        v.push_back({x1,x2,y});
        pq.push({x1,0,i});
        pq.push({x2,1,i});
    }

    for (int i=0;i<=n;i++) {
        parent[i]=i;
    }

    set<pair<int,int>> s; // y, num
    while (!pq.empty()) {
        int cmd=get<1>(pq.top());
        int num=get<2>(pq.top());
        int y=get<2>(v[num]);
        pq.pop();

        // 삽입 후 나와 인접 통나무들과 Union
        if (!cmd) {
            s.insert({y,num});
            auto it=s.find({y,num});

            if (it!=s.begin()) {
                auto prv=prev(it);
                Union(num,prv->second);
            }

            auto nxt=next(it);
            if (nxt!=s.end()) {
                Union(num,nxt->second);
            }
        }
        // 삭제 후 인접 통나무 간 Union
        else {
            auto it=s.find({y,num});
            auto nxt=next(it);
            if (it!=s.begin()&&nxt!=s.end()) {
                auto prv=prev(it);
                Union(prv->second,nxt->second);
            }
            s.erase({y,num});
        }
    }

    for (int i=0;i<q;i++) {
        int a,b;
        cin>>a>>b;

        if (Find(a)==Find(b)) cout<<"1\n";
        else cout<<"0\n";
    }
}
