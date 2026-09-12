#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <iomanip>
#define ll long long int
#define INF 2e9
using namespace std;

struct bus{
	ll lt,rt;
	double time;
	friend bool operator<(bus a,bus b){
		if(a.lt != b.lt){
			return a.lt<b.lt;
		}
		return a.time<b.time;
	}
}
buses[200000];
void solve(){
	ll B,P,L,Bspeed,Pspeed;
	cin>>B>>P>>L>>Bspeed>>Pspeed;
	for(int i=0;i<B;i++){
		cin>>buses[i].lt>>buses[i].rt;
		buses[i].time =(double) (buses[i].rt - buses[i].lt)/(double)Bspeed+(double)(L-buses[i].rt)/(double)Pspeed;
	}
	sort(buses,buses+B);
	for(int i=0;i<B-1;i++){
		buses[i+1].time = min(buses[i+1].time,buses[i].time);
	}
	double ans;
	int pos;
	for(int ctr=1;ctr<=P;ctr++){
		cin>>pos;
		ans = (double)(L-pos)/(double)Pspeed;
		int bl = 0,br = B;
		bool found = false;
		while(bl<br){
			int mid = (bl+br)/2;
			if(buses[mid].lt<=pos){
				found = true;
				if(bl==mid)
					break;
				bl = mid;
			}
			else{
				br = mid;
			}
		}
		if(found)
			ans = min(ans,buses[bl].time);
		cout<<ans<<endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc=1;
	cout<<setprecision(11);
	while(tc--){
		solve();
	}
}
