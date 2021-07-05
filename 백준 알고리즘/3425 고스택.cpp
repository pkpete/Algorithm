#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
// �Է��� ó���ϴ� �κ�
	// ��ɾ� ���ڷ� �����ϱ� ��ɾ ���� �б�
	// NUM ���� ���� �ڿ� ���ڰ� ����
	// �б⸦ �ؼ� ������ ��ɾ �����ؾ���
// ������ ����
	// �ڷᱸ�� ���
	// top���� ���� �߰�, ���ϰų�, �����ų� ...
// ��ɾ �����ϴ� �κ�... �� 10������
	// ���� �߿��ϴٰ� ������
	// ����ó��
		// divide �ؾ��ϴµ� 0�̰ų�
		// ���� �����ؾ� �Ǵµ� ���� �ʹ� ŭ	-> �ڷ��� ����
		// pop�ؾߵǴµ� ���� ���ų�
// �ʱ�ȭ + ������ ������ �����ϴ� ����

// ��������
	// 1. ����ó��
	// 2. �ʱ�ȭ �ȵǴ� ��
	// 3. ����� ... ������ ����

const int MAX_NUM = 1000000000;

int main() {
	while (1) {
		bool quit = false;
		vector<string> commands;
		vector<long long> numbers;
		while (1) {
			// ��ɾ� �Է� �ޱ�
			string str;
			cin >> str;

			// QUIT �Է� ������ ������
			if (str == "QUIT") {
				quit = true;
				break;
			}

			if (str == "NUM") {
				long long ltmp;
				cin >> ltmp;
				numbers.push_back(ltmp);
			}

			
			// END �Է� ������ ��ɾ� �Է� �ޱ� ��
			if (str == "END") break;
			commands.push_back(str);
		}

		// QUIT �Է� �޾Ƽ� ������
		if (quit) break;

		int n, num;
		
		cin >> n;
		for (int i = 0; i < n; i++) {
			int idx = 0;
			stack<long long> st;
			cin >> num;
			st.push(num);
			// ���� ��� ���� ���� true�� �Ͽ� break��
			bool error = false;
			for (int j = 0; j < commands.size(); j++) {
				if (commands[j] == "") continue;
				if (commands[j].size() == 3) {
					// ���� ���� ���� ���ڸ� �����Ѵ�
					if (commands[j] == "POP") {	
						// ����ó��
						if (st.empty()) {
							error = true;
							break;
						}
						st.pop();
					}
					// ù ���� ���� ��ȣ�� �ٲ۴�
					else if (commands[j] == "INV") {
						// ����ó��
						if (st.empty()) {
							error = true;
							break;
						}
						long long top = st.top();
						st.pop();
						st.push(top * -1);
					}
					//ù ���� ���ڸ� �ϳ� �� ������ ���� ���� �����Ѵ�
					else if (commands[j] == "DUP") {
						// ����ó��
						if (st.empty()) {
							error = true;
							break;
						}
						st.push(st.top());
					}
					// ù ���� ���ڿ� �� ��° ������ ��ġ�� �ٲ۴�
					else if (commands[j] == "SWP") {
						// ����ó��
						if (st.size() < 2) {
							error = true;
							break;
						}
						long long first = st.top(); st.pop();
						long long second = st.top(); st.pop();
						st.push(first); st.push(second);

					}
					// ù ��° ���ڿ� �� ��° ���ڸ� ���Ѵ�
					else if (commands[j] == "ADD") {
						// ����ó��
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
					// ù ��° ���ڿ� �� ��° ���ڸ� ����
					else if (commands[j] == "SUB") {
						// ����ó��
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
					// ù ��° ���ڿ� �� ��° ���ڸ� ���Ѵ�
					else if (commands[j] == "MUL") {
						// ����ó��
						if (st.size() < 2) {
							error = true;
							break;
						}
						long long first = st.top(); st.pop();
						long long second = st.top(); st.pop();
						// 10^9�� �Ѿ�� ����ó��
						if (abs(second * first) > MAX_NUM) {
							error = true;
							break;
						}
						st.push(second * first);
					}
					// ù ��° ���ڷ� �� ��° ���ڸ� ���� ���� �����Ѵ�. 
					// �� ��° ���ڰ� ������, ù ��° ���ڰ� �����̴�.
					else if (commands[j] == "DIV") {
						// ���� ó��
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
					// ù ��° ���ڷ� �� ��° ���ڸ� ���� �������� �����Ѵ�. 
					// �� ��° ���ڰ� ������, ù ��° ���ڰ� �����̴�.
					else if (commands[j] == "MOD") {
						// ���� ó��
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