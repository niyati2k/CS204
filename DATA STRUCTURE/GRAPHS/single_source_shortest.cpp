/* Single source shortest pair 
****BELLMAN-FORD ALGO****
****DP :  It first calculates the shortest distances which have at-most one edge in the path.
Then, it calculates shortest paths with at-most 2 edges, and so on.
After the i-th iteration of outer loop, the shortest paths with at most i edges are calculated.
There can be maximum |V| – 1 edges in any simple path, that is why the outer loop runs |v| – 1 times.

Input: Graph and a source vertex src
Output: Shortest distance to all vertices from src.
If there is a negative weight cycle, then shortest distances are not calculated,
negative weight cycle is reported.
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
 
int main(){
	fastio;
	int n,m;
	cin>>n>>m;
	vector<pair<pll,ll>>v;
	int x,y,w;
	forl(i,0,m){
		cin>>x>>y>>w;
		v.pb({{x,y},w});
	}
	int src;
	cin>>src;
	int arr[n];
	forl(i,0,n){
		if(i==src) arr[i]=0;
		else arr[i]=INT_MAX;
	}
	forl(i,0,n-1){
		forl(j,0,m){
			x=v[j].fi.fi;
			y=v[j].fi.se;
			w=v[j].se;
			arr[y]=min(arr[y],arr[x]+w);
		}
	}
	forl(i,0,m){
		x=v[i].fi.fi;
		y=v[i].fi.se;
		w=v[i].se;
		if(arr[y]>arr[x]+w){ cout<<"Negetive cycle"; return 0;}
	}
	forl(i,0,n){
		cout<<"Min distance from "<<src<<" to "<<i<<" is: "<<arr[i]<<endl;
	}
	return 0;
}
