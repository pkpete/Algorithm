#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int main() {
    cin >> N >> M;
    if (N == 1) //���� ��ĭ�̸� ������ �� ����
        cout << 1 << endl;
    else if (N == 2) //���ΰ� �� ĭ�̸� 2�� 3���� ����(3ȸ������ ������ �� �ִ�)
        cout << min(4, (M + 1) / 2) << endl;
    //1, 2, 3, 4���� ��� �ѹ����� ���;� �Ѵ�
    else if (N >= 3)
    {
        //���ΰ� 6������ �ִ� 4ĭ(1��, 4��, 2 or 3��)
        if (M <= 6)
            cout << min(4, M) << endl;
        else //2�� 3�� �ѹ��� �������� 1��, 4��
            cout << M - 2 << endl;
    }
}