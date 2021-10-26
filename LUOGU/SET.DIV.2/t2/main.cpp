#include <cstdio>
#include <iostream>
#include <cstring>
#inclued <queue>
#include <algorithm>
using namespace std;
struct num{
	int i,val;
	bool operator <(const num &a) const{
		return val>a.val;
	}
};
priority_queue <num> q;
int main(){
	return 0;
}
