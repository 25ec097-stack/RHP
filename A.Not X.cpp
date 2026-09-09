#include <iostream>
using namespace std;

void solve(){
	int x;
	cin>>x;
	if(x==1){
		cout<<2<<endl;
	}
	else if(x==2){
		cout<<3<<endl;
	}
	else{
		cout<<1<<endl;
	}
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc=1;
	//cin>>tc;
	while(tc--){
		solve();
	}
}
