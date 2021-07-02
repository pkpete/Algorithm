#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); i++) {
        pq.push(priorities[i]);
        q.push(make_pair(priorities[i], i));
    }

    while (!q.empty()) {
        int pqfirst = pq.top();
        int qfirst = q.front().first;
        int qlocation = q.front().second;
        q.pop();
        if (qfirst == pqfirst) {
            pq.pop();
            answer++;
            if (qlocation == location)
                break;
        }
        else {
            q.push(make_pair(qfirst, qlocation));
        }
    }
    return answer;
}