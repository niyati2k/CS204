//Tarjan's algo
// Q 1192. Critical Connections a Network LC
// Low val - Lowest discovery time that can be reached using one back edge
//         - Whenever there's some other early node (based on dis time) that can be
//           visited by subtree of that node

/* Articulation vertex
In DFS tree, a vertex u is articulation point if one of the following
two conditions is true.
1) u is root of DFS tree and it has at least two children.
2) u is not root of DFS tree and it has a child v such that no vertex in subtree
rooted with v has a back edge to one of the ancestors (in DFS tree) of u.

parent disc <=child low
---> parent is articulation point


The condition for an edge (u, v) to be a bridge is, “low[v] > disc[u]”.
u is parent
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

class Solution {
public:
    vector<int> vis,par,desc,low;
    vector<vector<int>> ans;
    int time;
    void dfs(int node,vector<int>v[]){
        forl(i,0,v[node].si){
            if(vis[v[node][i]]==0){
                vis[v[node][i]]=1;
                par[v[node][i]]=node;
                desc[v[node][i]]=time;
                low[v[node][i]]=time;
                time++;
                dfs(v[node][i],v);
                low[node]=min(low[node],low[v[node][i]]);
                if(desc[node]<low[v[node][i]]) {
                    vector<int> pr;
                    pr.pb(node); pr.pb(v[node][i]);
                    ans.pb(pr);
                }
                
            }
            else{
                if(v[node][i]!=par[node]) low[node]=min(low[node],desc[v[node][i]]);
            }
            
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& e) {
        
        vector<int>v[n];
        forl(i,0,e.si){
            v[e[i][0]].pb(e[i][1]);
            v[e[i][1]].pb(e[i][0]);
        }
        vis.assign(n,0);par.assign(n,-1);desc.assign(n,0);low.assign(n,0);
        time=1;
        forl(i,0,n){
            if(!vis[i]){
                vis[i]=1;
                par[i]=-1;
                desc[i]=time;
                low[i]=time;
                time++;
                dfs(i,v);
                
            }
        }
        return ans;
    }
};
