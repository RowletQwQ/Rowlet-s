#include <iostream>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	long int ai,x,t,ans=0;
	int n;
	scanf("%lld%lld%lld",&n,&x,&ai);
	for(int i=1;i<n;i++){
		t=ai;
		scanf("%d",&ai);
		if(t+ai>x){
			ans+=t+ai-x;
			ai-=t+ai-x;
			if(ai<0)ai=0;
		}
	}
	printf("%lld",ans);
	return 0;
}
