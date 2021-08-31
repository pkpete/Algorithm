#include <string>
#include <vector>
#include <iostream>

using namespace std;

string alpha = "AEIOU";
int answer = 0;
bool val = false;
int cnt = 0;

void dfs(string cur, string word) {
    if (cur.size() > 5) {
        cnt -= 1;
        return;
    }
    cout << cur << endl;
    if (cur == word) {
        answer = cnt;
        val = true;
        return;
    }
    for (int i = 0; i < alpha.size(); i++) {
        cnt += 1;
        dfs(cur + alpha[i], word);
        if (val)
            return;
    }
}

int main() {
    string word;
    cin >> word;
    dfs("", word);
    cout << answer;
}