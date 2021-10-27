#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int t,T,n,m;
int main(int argc, char** argv) {
		scanf("%d",&t);
		scanf("%d",&T);
		for(int i=1;i<=T;i++){
			scanf("%d%d",&n,&m);
			if(m<2&&n>1){
				printf("NO\n");
				continue;
			}
			printf("YES\n");
			for(int j=1;j<=n;j++){
				for(int k=1;k<=m;k++){
					if(k==1){
						printf("%d ",100-j+1);
					}else{
						printf("%d ",j);
					}
						
				}
				printf("\n");
			}
		}
	return 0;
}
