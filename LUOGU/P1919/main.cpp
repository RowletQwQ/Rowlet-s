#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
struct BigNums{
	int val[100005],cnt;
	void output(){
		bool isFirst=true;
		for(int i=cnt;i>=1;i--){
			if(isFirst&&val[i]==0)continue;
			isFirst=false;
			printf("%d",val[i]);
		}
		printf("\n");
	}
	bool addZero(int n){
		if(n<=cnt)return false;
		n-=cnt;
		for(int i=1;i<=n;i++){
			val[++cnt]=0;
		}
	}
	void readIn(){
		char c;
		for(c=getc(stdin);c<'0'||c>'9';c=getc(stdin));
		for(;c>='0'&&c<='9';c=getc(stdin))val[++cnt]=c-'0';
		int l=1,r=cnt;
		while(l<r){
			int t=val[l];
			val[l]=val[r];
			val[r]=t;
			l++;
			r--;
		}
	}
	void push_back(int n){
		val[++cnt]=n;
	}
}n1,n2,n3;

int cmp(BigNums x,BigNums y){
	if(x.cnt>y.cnt)return 1;
	if(x.cnt<y.cnt)return -1;
	for(int i=x.cnt;i>=1;i--){
		if(x.val[i]>y.val[i])return 1;
		if(y.val[i]>x.val[i])return -1;
	}
	return 0;	
}
BigNums add(BigNums a,BigNums b){
	BigNums c;
	if(b.addZero(a.cnt))a.addZero(b.cnt);
	int left=0;
	for(int i=1;i<=a.cnt;i++){
		c.push_back((a.val[i]+b.val[i]+left)%10);
		left=(a.val[i]+b.val[i]+left)/10;
	}
	if(left)c.push_back(left);
	return c;
}
int main(int argc, char** argv) {
	//BigNums n1,n2,n3;
	//int n;
	//cin>>n;
	n1.readIn();
	n2.readIn();
	//n1.output();
	//n2.output();
	//n3 = add(n1,n2);
	//n3.output();
	return 0;
}
