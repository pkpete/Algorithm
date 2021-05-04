#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>> house, chicken;
vector<int> chicken_house;
int map[51][51];
int n, m, answer = 1000000000;

void check_distance(){
	int sum = 0;
	for(int i = 0; i < house.size(); i++){
		int min_dis = 1000000000;
		for(int j = 0; j < chicken_house.size(); j++){
			int x1 = house[i].first, y1 = house[i].second;
			int x2 = chicken[chicken_house[j]].first, y2 = chicken[chicken_house[j]].second;
			int distance = abs(x1 - x2) + abs(y1 - y2);
			min_dis = min(min_dis, distance);
		}
		sum += min_dis;
	}
	if(sum < answer) answer = sum;
}

void choose_chicken(int index, int cnt){
	if(cnt == m){
		check_distance();
	}
	else{
		for(int i = index + 1; i < chicken.size(); i++){
			chicken_house[cnt] = i;
			choose_chicken(i, cnt+1);
			chicken_house[cnt] = 0;
		}
	}
}

void input(){
	cin >> n >> m;
	chicken_house = vector<int> (m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> map[i][j];
			if(map[i][j] == 1){
				house.push_back(make_pair(i,j));
			}
			else if(map[i][j] == 2){
				chicken.push_back(make_pair(i,j));
			}
		}
	}
}

int main(){
	input();
	
	for(int i = 0; i < chicken.size(); i++){
		chicken_house[0] = i;
		choose_chicken(i, 1);
		chicken_house[0] = 0;
	}
	cout << answer;
}