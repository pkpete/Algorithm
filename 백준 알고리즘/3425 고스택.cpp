#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
// 입력을 처리하는 부분
	// 명령어 문자로 들어오니까 명령어에 따라서 분기
	// NUM 같은 경우는 뒤에 숫자가 들어옴
	// 분기를 해서 적절한 명령어를 수행해야함
// 스택의 구현
	// 자료구조 사용
	// top에서 값을 추가, 더하거나, 나누거나 ...
// 명령어를 구현하는 부분... 총 10개정도
	// 가장 중요하다고 생각함
	// 예외처리
		// divide 해야하는데 0이거나
		// 값을 연산해야 되는데 값이 너무 큼	-> 자료형 주의
		// pop해야되는데 값이 없거나
// 초기화 + 각각의 연산을 수행하는 로직

// 주의할점
	// 1. 예외처리
	// 2. 초기화 안되는 것
	// 3. 디버깅 ... 굉장히 힘듬

const int MAX_NUM = 1000000000;

int main() {
	while (1) {
		bool quit = false;
		vector<string> commands;
		vector<long long> numbers;
		while (1) {
			// 명령어 입력 받기
			string str;
			cin >> str;

			// QUIT 입력 받으면 끝내기
			if (str == "QUIT") {
				quit = true;
				break;
			}

			if (str == "NUM") {
				long long ltmp;
				cin >> ltmp;
				numbers.push_back(ltmp);
			}

			
			// END 입력 받으면 명령어 입력 받기 끝
			if (str == "END") break;
			commands.push_back(str);
		}

		// QUIT 입력 받아서 끝내기
		if (quit) break;

		int n, num;
		
		cin >> n;
		for (int i = 0; i < n; i++) {
			int idx = 0;
			stack<long long> st;
			cin >> num;
			st.push(num);
			// 예외 경우 에러 값을 true로 하여 break함
			bool error = false;
			for (int j = 0; j < commands.size(); j++) {
				if (commands[j] == "") continue;
				if (commands[j].size() == 3) {
					// 스택 가장 위의 숫자를 제거한다
					if (commands[j] == "POP") {	
						// 예외처리
						if (st.empty()) {
							error = true;
							break;
						}
						st.pop();
					}
					// 첫 번쨰 수의 부호를 바꾼다
					else if (commands[j] == "INV") {
						// 예외처리
						if (st.empty()) {
							error = true;
							break;
						}
						long long top = st.top();
						st.pop();
						st.push(top * -1);
					}
					//첫 번쨰 숫자를 하나 더 스택의 가장 위에 저장한다
					else if (commands[j] == "DUP") {
						// 예외처리
						if (st.empty()) {
							error = true;
							break;
						}
						st.push(st.top());
					}
					// 첫 번쨰 숫자와 두 번째 숫자의 위치를 바꾼다
					else if (commands[j] == "SWP") {
						// 예외처리
						if (st.size() < 2) {
							error = true;
							break;
						}
						long long first = st.top(); st.pop();
						long long second = st.top(); st.pop();
						st.push(first); st.push(second);

					}
					// 첫 번째 숫자와 두 번째 숫자를 더한다
					else if (commands[j] == "ADD") {
						// 예외처리
						if (st.size() < 2) {
							error = true;
							break;
						}
						long long first = st.top(); st.pop();
						long long second = st.top(); st.pop();
						if (abs(first + second) > MAX_NUM) {
							error = true;
							break;
						}
						st.push(first + second);
					}
					// 첫 번째 숫자와 두 번째 숫자를 뺀다
					else if (commands[j] == "SUB") {
						// 예외처리
						if (st.size() < 2) {
							error = true;
							break;
						}
						long long first = st.top(); st.pop();
						long long second = st.top(); st.pop();
						if (abs(second - first) > MAX_NUM) {
							error = true;
							break;
						}
						st.push(second - first);
					}
					// 첫 번째 숫자와 두 번째 숫자를 곱한다
					else if (commands[j] == "MUL") {
						// 예외처리
						if (st.size() < 2) {
							error = true;
							break;
						}
						long long first = st.top(); st.pop();
						long long second = st.top(); st.pop();
						// 10^9을 넘어갈때 예외처리
						if (abs(second * first) > MAX_NUM) {
							error = true;
							break;
						}
						st.push(second * first);
					}
					// 첫 번째 숫자로 두 번째 숫자를 나눈 몫을 저장한다. 
					// 두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.
					else if (commands[j] == "DIV") {
						// 예외 처리
						if (st.size() < 2) {
							error = true;
							break;
						}
						int cnt = 0;
						long long first = st.top(); st.pop();
						if (first == 0) {
							error = true;
							break;
						}
						long long second = st.top(); st.pop();
						if (abs(second / first) > MAX_NUM) {
							error = true;
							break;
						}
						st.push(second / first);
						
	
					}
					// 첫 번째 숫자로 두 번째 숫자를 나눈 나머지를 저장한다. 
					// 두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.
					else if (commands[j] == "MOD") {
						// 예외 처리
						if (st.size() < 2) {
							error = true;
							break;
						}
						int cnt = 0;
						long long first = st.top(); st.pop();
						long long second = st.top(); st.pop();
						if (first == 0) {
							error = true;
							break;
						}if (abs(second % first) > MAX_NUM) {
							error = true;
							break;
						}
						st.push(second % first);
					}
					else if (commands[j] == "NUM") {
						long long tmp_num = numbers[idx++];
						if (tmp_num > MAX_NUM) {
							error = true;
							break;
						}
						st.push(tmp_num);
					}
				}
				if (error)
					break;
			}
			if (st.size() != 1)
				error = true;

			if (error)
				cout << "ERROR" << endl;
			else
				cout << st.top() << endl;
		}
		cout << endl;		
	}
}