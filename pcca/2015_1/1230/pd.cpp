#include <bits/stdc++.h>
using namespace std;

vector<int> mat[510],s;
int d[510][26],srt[510][26],ans[510][2],n,sid[510],a[510],tmp,m,k,cnt,BIG;
char o[500];
int idx;
bool comp(int a,int b){
    for(int i=0;i<k;++i){
        if(mat[idx][(a-i+k)%k]!=mat[idx][(b-i+k)%k])return mat[idx][(a-i+k)%k]<mat[idx][(b-i+k)%k];
    }
    return 0;
}
int cti(char c){
    if(isdigit(c)) return c - '0';
    return c - 'H' + 10;
}
char p(int x){
    if(0 <= x && x <= 9)
        return x + '0';
    return x - 10 + 'H';
}
void Solve(){
    tmp=0;m=1;k=0;cnt=0;
    scanf("%s", o);
    int n;
	scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<510;++i)mat[i].clear();
    for(int i=0;o[i]!='\0';++i){
        d[0][cti(o[i])]++;
        mat[i].push_back(cti(o[i]));
    }
    memset(sid,0,sizeof(sid));
    for(int i=1;i<k;++i){
        tmp=0,cnt=0;
        for(int j=0;j<m;++j){
            for(int l=0;l<14;++l){
                if(d[j][l])srt[j][l]=cnt++;
                while(d[j][l]){
                    mat[tmp].push_back(l);
                    tmp++;
                    d[j][l]--;
                }
            }
        }
        if(i!=k-1)
            for(int j=0;j<n*k;++j){
				sid[j]=srt[sid[j]][mat[j][mat[j].size()-2]];
                d[sid[j]][mat[j][mat[j].size()-1]]++;
			}
        m=cnt;
    }
	
	for(int l=0;l<n;++l){
		int i=a[l]-1;
		for(int j=1;j<(int)mat[i].size();++j){
			printf("%c",p(mat[i][j]));
		}
		printf("%c",p(mat[i][0]));
	}
	printf("\n");
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        Solve();
    }
    return 0;
}
