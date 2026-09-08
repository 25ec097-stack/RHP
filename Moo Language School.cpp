#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <set>
#define ll long long int
using namespace std;
   
void solve(){
	int N,K;
	cin>>N>>K;
	string s;
	cin>>s;
	int F=N/K;
	vector<bool> own(F,false);
	for(unsigned int i=0;i<s.size();i++){
		if(s[i]=='0'){
			int farmidx = i/K;
			own[farmidx] = true;
		}
	}
	int count = 0;
	for(int f=0;f<F;f++){
		if(!own[f])
			count++;
	}
	cout<<count<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);int tc;
	cin>>tc;
	while(tc--){
		solve();
	}
}
