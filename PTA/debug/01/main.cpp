/*#include <stdio.h>
#define ll long long
int main(){
	ll T,n;
	int digit;
	scanf("%lld",&T);
	for(int i=1;i<=T;i++){
		scanf("%lld",&n);
		digit=n%10;
		int ans=digit;
		for(int j=1;j<=(n-1)%4;j++)ans=(ans*digit)%10;
		printf("%d\n",ans);
	}
	return 0;
} */
#include<stdio.h>
int main()
{
 int T,i,j,digit,digit1;
 long long n,result;
 scanf("%d", &T);
 for(i=0;i<T;i++)
 {
  scanf("%lld", &n);
  digit1=n%10;
  result=1;
  if(n%4!=0&&digit1!=0)
  {
   for(j=0;j<n%4;j++)
   {
    result=result*digit1;
   }
   digit=result%10;
   printf("%d\n", digit);
  }
  else if(n%4==0&&digit1!=0)
  {
   printf("6\n");
  }
  else if(digit1==0)
  {
   printf("0\n");
  }
 }
 return 0;
}
