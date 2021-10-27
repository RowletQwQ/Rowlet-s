#include <stdio.h>
#include <stdlib.h>
int a[10];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int ans=0,t=0;
	for(int i=0;i<10;i++){
		scanf("%d",&t);
		if(i==0){
			ans=t;
		}else{
			if(a[i]>ans)ans=t;
		}
	}
	printf("%d",t);
	return 0;
}
