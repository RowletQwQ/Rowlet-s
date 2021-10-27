#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long 
ll a[3];
/*Not triangle；
如果是直角三角形，输出Right triangle；
如果是锐角三角形，输出Acute triangle；
如果是钝角三角形，输出Obtuse triangle；
如果是等腰三角形，输出Isosceles triangle；
如果是等边三角形，输出Equilateral triangle*/

int main(int argc, char** argv) {
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	if(a[0]+a[1]<=a[2]){
		cout<<"Not triangle"<<endl;
	}else{
		if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2]){
			cout<<"Right triangle"<<endl;
		}else if(a[0]*a[0]+a[1]*a[1]>=a[2]*a[2]){
			cout<<"Acute triangle"<<endl;
		}else{
			cout<<"Obtuse triangle"<<endl;
		}
		if(a[0]==a[1]||a[1]==a[2]||a[0]==a[2]){
			cout<<"Isosceles triangle"<<endl;
			if(a[0]==a[1]&&a[1]==a[2]&&a[0]==a[2]){
				cout<<"Equilateral triangle"<<endl;
			}
		}
	}
	return 0;
}
