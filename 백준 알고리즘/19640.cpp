#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int people, line, k; // �����, �ټ�, ��ī �տ� �ִ� ��� ��
struct emp{
	int days, priority, index, line;
	emp(int a, int b, int c, int d) : days(a), priority(b), index(c), line(d){}
};
struct cmp{
	bool operator()(const emp &a, const emp &b){
		if(a.days != b.days)	
			return a.days < b.days;	//�� ���� ���� �����
		else if(a.days == b.days){
			if(a.priority != b.priority)
				return a.priority < b.priority;	//�켱������ �� ū �����
			else if(a.priority == b.priority){
				return a.line > b.line;	//���� ��ȣ�� ���� �����
			}
		}
	}
};

vector<emp> v;
priority_queue<emp, vector<emp>, cmp> pq;

int main(){
	int d, p;
	cin >> people >> line >> k;
	for(int i = 0; i < people; i++){
		cin >> d >> p;
		v.push_back(emp(d,p,i,i%line));
	}
	int count = 0;
	// ó���� ���� �� ��ŭ ť���� �� �켱���� ť�� �ִ´�.

	for(int i = 0; i < line; i++){
		if(i < people)
			pq.push(v[i]);
		else break;
	}

	while(1){
		//�켱���� ť���� 1�� ����
		//�� ���� index,,,, v[index+line]�� �켱���� ť�� �־�
		emp e = pq.top();
		pq.pop();
		int line_num = e.index + line;
		if(line_num < people)
			pq.push(v[line_num]);
		if(e.index == k){	//Decka�̸� �������Ͷ�
			break;
		}
		count++;
	}
	cout << count;
}