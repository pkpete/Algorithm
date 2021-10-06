#include <iostream>
using namespace std;
struct tree {
	char left, right;
};

tree arr[26];

void preorder(char c) {
	if (c == '.') return;
	cout << c;
	preorder(arr[c - 'A'].left);
	preorder(arr[c - 'A'].right);
}
void inorder(char c) {
	if (c == '.') return;
	inorder(arr[c - 'A'].left);
	cout << c;
	inorder(arr[c - 'A'].right);
}
void postorder(char c) {
	if (c == '.') return;
	postorder(arr[c - 'A'].left);
	postorder(arr[c - 'A'].right);
	cout << c;
}
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		char parent, left, right;
		cin >> parent >> left >> right;
		arr[parent - 'A'].left = left;
		arr[parent - 'A'].right = right;
	}
	
	preorder('A'); cout << "\n";
	inorder('A'); cout << "\n";
	postorder('A'); cout << "\n";
	
}