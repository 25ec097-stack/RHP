#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <set>
#define ll long long int
#define INF 2e9
using namespace std;

void solve(){ 
	int x,y;
	cin>>x>>y;
	int sum = x+y;
	int rx = 0,ry = 0;
	for(int sh=30;sh>=0;sh--){
		if((sum&(1<<sh))!=0){
			if((rx|(1<<sh))<=x){
				rx = rx|(1<<sh);
			}
			else{
				ry = ry|(1<<sh);
			}
		}
	}
	cout<<sum<<" "<<x-rx<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin>>tc;
	while(tc--){
		solve();
	}
}
