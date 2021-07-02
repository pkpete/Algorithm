#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer(3);
    int one[] = { 1,2,3,4,5 };
    int two[] = { 2,1,2,3,2,4,2,5 };
    int three[] = { 3,3,1,1,2,2,4,4,5,5 };

    int num = 0;

    for (int i = 0; i < answers.size(); i++) {
        int tmp = i % 5;
        if (one[i % 5] == answers[i])
            answer[0]++;
        if (two[i % 8] == answers[i])
            answer[1]++;
        if (three[i % 10] == answers[i])
            answer[2]++;
    }

    for (int i = 0; i < 3; i++) {
        num = max(num, answer[i]);
    }
    vector<int> aws;
    for (int i = 0; i < 3; i++) {
        if (num == answer[i])
            aws.push_back(i + 1);
    }

    return aws;
}