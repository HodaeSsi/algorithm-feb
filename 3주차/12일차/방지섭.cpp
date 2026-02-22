#include <bits/stdc++.h>
using namespace std;

int n,m, cnt;
char A[10000][500];
bool visited[10000][500], flag;
void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> A[i][j];
}

int dx[] = {-1,0,1}, dy[] = {1,1,1};
void dfs(int x, int y){
    if(flag) return;
    if(y == m-1){
        flag = true;
        cnt++;
        return;
    }
    for(int i=0;i<3;i++){
        if(flag) return;
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && A[nx][ny] != 'x' && !visited[nx][ny]){
            visited[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}

void solve(){
    for(int i=0;i<n;i++){
        flag = false;
        dfs(i,0);
    }
    cout << cnt;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}