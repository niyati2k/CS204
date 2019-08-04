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
//------------------------------------------------------------
string addition(string a, string b){
	if (a.si<b.si) swap(a,b);
	reverse(a.beg,a.en);
	reverse(b.beg,b.en);
	int n1=a.si,n2=b.si;
	int carry = 0;
	string ans="";
    forl(i,0,n2){
        int sum = ((a[i]-'0')+(b[i]-'0')+carry); 
        ans.pb(sum%10 + '0');
        carry = sum/10; 
    }
    forl(i,n2,n1) 
    {   int sum = (( a[i]-'0')+carry); 
        ans.pb(sum%10 + '0'); 
        carry = sum/10; 
    } 
    if (carry) ans.pb(carry+'0'); 
    reverse(ans.beg,ans.en); 
  
    return ans; 
}

int main(){
	fastio;
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        cout<<addition(a,b)<<endl;
    }
	return 0;
}