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
bool small(string a,string b){
	int n1=a.si,n2=b.si;
	if(n1<n2) return true;
	if(n1>n2) return false;
	forl(i,0,n1){
		if(a[i]<b[i]) return true;
		else if(a[i]>b[i]) return false;
	}
	return false;
}
string subtraction(string a,string b){
	string ans="";
	//int check=0;
	if(small(a,b)) {swap(a,b);//check=1;
	}
	int n1=a.si,n2=b.si;
	reverse(a.beg,a.en);
	reverse(b.beg,b.en);
	int carry=0;
	forl(i,0,n2){
		int sub=(a[i]-'0')-(b[i]-'0')-carry;
		if (sub < 0){  
			sub+=10; 
            carry = 1; 
        } 
        else carry = 0; 
        ans.pb(sub + '0'); 
	}
	forl(i,n2,n1){
		int sub = ((a[i]-'0') - carry);
        if (sub < 0){ 
        	sub = sub + 10; 
            carry = 1; 
        } 
        else carry = 0;
        ans.pb(sub + '0'); 
    } 
    reverse(ans.beg,ans.en); 
    string final="";
    //if(check) final+="-";
    forl(i,0,ans.si){
    	if(ans[i]!='0'||final.si) final+=ans[i];
    }
    return final; 
}
int main(){
	fastio;
	int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        cout<<subtraction(a,b)<<endl;
    }
	return 0;
}