#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> graph[101];
bool visit[101];
int cnt = 0;
void cnt_parent(int idx, int a, int b) {
    // cout << idx << " ";
    cnt++;
    for (int i = 0; i < graph[idx].size(); i++) {
        if (!visit[graph[idx][i]] && !((idx == a && graph[idx][i] == b) || idx == b && graph[idx][i] == a)) {
            visit[graph[idx][i]] = true;
            cnt_parent(graph[idx][i], a, b);
            visit[graph[idx][i]] = false;
        }
    }
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 10000;
    for (int i = 0; i < wires.size(); i++) {
        int a = wires[i][0], b = wires[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < wires.size(); i++) {
        int a = wires[i][0], b = wires[i][1];
        cnt = 0;
        for (int j = 0; j <= n; j++)
            visit[i] = false;
        visit[1] = true;

        // cout << a << " " << b << "\n";

        cnt_parent(1, a, b);
        // cout << "\n" << "answer : " << abs(n-cnt) << "\n";
        answer = min(answer, abs(cnt - abs(n - cnt)));
    }
    return answer;
}