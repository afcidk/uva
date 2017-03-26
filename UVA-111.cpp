#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstring>
using namespace std;

bool check(string s){
	for(int i=0; i<s.length(); ++i)
		if(s.at(i)==' ')	return false;
	return true;
}

int main() {
	string s;
	int tar[50];
	int num[50];
	int comp[50];
	int n;
	while(getline(cin,s)){
		if(check(s)){
			stringstream ss(s);
			ss>>n;

			int x, p=0;
			getline(cin, s);
			stringstream st(s);
			while(st>>x){
				tar[x]=++p;
			}
		}
		else{
			int xx[50][50]={0};
			memset(comp, 0, sizeof(comp));
			stringstream ss(s);
			int pos=0, x;
			while(ss>>x){
				num[x]=++pos;
			}
			int i, j;

			for(i=1; i<=n; ++i){
				for(j=1; j<=n; ++j){
					if(num[i]==tar[j])	xx[i][j] = xx[i-1][j-1]+1;
					else xx[i][j]=max(xx[i-1][j], xx[i][j-1]);
				}
			}
			printf("%d\n", xx[n][n]);
		}
	}
	return 0;
}
