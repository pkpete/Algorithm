#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> st;

    for (int i = 0; i < prices.size(); i++)
    {
        //������ ��������ʰ� ���ø����� ���� ���簪���� ũ�ٸ�
       //-> ������ �������ٸ�
        while (!st.empty() && prices[st.top()] > prices[i])
        {
            //������ ���������Ƿ� i - ���� �������� ����
            answer[st.top()] = i - st.top();
            //������
            st.pop();
            //�ݺ����� ����: ������ �������� �����Ǿ������
            //���簪���� ��������Ƿ� 1�����̾� �־��ֱ� ���ؼ���.
        }
        //���� �ε����� ���ÿ� �ֱ�
        st.push(i);
    }
    //������ �������� �ݺ�
    while (!st.empty())
    {
        //������ Ư����ġ�� �̹̰��� �־����Ƿ� pushback�̳� insert���ϸ� �ȵȴ�.
        //�ڿ������� �־���ϹǷ� size-1 ���� top���� ���ش�.
        answer[st.top()] = prices.size() - st.top() - 1;
        st.pop();
    }

    return answer;
}