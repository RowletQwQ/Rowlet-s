#include <iostream>
#include <map>
#include <queue>
#include <string>
#define INTMAX 2147483647
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n,book[505][505],ans,cnt=2;
bool path[505];
queue<int> q;
int min(int x,int y){
	return (x>y)?y:x;
}
map <string,int> NtoP;
void dfs(int x){
	if(x==1){
		int mins=INTMAX;
		int tx=q.front();q.pop();
		int ty=q.front();
		q.push(tx);
		do{
			mins=min(mins,book[tx][ty]);
			tx=ty;
			q.pop();
			ty=q.front();
		}while(ty);
		tx=ty;q.pop();
		
		ty=q.front();
		do{
			q.push(tx);
			q.pop();
			book[tx][ty]-=mins;
			tx=ty;
			ty=q.front();
		}while(ty);
		ans+=mins;
		return;
	}
	path[x]=true;
	q.push(x);
	for(int i=0;i<cnt;i++){
		if(!book[x][i]&&!path[i])dfs(i);
	}
	path[x]=false;
	q.pop();
}
int main(int argc, char** argv) {
	string source,dest;
	cin>>source>>dest>>n;
	NtoP[source]=0;
	NtoP[dest]=1;
	int cap,xi,yi;
	for(int i=1;i<=n;i++){
		cin>>source>>dest>>cap;
		if(NtoP.find(source)==NtoP.end())NtoP[source]=cnt++;
		if(NtoP.find(dest)==NtoP.end())NtoP[dest]=cnt++;
		book[NtoP[source]][NtoP[dest]]=cap;
	}
	dfs(0);
	printf("%d",ans);
	return 0;
}
