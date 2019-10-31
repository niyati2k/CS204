/*
BFS: 
Question:
Given a 2d grid size nXm of '1's (land) and '0's (water),count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.
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
	int grid[n][m];
	vector<pii>one;
	forl(i,0,n){
		forl(j,0,m){
			cin>>grid[i][j];
			if(grid[i][j]){
				one.pb({i,j});
			}
		}
	}
	int sz=one.si;
	int visited[n][m];
	forl(i,0,n){
		forl(j,0,m){
			visited[i][j]=0;
		}
	}
	//cout<<sz<<endl;
	int ans=0;
	forl(i,0,sz){
		vector<pii> v;
		int x=one[i].fi,y=one[i].se;
		//cout<<x<<y;
		if(visited[x][y]==0){
			ans++;
			v.pb({x,y});
			while(!v.emp){
				pii val=v.bk;
				v.popb;
				int l=val.fi,r=val.se;
				visited[l][r]=1;
				if(l-1>=0&&grid[l-1][r]&&!visited[l-1][r]) v.pb({l-1,r});
				if(l+1<n&&grid[l+1][r]&&!visited[l+1][r]) v.pb({l+1,r});
				if(r-1>=0&&grid[l][r-1]&&!visited[l][r-1]) v.pb({l,r-1});
				if(r+1<m&&grid[l][r+1]&&!visited[l][r+1]) v.pb({l,r+1});
			}
			
		}
	}
	cout<<ans;
	
	return 0;
}
