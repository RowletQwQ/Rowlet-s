#include <iostream>
#include <cstdio>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double a,b,c,d;

double ans(double x); 
double findX(double l,double r){
	double mid=(l+r)/2.00;
	if(r-l<0.001){
		return mid;
	}
	if(ans(mid)==0.00)return mid;
	if(ans(l)==0.00)return l;
	if(ans(r)==0.00)return r;
	if(ans(l)*ans(mid)<0)return findX(l,mid);
	else return findX(mid,r);
}
double ans(double x){
	return a*x*x*x+b*x*x+c*x+d; 
}
int main(int argc, char** argv) {
	
	int j=0;
	cin>>a>>b>>c>>d;
	//cout<<ans(0.00)<<endl;
	for(int i=-100;i<100;i++){
		double r=i;
		if(ans(i)==0)printf("%.2lf ",r);
		if(ans(i)*ans(i+1.00)<0){
			printf("%.2lf ",findX(r,r+1.00));
			j++;
		}
		if(j==3)break;
	}
	//cout<<field[3]<<endl;
	//for(int i=1;i<=j;i++)printf("%.2lf ",findX(field[i],field[i]+1));
	return 0;
}
