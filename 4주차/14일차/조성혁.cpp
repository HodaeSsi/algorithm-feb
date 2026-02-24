#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int row[20];
int n;
int ans=2e9;

// 행 우선 뒤집기
void dfs(int idx) {
    if (idx==n) {
        int cur=0;
        // 이제 열을 뒤집는다.
        // 1의 개수가 n/2 초과인 경우 뒤집는다.
        for (int j=0;j<n;j++) {
            int sum=0;
            for (int i=0;i<n;i++) {
                sum+=row[i]>>n-j-1&1;
            }

            if (sum>n/2) cur+=n-sum;
            else cur+=sum;
        }

        ans=min(ans,cur);

        return;
    }

    // 안 뒤집기
    dfs(idx+1);

    // 뒤집기
    row[idx]=~row[idx];
    dfs(idx+1);
    row[idx]=~row[idx];
}

int main() {
    cin>>n;

    for (int i=0;i<n;i++) {
        string input;
        cin>>input;
        for (int j=0;j<n;j++) {
            // T는 1, H는 0으로
            if (input[j]=='T') {
                row[i]|=1<<n-j-1;
            }
        }
    }

    dfs(0);

    cout<<ans;
}
