#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> music;
int n;
int count(int s){
	int cnt = 1, sum = 0;
	for(int i = 0; i < n; i++){
		if(sum + music[i] >= s){
			sum = music[i];
			cnt++;
		}
		else sum += music[i];
	}
	return cnt;
}
int main(){
	int m, sum=0;
	cin >> n >> m;
	music = vector<int> (n);
	for(int i = 0; i < n; i++){
		cin >> music[i];
		sum += music[i];
	}
	sort(music.begin(), music.end());
	int left = 0, right = sum, mid;
	int answer;
	while(left <= right){
		mid = (left+right)/2;
		if(count(mid) <= m){
			answer = mid;
			right = mid -1;
		}
		else{
			left = mid + 1;
		}
	}
	cout << answer;
}