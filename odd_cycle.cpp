#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
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
 
int main(){
	fastio;
	int n,m,x,y,z;
	cin>>n>>m;
	vector<int> v[n+5],wt[n+5];
	forl(i,0,m){
		cin>>x>>y>>z;
		v[y].pb(x);
		v[x].pb(y);
		if(z%2==0){
			wt[x].pb(0);
			wt[y].pb(0);
		}
		else {
			wt[x].pb(1);
			wt[y].pb(1);
		}
	}
	int c[n+5]={0};
	queue<int>q;
	int curr=1;
	c[1]=1;
	q.push(1); 
	while(!q.empty()){
		int i=q.front();
		q.pop();
		forl(j,0,v[i].si){
			if(wt[i][j]==0) curr=c[i];
			else{
				if(c[i]==1) curr=1;
				else curr=2;
			}
			if(c[v[i][j]]==0) q.push(v[i][j]);
			if(c[v[i][j]]==0||c[v[i][j]]==curr) c[v[i][j]]=curr;
			else {cout<<"YES"; return 0;}
		}
	}
	cout<<"NO";
	return 0;
}