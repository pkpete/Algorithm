#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int a, b, c, x, y;	// ���ġŲ, �Ķ��̵� ġŲ, �ݹ�ġŲ ���� ,,,,,,,,,,,, ���ġŲ, �Ķ��̵� ġŲ �ּ� ������
	cin >> a >> b >> c >> x >> y;
	int cost = a * x + b * y;

	if (x < y) {
		int tmp = x * 2 * c + (y - x) * b;
		cost = min(cost, tmp);
		cost = min(cost, y * 2 * c);
	}
	else if (x > y) {
		int tmp = y * 2 * c + (x - y) * a;
		cost = min(cost, tmp);
		cost = min(cost, x * 2 * c);
	}
	else {
		int tmp = c * 2 * x;
		cost = min(cost, tmp);
	}

	cout << cost;
}