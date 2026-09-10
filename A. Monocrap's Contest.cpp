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
	int N;
	cin>>N;
	vector<int> arr(N);
	int oc = 0;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		oc += arr[i];
	}
	int zc = N-oc;
	if(zc<2){
		cout<<"-1\n";
		return;
	}
	int ans = 0;
	if(arr[0])
		ans++;
	if(arr[N-1])
		ans++;
	cout<<ans<<endl;
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
