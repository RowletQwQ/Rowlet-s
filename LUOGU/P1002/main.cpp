#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
ll dp[25][25],n,m,x,y;
bool book[25][25]; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int step[8][2]={{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2}};
int main(int argc, char** argv) {
	//freopen("out.txt","w",stdout);
	scanf("%d%d%d%d",&n,&m,&x,&y);
	book[x][y]=true;
	int tx,ty;
	for(int i=0;i<8;i++){
		tx=x+step[i][0];
		ty=y+step[i][1];
		if(tx>=0&&ty>=0&&tx<=n&&ty<=m){
			book[tx][ty]=true;
		}
	}
	for(int i=0;i<=n;i++){
		if(book[i][0])break;
		dp[i][0]=1;
	}
	for(int i=0;i<=m;i++){
		if(book[0][i])break;
		dp[0][i]=1;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(!book[j][i]){
				dp[j][i]=dp[j-1][i]+dp[j][i-1];
			}
		}
	}
	printf("%lld",dp[n][m]);
	/*for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			printf("%llu ",dp[i][j]);
		}
		printf("\n");
	}*/
	return 0;
}
