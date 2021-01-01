#include <iostream>
using namespace std;

struct ppl{
	int height, weight;
	int count;
};
ppl arr[51];
int main(){
	int n;
	cin >> n;
	for(int i = 0 ; i < n; i++){
		cin >> arr[i].weight >> arr[i].height;
		arr[i].count = 1;
	}
	for(int i = 0 ; i < n; i++){
		for(int j = 0 ; j < n; j++){
			if(i != j){
				if(arr[i].height > arr[j].height && 
					arr[i].weight > arr[j].weight)
					arr[j].count++;
			}
		}
	}
	for(int i = 0 ; i < n; i++){
		cout << arr[i].count << " ";
	}
}