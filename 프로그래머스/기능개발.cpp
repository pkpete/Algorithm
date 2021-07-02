#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int index = 0;

    while (1) {
        int cnt = 0;
        if (index == speeds.size())  break;

        for (int i = index; i < speeds.size(); i++) {
            progresses[i] += speeds[i];
        }

        for (int i = index; i < speeds.size(); i++) {
            if (progresses[i] < 100) break;
            cnt++;
            index++;
        }

        if (cnt > 0)
            answer.push_back(cnt);
    }

    return answer;
}