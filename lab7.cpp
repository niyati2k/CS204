#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define si size()
#define bk back()
#define popb pop_back()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define beg begin()
#define en end()
#define forl(i,a,n) for(int i=a;i<n;i++)
#define rfor(i,n,a) for(int i=n;i>=a;i--)
//------------------------------------------------------------
bool cmp(string s, string t){
	string st=s+t,ts=t+s;
	if(st<=ts) return true;
	return false;
}
int main(){
	fastio;
	ll q;
	cin>>q;
	while(q--){
		ll t;
		cin>>t;
		vector<string> inp;
		string s;
		forl(i,0,t){
			cin>>s;
			inp.pb(s);
		}
		sort(inp.beg,inp.en,cmp);
		rfor(i,inp.si-1,0){
			cout<<inp[i];
		}
		cout<<endl;
	}
	return 0;
}
