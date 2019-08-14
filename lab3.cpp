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
//------------------------------------------------------------
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		string s;
		stack<char> st;
		cin>>s;
		int check=1;
		forl(i,0,s.si){
			if(s[i]=='('||s[i]=='{'||s[i]=='['||s[i]=='<'){
				st.push(s[i]);
			}
			else if(s[i]=='|'){
				char x='a';
				if(!st.emp) x=st.top();
				if(x=='|'){
					st.pop();
				}
				else{
					st.push(s[i]);
				}
			}
			else{
				if(st.emp){
					//cout<<i<<endl;
					cout<<"NO"<<endl;
					check=0;
					break;
				}
				else{
					char x=st.top();
					//cout<<x;
					if(s[i]==')'&&x=='(') st.pop();
					else if(s[i]=='}'&&x=='{') st.pop();
					else if(s[i]=='>'&&x=='<') st.pop();
					else if(s[i]==']'&&x=='[') st.pop();
					else{
						cout<<"NO"<<endl;
						check=0;
						break;
					}
				}
			}
			if(check==0) break;
		}
		if(check){
			if(st.emp) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}