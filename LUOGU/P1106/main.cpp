#include <iostream>
#include <cstdio>
#include <string>
using namespace std; 
int num[330],ans[330],n;
void findN(int len,int k,int s,int step){
	if(len==0)return;
	int l=10,t=0;
	for(int i=s;i<=n-k+1;i++){
		if(num[i]<l){
			l=num[i];
			t=i;
		}
	}
	ans[step+1]=l;
	findN(len-1,k-1,t+1,step+1); 
}
int main(int argc, char** argv) {
	string in,anst;
	int k,size,zero=0;
	cin>>in;
	scanf("%d",&k);
	n=in.length();
	
	for(int i=1,j=1;i<=n;i++,j++){
		num[j]=in[i-1]-'0';
	}
	size=n-k;
	int l=10,t=0;
	for(int i=1;i<=n-size+1;i++){
		if(num[i]<l){
			l=num[i];
			t=i;
		}
		if(l==0)break;
	}
	ans[1]=l;
	char ti;
	findN(n-t,size-1,t+1,1);
	bool isF=false;
	for(int i=1;i<=n-k;i++){
		if(ans[i]!=0)isF=true;
		if(isF||size==1)printf("%d",ans[i]);
	}
	return 0;
}
