/*
DFS: 
Question:
You are given a input of employee information,
which includes the employee's unique id, his importance value,
number od sub-ordinates and his direct subordinates' id.

Now given the employee information of a company,and an employee id,
you need to return the total importance value of this employee and all his subordinates.
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

int dfs(vector<int> v[], int visited[],int imp[],int id){
	visited[id]=1;
	int ans=imp[id];
	forl(i,0,v[id].si){
		if(visited[v[id][i]]==0){
			visited[v[id][i]]=1;
			ans+=dfs(v,visited,imp,v[id][i]);
		}	
	}
	return ans;
}
int main(){
	fastio;
	int n;
	cin>>n;
	vector<int> v[n+1];
	int arr[n+1];
	int visited[n+1]={0};
	int x,imp,y,jun;
	forl(i,0,n){
		cin>>x>>imp>>y;
		arr[x]=imp;
		forl(j,0,y){
			cin>>jun;
			v[x].pb(jun);
		}
	}
	cout<<"Enter Employee ID "<<endl;
	int id; cin>>id;
	cout<<"Total imp is " << dfs(v,visited,arr,id);
	
	return 0;
}
