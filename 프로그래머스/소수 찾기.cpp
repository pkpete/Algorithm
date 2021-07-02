#include <string>
#include <vector>

using namespace std;

const int MAX_NUM = 10000000;
int prime_num[MAX_NUM];
bool check[MAX_NUM];
vector<bool> num;
int answer = 0;
void dfs(int tmp, string numbers) {
    if (prime_num[tmp] == 0 && !check[tmp]) {
        answer++;
        check[tmp] = true;
    }

    for (int i = 0; i < numbers.size(); i++) {
        if (!num[i]) {
            num[i] = true;
            dfs(tmp * 10 + numbers[i] - '0', numbers);
            num[i] = false;
        }
    }
}

int solution(string numbers) {

    prime_num[0] = 1;
    prime_num[1] = 1;
    for (int i = 2; i < MAX_NUM; i++) {
        if (prime_num[i] == 0)
            for (int j = 2 * i; j < MAX_NUM; j = j + i) {
                prime_num[j] = 1;
            }
    }

    num = vector<bool>(numbers.size());
    for (int i = 0; i < numbers.size(); i++) {
        num[i] = true;
        dfs(numbers[i] - '0', numbers);
        num[i] = false;
    }

    return answer;
}