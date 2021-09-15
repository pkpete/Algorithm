#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
    int size = enter.size();

    vector<int> answer(size);
    deque<int> in_q, out_q;

    for (int i = 0; i < size; i++) {
        int in = enter[i];  // 방에 들어오는 사람
        int out = leave[i]; // 방에 나갈 사람

        in_q.push_back(in);     // 배열에 넣어
        out_q.push_back(out);   // 큐에 넣어

        int q_size = in_q.size();

        for (int i = q_size - 1; i >= 0; i--) {
            // 나갈 사람이 있는지 확인

            int tmp = in_q[i];
            if (!out_q.empty() && tmp == out_q[0]) {
                // 현재 가리키고 있는 사람이 나가야 되는 사람이면(큐의 가장 맨 앞에 있음)
                out_q.pop_front();  // 큐 pop
                in_q[i] = -1;       // 배열에 나갔다고 표시

                for (int j = 0; j < in_q.size(); j++) {
                    // 배열에 있는 사람 수 == 현재 나가는 사람의 만난 수
                    if (in_q[j] == -1) continue;
                    answer[tmp - 1] ++;
                }

                for (int j = 0; j < in_q.size(); j++) {
                    // 현재 나간 사람 만난거여서 배열에 있는 사람 다 +1 해줌
                    if (in_q[j] == -1) continue;
                    answer[in_q[j] - 1]++;
                }
                i = q_size - 1; // 큐에 남아 있는 사람들을 다시 확인해야됨
            }
        }

    }

    return answer;
}