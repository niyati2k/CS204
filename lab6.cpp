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
	int n,q;
	cin>>n>>q;
	ll arr[n+5]={0};
	ll mx=INT_MIN,id=-1;
	while(q--){
		int t;
		cin>>t;
		if(t==1){
			int a;
			ll b;
			cin>>a>>b;
			arr[a]+=b;
			if(arr[a]>mx){
				mx=arr[a];
				id=a;
			}
		}
		else{
			if(id==-1) cout<<"No data available."<<endl;
			else cout<<id<<endl;
		}
	}
	return 0;
}