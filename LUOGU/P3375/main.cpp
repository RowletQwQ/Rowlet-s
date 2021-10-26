#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[1000005],b[1000005];
int kmp[1000005],a1,b1;


int main(int argc, char** argv) {
	kmp[1]=0;
	scanf("%s%s",a+1,b+1);
	a1=strlen(a+1);
	b1=strlen(b+1);
	for(int i=2,j=0;i<=b1;i++){
		while(j&&b[i]!=b[j+1])j=kmp[j];
		if(b[i]==b[j+1])j++;
		kmp[i]=j;		
	}
	for(int i=1,j=0;i<=a1;i++){
		while(j>0&&b[j+1]!=a[i])j=kmp[j];
		if(b[j+1]==a[i])j++;
		if(j==b1){
			printf("%d\n",i-b1+1);
			j=kmp[j];
		}
	}
	for(int i=1;i<=b1;i++)printf("%d ",kmp[i]);
	return 0;
}
