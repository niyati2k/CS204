/* 
All pair shortest path
***Floyd Warshall***
***DP
Considering all n vertices to be an intermediate vertex once.
So, finding the shortest paths in whole grid considering that kth vertex to be coming in between.
Do this for all vertices 1-n, and each time update the whole grid

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
	int n,m;
	cin>>n>>m;
	ll graph [n][n];
	forl(i,0,n){
		forl(j,0,n){
			graph[i][j]=INT_MAX;
			graph[i][i]=0;
			graph[j][j]=0;
		}
	}
	ll x,y,w;
	forl(i,0,m){
		cin>>x>>y>>w;
		graph[x][y]=w;
	}
	forl(k,0,n){
		forl(i,0,n){
			forl(j,0,n){
				graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
			}
		}
	}
	forl(i,0,n){
		forl(j,0,n){
			if(graph[i][j]==INT_MAX) cout<<"INF ";
			else cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
/* 
Input :-
4 4
0 1 5
0 3 10
1 2 3
2 3 1
Output :-
0 5 8 9 
INF 0 3 4 
INF INF 0 1 
INF INF INF 0 
*/
