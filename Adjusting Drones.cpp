#include<iostream>
#include<vector>
using namespace std;
#define ll long long int
void solve(){
	int n,k,curr;
	cin>>n>>k;
	vector<int> cnt(n+n+n+1,0);
	for(int i=0;i<n;i++){
		cin>>curr;
		cnt[curr]++;
	}
	int ans=0;
	for(int val=1;val<=n+n;val++){
		int curr=val;
		while(cnt[curr]>k){
			cnt[curr+1]+=cnt[curr]-1;
			cnt[curr]=1;
			curr++;
		}
		ans=max(ans,curr-val);
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc=1;
	cin>>tc;
	while(tc--)
	solve();
}
