#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
//#define mp make_pair
#define fi first
#define se second
#define si size()
#define bk back()
#define popb pop_back()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define emp empty()
#define beg begin()
#define en end()
#define pll pair < long long, long long >
#define pli pair <long long, int>
#define pil pair <int, long long>
#define pii pair < int, int>
#define forl(i,a,n) for(int i=a;i<n;i++)
#define rfor(i,n,a) for(int i=n;i>=a;i--)
#define fore(i,a,n) for(int i=a;i<=n;i++)
ll mod=1e9+7;
ll power(ll num,ll r){
    if(r==0) return 1;
    if(r==1) return num%mod;
    ll ans=power(num,r/2)%mod;
    if(r%2==0) {
        return (ans*ans)%mod;
    } return (((ans*ans)%mod)*num)%mod;
}
ll modinv(ll num){
    return power(num,mod-2);
}
//------------------------------------------------------------
map<pair<ll,ll>,ll>mp;
int bfs(int x, int y, int vis[] ){
	int ans=1;
	if(mp.find({x-1,y})!=mp.end()&&!vis[mp[{x-1,y}]]){
		vis[mp[{x-1,y}]]=1;
		ans+=bfs(x-1,y,vis);
	}
	if(mp.find({x+1,y})!=mp.end()&&!vis[mp[{x+1,y}]]){
		vis[mp[{x+1,y}]]=1;
		ans+=bfs(x+1,y,vis);
	}
	if(mp.find({x,y-1})!=mp.end()&&!vis[mp[{x,y-1}]]){
		vis[mp[{x,y-1}]]=1;
		ans+=bfs(x,y-1,vis);
	}
	if(mp.find({x,y+1})!=mp.end()&&!vis[mp[{x,y+1}]]){
		vis[mp[{x,y+1}]]=1;
		ans+=bfs(x,y+1,vis);
	}
	return ans;
}
int main(){
	fastio;
	int m,n;
	cin>>m>>n;
	int k;
	cin>>k;
	forl(i,0,k){
		int x,y;
		cin>>x>>y;
		mp[{x,y}]=i;
	}
	int vis[k]={0};
	int j=0;
	int ans=0;
	for(auto i:mp){
		vis[j]=1;
		ans=max(ans,bfs(i.fi.fi,i.fi.se,vis));
		j++;
	}
	cout<<ans;
	return 0;
}