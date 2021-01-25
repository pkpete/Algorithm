#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int K;
vector<int> maxNum, minNum;
string sign;
//�ε�ȣ�� �����ϴ��� Ȯ��
bool valid(vector<int>& v){

    for (int i = 0; i < sign.length(); i++)
        if (sign[i] == '<' && v[i] > v[i + 1])
            return false;
        else if (sign[i] == '>' && v[i] < v[i + 1])
            return false;
    //����� ���� ���
    return true;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin ����ӵ� ���
    cin >> K;
    for (int i = 0; i < K; i++){
        char temp;
        cin >> temp;
        sign += temp;
    }

    //�ִ�
    for (int i = 9; i > 9 - (K + 1); i--)
        maxNum.push_back(i);

    while (1)
    {
        if (valid(maxNum))
            break;
        prev_permutation(maxNum.begin(), maxNum.end());
    }

    //�ּ�
    for (int i = 0; i < (K + 1); i++)
        minNum.push_back(i);

    while (1){
        if (valid(minNum))
            break;
        next_permutation(minNum.begin(), minNum.end());
    }

    for (int i = 0; i < maxNum.size(); i++)
        cout << maxNum[i];
    cout << "\n";
    for (int i = 0; i < minNum.size(); i++)
        cout << minNum[i];
    cout << "\n";
    return 0;
}
