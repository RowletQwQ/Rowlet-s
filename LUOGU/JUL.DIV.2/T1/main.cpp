#include <iostream>
#include <cstdio>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node{
	int a[5],posZ;
	int HaveZero(){
		int cnt=0;
		for(int i=1;i<=4;i++)if(this->a[i]==0)cnt++;
		return cnt;
	}
	void PosZero(){
		for(int i=1;i<=4;i++){
			if(this->a[i]==0)posZ=i;
		}
	}
	void print(){
		for(int i=1;i<=4;i++)printf("%d ",a[i]);
		printf("\n");
	}
	
};
int n=1,aZ,bfsn=0;
int step[5][2]={{0,0},{2,3},{1,4},{1,4},{2,3}};
node a,b,book[30],bfs[50];
bool isEqual(node &x,node &y){
	for(int i=1;i<=4;i++){
		if(x.a[i]!=y.a[i])return false;
	}
	return true;
}
bool findB(node &x){
	for(int i=1;i<=n;i++){
		if(isEqual(book[i],x))return true;	
	}
	return false;
}
bool Bfs(int s){
	if(isEqual(bfs[s],b))return true;
	if(findB(bfs[s]))return false;
	bfs[s].PosZero();
	book[n]=bfs[s];
	n++;
	int p=bfs[s].posZ;
	bfsn++;
	bfs[bfsn]=bfs[s];
	swap(bfs[bfsn].a[p],bfs[bfsn].a[step[p][0]]);
	bool aB = Bfs(bfsn);
	if(aB)return aB;
	bfsn++;
	bfs[bfsn]=bfs[s];
	swap(bfs[bfsn].a[p],bfs[bfsn].a[step[p][1]]);
	aB = Bfs(bfsn);
	if(aB)return aB;
	return false;
}
int main(int argc, char** argv) {
	for(int i=1;i<=4;i++)scanf("%d",&a.a[i]);
	for(int i=1;i<=4;i++)scanf("%d",&b.a[i]);
	aZ=a.HaveZero();
	if(aZ>=2){
		printf("Yes");
	}else if(aZ==0){
		if(isEqual(a,b))printf("Yes");
		else printf("No");
	}else{
		a.PosZero();
		bfs[0]=a;
		if(Bfs(0))printf("Yes");
		else printf("No"); 
	}
	return 0;
}
