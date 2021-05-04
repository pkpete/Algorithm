#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[21][21];
int n, answer = 1000000000;
vector<int> team;

void add_score(){
	int team_a = 0, team_b = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <=n; j++){
			if(i!=j && team[i] == team[j]){
				if(team[i] == 1){
					team_a += map[i][j];
				}
				else if(team[i] == 0){
					team_b += map[i][j];
				}
			}
		}
	}
	answer = min(answer, abs(team_a - team_b));
}

void make_team(int index, int cnt){
	if(cnt == n/2){
		add_score();
	}
	else{
		for(int i = index + 1; i <= n; i++){
			team[i] = 1;
			make_team(i, cnt+1);
			team[i] = 0;
		}
	}
}

int main(){
	cin >> n;
	team = vector<int> (n+1,0);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			cin >> map[i][j];
	}

	for(int i = 1; i <= n; i++){
		team[i] = 1;
		make_team(i, 1);
		team[i] = 0;
	}
	cout << answer;
}