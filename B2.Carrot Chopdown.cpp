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
	int N,M;
	cin>>N>>M;
	vector<int> cnt(M+1,0), psum(M+1,0);
	for(int ctr=1;ctr<=N;ctr++){
		int curr;
		cin>>curr;
		cnt[curr]++;
	}
	for(int cl=1;cl<=M;cl++){
		psum[cl]=psum[cl-1]+cnt[cl];
	}
	vector<ll> ans(M+1,0);
	for(int cut=1;cut<=min(M,18);cut++){
		ll maxc = 0;
		for(int x=1;x<=M;x++){
			ll currc = 0;
			for(int mul=1;mul*x<=M;mul++){ //mul is the quocient
				int lt = mul*x;
				int rt = lt+x-1;
				currc += min(1LL*mul,(1LL<<cut)-1)*(psum[min(rt,M)]-psum[lt-1]);
			}
			if((1LL<<cut)*x<=M){
				currc += cnt[(1LL<<cut)*x];
			}
			maxc = max(maxc,currc);
		}
		ans[cut] = maxc;
	}
	for(int cut=1;cut<=M;cut++){
		cout << ans[min(cut,18)]<<(cut==M?"\n":" ");
	}	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);int tc;
	cin>>tc;
	while(tc--){
		solve();
	}
}
