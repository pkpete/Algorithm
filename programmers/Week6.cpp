#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct box {
    double wins;
    int w_wins, weight, num;
};

bool cmp(box a, box b) {
    if (a.wins > b.wins) {
        return true;
    }
    else if (a.wins == b.wins) {
        if (a.w_wins > b.w_wins)
            return true;
        else if (a.w_wins == b.w_wins) {
            if (a.weight > b.weight)
                return true;
            else if (a.weight == b.weight) {
                if (a.num < b.num)
                    return true;
            }
        }
    }
    return false;
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    vector<box> array;
    for (int i = 0; i < head2head.size(); i++) {
        double wins = 0; int w_wins = 0;
        double cnt = 0;
        for (int j = 0; j < head2head[i].size(); j++) {
            if (head2head[i][j] == 'N') continue;
            cnt++;
            if (head2head[i][j] == 'W') {
                wins++;
                if (weights[i] < weights[j]) {
                    w_wins++;
                }
            }
        }
        if (wins == 0)
            array.push_back({ wins, w_wins, weights[i], i + 1 });
        else
            array.push_back({ wins, w_wins, weights[i], i + 1 });
    }

    sort(array.begin(), array.end(), cmp);

    for (int i = 0; i < array.size(); i++) {
        answer.push_back(array[i].num);
    }

    return answer;
}