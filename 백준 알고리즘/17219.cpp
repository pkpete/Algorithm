#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL);
	cin.tie(NULL);
	int num_of_site, num_of_sites_to_find;
	cin >> num_of_site >> num_of_sites_to_find;
	map<string, string> m;
	string site, pw;
	for(int i = 0; i < num_of_site; i++){
		cin >> site >> pw;
		m.insert(make_pair(site,pw));
	}
	for(int i = 0; i < num_of_sites_to_find; i++){
		cin >> site;
		cout << m.find(site)->second << "\n";
	}
}