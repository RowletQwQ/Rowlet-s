#include <iostream>
using namespace std;
int main(){
	char r,y='Y',n='N';
	cout<<"现在正在下雨吗？"<<endl;
	cin>>r;
	if(r==y)cout<<"正在下雨";
	else if(r==n)cout<<"没下呢";
	else cout<<"你别搞笑咯"; 
	return 0;
}
