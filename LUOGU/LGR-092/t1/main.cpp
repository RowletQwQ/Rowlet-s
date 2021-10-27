#include <iostream>
#include <string>
using namespace std;
string s;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void check(int a){
	a++;
	if(s[a]=='n'){
		cout<<"linux";
		return;
	}
	if(s[a]=='r'){
		if(s.length()-1==a){
			cout<<"mac";
			return;
		}
		if(s[a+1]==92&&s[a+2]=='n'){
			cout<<"windows";
			return;
		}
		cout<<"mac";
	}
	return;
}
int main(int argc, char** argv) {
	
	getline(cin,s);
	int len=s.length();
	for(int i=0;i<len;i++){
		//cout<<int(s[i])<<" ";
		if(s[i]==92){
			check(i);
			break;
		}
	}
	return 0;
}
