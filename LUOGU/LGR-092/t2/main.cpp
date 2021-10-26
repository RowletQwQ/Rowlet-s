#include <iostream>
#include <cstdio>
int tuan[500005][2],n,top,sum,t,cnt;
using namespace std; 
void readi(int &x){
	char c;
	for(c=getc(stdin);c<'0'||c>'9';c=getc(stdin));
	for(x=0;c<='9'&&c>='0';c=getc(stdin))x=(x<<3)+(x<<1)+c-'0';
	return;
}
int main(int argc, char** argv) {
	readi(n);
	for(int i=1;i<=n;i++){
		readi(t);
		if(t==1){
			top++;
			readi(tuan[top][0]);readi(tuan[top][1]);
			
		}else{
			sum=0;
			readi(cnt);
			while(cnt){
				if(cnt>=tuan[top][1]-tuan[top][0]+1){
					sum+=((tuan[top][1]-tuan[top][0]+1)*((tuan[top][0]+tuan[top][1])))>>1;
					cnt-=tuan[top][1]-tuan[top][0]+1;
					top--;
				}else{
					sum+=(cnt*((tuan[top][1]+(tuan[top][1]-cnt+1))))>>1;
					tuan[top][1]-=cnt;
					cnt=0;
				}
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}
