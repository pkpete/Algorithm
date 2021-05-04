#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int people, line, k; // 사람수, 줄수, 데카 앞에 있는 사원 수
struct emp{
	int days, priority, index, line;
	emp(int a, int b, int c, int d) : days(a), priority(b), index(c), line(d){}
};
struct cmp{
	bool operator()(const emp &a, const emp &b){
		if(a.days != b.days)	
			return a.days < b.days;	//더 많이 일한 사람이
		else if(a.days == b.days){
			if(a.priority != b.priority)
				return a.priority < b.priority;	//우선순위가 더 큰 사람이
			else if(a.priority == b.priority){
				return a.line > b.line;	//줄의 번호가 작은 사람이
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
	// 처음에 줄의 수 만큼 큐에서 빼 우선순위 큐에 넣는다.

	for(int i = 0; i < line; i++){
		if(i < people)
			pq.push(v[i]);
		else break;
	}

	while(1){
		//우선순위 큐에서 1명 빼고
		//뺀 놈의 index,,,, v[index+line]을 우선순위 큐에 넣어
		emp e = pq.top();
		pq.pop();
		int line_num = e.index + line;
		if(line_num < people)
			pq.push(v[line_num]);
		if(e.index == k){	//Decka이면 빠져나와라
			break;
		}
		count++;
	}
	cout << count;
}