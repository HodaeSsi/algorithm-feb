#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int l[200001];
int r[200001];

int n;

int dfs(int node, long long int k)
{
    if (l[node]==-1)
    {
        if (r[node]==-1)
        {
            return node;
        }
        return dfs(r[node], k);
    }
    if (r[node]==-1)
    {
        return dfs(l[node], k);
    }
    if (k%2ll)
    {
        return dfs(l[node], k/2ll+1ll);
    }
    return dfs(r[node], k/2ll);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    long long int k;
    cin>>k;
    cout<<dfs(1, k);
}
