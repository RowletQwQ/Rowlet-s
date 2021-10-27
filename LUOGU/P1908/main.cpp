// luogu-judger-enable-o2
#include <cstdio>
#include <iostream>
#include <cstring>
int n,num[500005],L[250005],R[250005];
long long ans;
using namespace std;
int get(){
    int x;
    char c;
    for(c=getc(stdin);c<'0'||c>'9';c=getc(stdin));
    for(x=0;c>='0'&&c<='9';c=getc(stdin))
        x=x*10+c-'0';
    return x;
}
void merge(int l,int q,int r){
    int size=(r-l+10)>>1;
    memset(L,0,sizeof(int)*size);
    memset(R,0,sizeof(int)*size);
    int t=1;
    //cout<<"L:";
    for(int i=l;i<=q;i++){
        L[t]=num[i];
        //printf("%d ",L[t]);
        t++;
    }
    t=1;
    //cout<<"R:";
    for(int i=q+1;i<=r;i++){
        R[t]=num[i];
        //cout<<R[t]<<" ";
        t++;
    }
    //cout<<endl;
    int mark=l;
    int li=1,lr=1;
    while(mark<=r){
        if(L[li]>R[lr]){
            num[mark]=L[li];
            mark++;
            //ans++;
            ans+=r-q+1-lr;
            li++;
        }else{
            num[mark]=R[lr];
            mark++;
            lr++;
        }
    }
    //cout<<"now:";
    //for(int i=1;i<=n;i++)
        //printf("%d ",num[i]);
//cout<<endl;
    return;
    
 }
void msort(int l,int r){
    if(l<r){
        int q=(l+r)>>1;
        msort(l,q);
        msort(q+1,r);
        merge(l,q,r);
    }
    return;
}
int main(){
    memset(num,0,sizeof(num));
    //int n;
    n=get();
    for(int i=1;i<=n;i++)
        num[i]=get();
    msort(1,n);
    printf("%lld",ans);
    //for(int i=1;i<=n;i++)
        //printf("%d ",num[i]);
    return 0; 
}
