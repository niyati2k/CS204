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
int n,m;
int bfs(int i,int j,vector<vector<int>> & vis,vector<vector<int>> & grid){
	vis[i][j]=1;
	int ans=1;
    if(i-1>=0){
		if(grid[i][j]==grid[i-1][j]&&!vis[i-1][j]){
			vis[i-1][j]=1;
			ans+=bfs(i-1,j,vis,grid);
		}
	}
	if(j-1>=0){
		if(grid[i][j]==grid[i][j-1]&&!vis[i][j-1]){
			vis[i][j-1]=1;
			ans+=bfs(i,j-1,vis,grid);
		}
	}
	if(i+1<n){
		if(grid[i][j]==grid[i+1][j]&&!vis[i+1][j]){
			vis[i+1][j]=1;
			ans+=bfs(i+1,j,vis,grid);
		}
	}
	if(j+1<m){
		if(grid[i][j]==grid[i][j+1]&&!vis[i][j+1]){
			vis[i][j+1]=1;
			ans+=bfs(i,j+1,vis,grid);
		}
	}
	return ans;
}
int main(){
	fastio;
	int c;
	cin>>m>>n>>c;
	int x;
	vector<vector<int>> grid(n);
	forl(i,0,m){
		forl(j,0,n){
			cin>>x;
			grid[i].pb(x);
		}
	}
	vector<vector<int>> vis(n);
	forl(i,0,m){
		forl(j,0,n){
			vis[i].pb(0);
		}
	}
	int mx=0,mxc=-1,ans=0;
	forl(i,0,m){
		forl(j,0,n){
			ans=0;
			if(!vis[i][j])
			    ans=bfs(i,j,vis,grid);
			if(ans>mx){
				mx=ans;
				mxc=grid[i][j];
			}
		}
	}
	cout<<mx<<" "<<mxc;
	return 0;
}