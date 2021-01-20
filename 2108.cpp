#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stack>
 
using namespace std;
 
//sort ���� 
bool comp(const pair<int, int> &p1,const pair<int, int> &p2){
    
    if(p1.second == p2.second){     //�󵵼��� ������ 
        return p1.first < p2.first; //����(key)������ ������ 
    }
    return p1.second > p2.second;    //�ٸ��� �󵵼��� ū�� ������ 
    
}
 
int main(void){
    //�Է� 1
    int n;
    cin >> n;
    
    vector<int> v;
    int    key;     
    double sum=0;    //�����տ� 
    
    //�Է� 2    
    for(int i=0; i<n ;i++){
        cin >> key;        
        v.push_back(key);
        
        sum += key;
    }
    
    //������������ ����. 
    sort(v.begin(), v.end());    
    
    //������ ���. 
    //�����Լ��� �̿��Ͽ� �ݿø�.
    cout <<  (int)floor( (sum / n) + 0.5) << endl;
    
    
    //�߾Ӱ�. 
    cout << v[n/2] << endl;
    
    
    //�ֺ�. 
    vector<pair<int,int> > st;            //key �� �󵵼��� ������ pair�� vector. 
    vector<int>::size_type i;
    
    for(i=0; i<v.size(); i++){
        if(st.empty()){
            st.push_back(pair<int,int>(v[i],1));
            continue;
        } 
 
        if(st.back().first == v[i]){        //������ �ִٸ� 
        
            pair<int, int> tmp = st.back();    
            tmp.second++;                    //�ϳ� ���� 
            st.pop_back();                    //������ ���ְ� 
            st.push_back(tmp);                //���ο� �� �ٽ� ���� 
        
        }else{ 
            st.push_back(pair<int,int>(v[i],1));    
        }
    }
    
 
    //�󵵼��� ����, ����(key)�� ���� ������ ���� 
    sort(st.begin(), st.end(), comp); 
    
    if(st[0].second == st[1].second){
        cout << st[1].first << endl;
    }else{
        cout << st[0].first << endl;
    }
    
    
    //����.
    cout << v.back() - v.front() << endl;
    
    
    return 0;    
}
