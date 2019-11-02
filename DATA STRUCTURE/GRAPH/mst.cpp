/*
Minimum Spanning Tree
Question: 
Given a Graph, with weighted edges, find the total cost of the minimal spanning tree
*/
// ****KRUSKAL'S ALGO****
/*
1. Sort all the edges in non-decreasing order of their weight.
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far.
If cycle is not formed, include this edge. Else, discard it.
3. Repeat step#2 until there are (V-1) edges in the spanning tree.
*/
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
int findset(ll arr[], ll x){
	if(x!=arr[x]){
		arr[x]=findset(arr,arr[x]);
	}
	return arr[x];
}
void uni(ll arr[],ll ranks[],int a,int b){
	int ra=findset(arr,a);
	int rb=findset(arr,b);
	if(ra!=rb){
		if(ranks[ra]<ranks[rb]) swap(ra,rb);
		arr[rb]=ra;
		if(ranks[ra]==ranks[rb]){
			ranks[ra]++;
		}
	}
}
int main(){
	fastio;
	int n,m;
	cin>>n>>m;
	vector<pair<ll,pll>>v; //to save edges and weights
	int x,y,w;
	forl(i,0,m){
		cin>>x>>y>>w;
		v.pb({w,{x,y}});
	}
	sort(v.beg,v.en); //(greedy, so take min weight)
	ll arr[n+1],ranks[n+1];
	ll ans=0; //store min weight tree
	forl(i,0,n+1){
		arr[i]=i; //make-set
		ranks[i]=0;
	}
	forl(i,0,v.si){
		int rx=findset(arr,v[i].se.fi),ry=findset(arr,v[i].se.se);
		if(rx!=ry){ //only add edge if in different components (no cyle should be made)
			ans+=v[i].fi;
			uni(arr,ranks,v[i].se.fi,v[i].se.se);
		}
	}
	cout<<ans;
	return 0;
}
