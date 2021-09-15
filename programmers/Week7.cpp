#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
    int size = enter.size();

    vector<int> answer(size);
    deque<int> in_q, out_q;

    for (int i = 0; i < size; i++) {
        int in = enter[i];  // �濡 ������ ���
        int out = leave[i]; // �濡 ���� ���

        in_q.push_back(in);     // �迭�� �־�
        out_q.push_back(out);   // ť�� �־�

        int q_size = in_q.size();

        for (int i = q_size - 1; i >= 0; i--) {
            // ���� ����� �ִ��� Ȯ��

            int tmp = in_q[i];
            if (!out_q.empty() && tmp == out_q[0]) {
                // ���� ����Ű�� �ִ� ����� ������ �Ǵ� ����̸�(ť�� ���� �� �տ� ����)
                out_q.pop_front();  // ť pop
                in_q[i] = -1;       // �迭�� �����ٰ� ǥ��

                for (int j = 0; j < in_q.size(); j++) {
                    // �迭�� �ִ� ��� �� == ���� ������ ����� ���� ��
                    if (in_q[j] == -1) continue;
                    answer[tmp - 1] ++;
                }

                for (int j = 0; j < in_q.size(); j++) {
                    // ���� ���� ��� �����ſ��� �迭�� �ִ� ��� �� +1 ����
                    if (in_q[j] == -1) continue;
                    answer[in_q[j] - 1]++;
                }
                i = q_size - 1; // ť�� ���� �ִ� ������� �ٽ� Ȯ���ؾߵ�
            }
        }

    }

    return answer;
}