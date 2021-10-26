#include <iostream>
#include <cstdio>
using namespace std;
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n,nums[1000005],f[1000005][3];
int min(int x,int y){
	return (x>y)?y:x;
}
void readi(int &i){
	char c;
	bool is=false;
	for(c=getc(stdin);c<'0'||c>'9';c=getc(stdin))if(c=='-')is=true;
	for(i=0;c<='9'&&c>='0';c=getc(stdin))i=(i<<3)+(i<<1)+c-'0';
	if(is)i=-i;
}
int main(int argc, char** argv) {
	readi(n);
	for(int i=1;i<=n;i++){
		readi(nums[i]);
	}
	memset(f,-1,sizeof(f));
	f[1][nums[1]+1]=0;
	for(int i=2;i<=n;i++){
		int t=nums[i]+1;
		if(t==1){
			if(f[i-1][0]!=-1){
				f[i][1]=f[i-1][0];
				f[i][0]=f[i-1][0]+1;	
			}
			if(f[i-1][1]!=-1){
				if(f[i][1]!=-1){
					f[i][1]=min(f[i][1],f[i-1][1]);
				}
			}
			if(f[i-1][2]!=-1)f[i][2]=f[i-1][2]+1;
		}else if(t==0){
			if(f[i-1][0]!=-1)f[i][0]=f[i-1][t];
			if(f[i-1][2]!=-1)f[i][2]=f[i-1][2]+2;
		}else{
			if(f[i-1][0]!=-1){
				f[i][1]=f[i-1][0]+1;
				f[i][0]=f[i-1][0]+2;
				f[i][2]=f[i-1][0];
			}
			if(f[i-1][1]!=-1){
				if(f[i][2]==-1)f[i][2]=f[i-1][1];
				else f[i][2]=min(f[i][2],f[i-1][1]);	
			}
			if(f[i-1][2]!=-1){
				if(f[i][2]==-1)f[i][2]=f[i-1][2];
				else f[i][2]=min(f[i][2],f[i-1][2]);
			}
		}
	}
	int ans=(1<<31)-1;
	int temp=ans;
	for(int i=0;i<=2;i++){
		if(f[n][i]>=0)ans=min(f[n][i],ans);
	}
	if(ans==temp){
		printf("BRAK");
	}else{
		printf("%d",ans);
	}
/*	for(int i=1;i<=n;i++){
		for(int j=0;j<=2;j++){
			printf("%d ",f[i][j]);
		}
		printf("\n");
	}*/
	return 0;
}
