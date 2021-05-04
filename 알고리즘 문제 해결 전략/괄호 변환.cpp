#include <string>
#include <iostream>
using namespace std;

string make_balance(string p) {
    if (p == "")
        return "";
    string u = "", v = "", answer = "";
    int left = 0, right = 0;
    bool correct = true;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') {
            left++;
        }
        else {
            right++;
        }
        u += p[i];
        if (right > left)
            correct = false;
        if (left == right) {  //±ÕÇüÀâÈù °ıÈ£
            for (int j = i + 1; j < p.size(); j++) {
                v += p[j];
            }
            if (correct) {    // ¿Ã¹Ù¸¥ °ıÈ£
                answer += u;
                answer += make_balance(v);
            }
            else {
                answer = "(" + make_balance(v) + ")";
                for (int i = 1; i < u.size() - 1; i++) {
                    if (u[i] == '(') {
                        u[i] = ')';
                    }
                    else if (u[i] == ')') {
                        u[i] = '(';
                    }
                    answer += u[i];
                }
            }
            return answer;
        }
    }
}

int main() {
    string p;
    cin >> p;
    cout << make_balance(p);
}