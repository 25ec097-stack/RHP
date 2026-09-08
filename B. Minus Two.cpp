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
	int N;
	cin>>N;
	int odd=0,eoq=0,eeq=0;
	for(int ctr=1;ctr<=N;ctr++){
		int curr;
		cin>>curr;
		if(curr&1) 
			odd++;
		else{
			int q = curr/2;
			if(q&1) eoq++;
			else eeq++;
		}
	}
	cout << max(odd,max(eoq,eeq)) << endl; 
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);int tc;
	cin>>tc;
	while(tc--){
		solve();
	}
}
