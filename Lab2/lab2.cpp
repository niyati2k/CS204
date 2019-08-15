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
struct node{
 	int x;
 	int y;
 	node* next;
};
node * start= NULL;
void AddFirst(int x, int y){
	node* tmp= new node;
	tmp->next=NULL;
	tmp->x=x; tmp->y=y;
	if(start==NULL) start=tmp;
	else {
		tmp->next=start;
		start=tmp;
	}
}
void DelFirst(){
	if(start==NULL) cout<<-1<<endl;
	node *tmp=start;
	start=start->next;
	delete tmp;
	//return 0;
}
void Del(int x,int y){
	node * tmp=start;
	node * prev = NULL;
	while(tmp!=NULL){
		if(tmp->x==x&&tmp->y==y){
			if(tmp==start){
				start=start->next;
			}
			else{
				prev->next=tmp->next;
			}
			delete tmp;
			return ;
		}
		prev=tmp;
		tmp=tmp->next;
	}
	cout<<-1<<endl;
}
void Search(double d){
	node * tmp=start;
	int check=1;
	int count=0;
	while(tmp!=NULL){
		if(sqrt((tmp->x)*(tmp->x)+(tmp->y)*(tmp->y))<=d){
			count++;
			check=0;
		}
		tmp=tmp->next;
	}
	if(check) cout<<-1;
	else cout<<count;
	cout<<endl;
}
void Search(int x,int y){
	//int check=1;
	node * tmp=start;
	while(tmp!=NULL){
		if(tmp->x==x&&tmp->y==y){
			cout<<"True"<<endl;
			return;
		}
		tmp=tmp->next;
	}
	cout<<"False"<<endl;
}
int Length(){
	node *tmp=start;
	int count=0;
	while(tmp!=NULL){
		count++;
		tmp=tmp->next;
	}
	return count;
}
int main(){
	fastio;
	ll t;
	cin>>t;
	while(t--){
		int f;
		cin>>f;
		if(f==1){
			int x,y; 
			cin>>x>>y;
			AddFirst(x,y);
		}
		else if(f==2){
			DelFirst();
		}
		else if(f==3){
			int x,y;
			cin>>x>>y;
			Del(x,y);
		}
		else if(f==4){
			double d;
			cin>>d;
			Search(d);
		}
		else if(f==5){
			int x,y;
			cin>>x>>y;
			Search(x,y);
		}
		
		else if (f==6){
			cout<<Length()<<endl;
		}
		else break;
	}
	return 0;
}
