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
	ll n,q;
	cin>>n>>q;
	vector<pair<ll,ll>> v;
	vector<ll> ids;
	ll mx=INT_MIN,id=-1;
	forl(i,0,q){
		int t;
		cin>>t;
		ll a=-1,b=-1;
		if(t==1){
			cin>>a>>b;
			ll val=0;
			ids.pb(a);
			v.pb(mp(a,b));
		}
		else{
			v.pb(mp(a,b));
		}
	}
	sort(ids.beg,ids.en);
//	cout<<ids[2]<<ids[3]<<endl;
	ll arr[ids.si]={0};
	forl(i,0,v.si){
		if(v[i].fi==-1){
			if(id==-1) cout<<"No data available."<<endl;
			else cout<<id<<endl;
		}
		else{
		//	vector<pair<ll,ll>>::iterator low;
			//low=lb(ids.beg,ids.en,v[q].fi);
			int pos = lb(ids.beg,ids.en,v[i].fi)-ids.beg;
			arr[pos]+=v[i].se;
			if(arr[pos]>mx){
				mx=arr[pos];
				id=ids[pos];
			}
		}
	}
	return 0;
}