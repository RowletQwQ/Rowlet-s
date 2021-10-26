#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int T,N;
float ans = 0.00;
struct iy{
	int m,v;
}s[105];
bool cmp(iy x,iy y){
	return x.v*y.m>x.m*y.v;
}
void addup(){
	for(int i=0;i<N;i++){
		if(s[i].m<=T){
			T-=s[i].m;
			ans+=s[i].v;
		}else{
			float single = 0.00;
			single= 1.0*s[i].v/s[i].m;
			ans+=single*T*1.0;
			break;
		}
	}
}
int main(int argc, char** argv) {
	scanf("%d%d",&N,&T);
	for(int i = 0;i<N;i++)
		scanf("%d%d",&s[i].m,&s[i].v);
	sort(s,s+N,cmp);
	addup();
	printf("%.2lf",ans);
	return 0;
}
