#include <iostream>
using namespace std;
int a[100][100];
int b[100][100];
int answer[100][100];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	int k;
	cin >> m >> k;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < k; j++)
			cin >> b[i][j];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int l = 0; l < k; l++){
				answer[i][l] += a[i][j] * b[j][l];
			}
		}
	}
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < k; j++)
			cout << answer[i][j] << " ";
		cout << endl;
	}
}