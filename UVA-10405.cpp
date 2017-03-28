#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 1005
using namespace std;

int main() {
	string a, b;
	while(getline(cin, a) && getline(cin, b)){
		int lena=a.length(), lenb=b.length();
		int xx[MAX][MAX];
		int i, j;
		memset(xx, 0, sizeof(xx));

		for(i=1; i<=lena; ++i){
			for(j=1; j<=lenb; ++j){
				if(a.at(i-1)==b.at(j-1))	xx[i][j]=xx[i-1][j-1]+1;
				else xx[i][j]=max(xx[i-1][j], xx[i][j-1]);
			}
		}
		printf("%d\n", xx[lena][lenb]);
	}
	return 0;
}
