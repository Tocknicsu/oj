#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct s{
	int x,d;
	s(){}
	s(int x_,int d_){x=x_;d=d_;}
}p[100010];
bool comp (s const &A,s const &B){
	return A.x<B.x;
}
int d[100010],a[100010];
deque<s> deq;
int n,m;
void solve(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%d %d",&p[i].x,&p[i].d);
	}
	sort(p,p+n,comp);
	for(int j=0;j<m;++j){
		scanf("%d",&a[j]);
		d[j]=1000000000;
	}
	sort(a,a+m);
	deq.clear();
	for(int i=0,j=0;i<n||j<m;){
		if(i!=n&&(j==m||p[i].x<=a[j])){
			while(!deq.empty()&&deq.back().d<=p[i].x+p[i].d)deq.pop_back();
			deq.push_back(s(p[i].x,p[i].x+p[i].d));
			i++;
		}else{ 
			while(!deq.empty()&&deq.back().d<a[j])deq.pop_back();
			if(!deq.empty()){
				d[j]=min(d[j],a[j]-deq.back().x);
			}
			j++;
		}
	}
	deq.clear();
	for(int i=n-1,j=m-1;i>=0||j>=0;){
		if(i!=-1&&(j==-1||p[i].x>=a[j])){
			while(!deq.empty()&&deq.back().d>=p[i].x-p[i].d)deq.pop_back();
			deq.push_back(s(p[i].x,p[i].x-p[i].d));
			i--;
		}else{ 
			while(!deq.empty()&&deq.back().d>a[j])deq.pop_back();
			if(!deq.empty()){
				d[j]=min(d[j],deq.back().x-a[j]);
			}
			j--;
		}
		
	}
	long long ans=0;
	for(int i=0;i<m;++i)ans+=d[i];
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)solve();


}
