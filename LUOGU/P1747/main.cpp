#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm> 
using namespace std;
bool book[30][30][2];
int step[12][2]={{-2,-1},{-2,-2},{-1,-2},{1,-2},{2,-2},{2,-1},{2,1},{2,2},{1,2},{-1,2},{-2,2},{-2,1}};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct horse{
	int x,y,val,cnt;
};
queue<horse> q;
horse min(horse x,horse y){
	if(x.cnt>y.cnt)return y;
	return x;
}
int main(int argc, char** argv) {
	horse black,white;
	black.val=1;
	black.cnt=0;
	white.cnt=0;
	white.val=0;
	int x=0,y=0;
	scanf("%d%d%d%d",&black.x,&black.y,&white.x,&white.y);
	x=max(black.x,white.x);
	y=max(black.y,white.y);
	q.push(white);
	q.push(black);
	white.cnt=1e8;
	black.cnt=1e8;
	while(!q.empty()){
		horse t,t1;
		t=q.front();
		q.pop();
		book[t.x][t.y][t.val]=true;
		if(t.x==1&&t.y==1){
			if(t.val==1){
				black=min(black,t);
			}
			else white=min(white,t);
		}
		//if(book[1][1][0]&&book[1][1][1])break;
		for(int i=0;i<12;i++){
			if(t.x+step[i][0]<=x&&t.x+step[i][0]>0&&t.y+step[i][1]<=y&&t.y+step[i][1]>0){
				t1.x=t.x+step[i][0];
				t1.y=t.y+step[i][1];
				t1.val=t.val;
				t1.cnt=t.cnt+1;
				if(!book[t1.x][t1.y][t1.val]){
					q.push(t1);
				}
			}
		}
	}
	printf("%d\n%d",black.cnt,white.cnt);
	return 0;
}
