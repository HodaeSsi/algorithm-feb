#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[200001]; // 순서대로 left, right

void dfs(int num, long long val) {
    if (graph[num].size() == 0) {
        cout << num;
        exit(0);
    }
    
    if (graph[num].size() == 1) {
        dfs(graph[num][0], val);
    }
    // 자식이 두 개인 경우
    else {
        // 짝수면 오른쪽, 홀수면 왼쪽으로
        if (val % 2 == 0) {
            dfs(graph[num][1], val / 2);
        }
        else {
            dfs(graph[num][0], val / 2 + 1);
        }
    }
    

}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        
        if (a != -1)
            graph[i].push_back(a);
        if (b != -1)
            graph[i].push_back(b);
    }
    
    long long k;
    cin >> k;
    dfs(1, k);
}
