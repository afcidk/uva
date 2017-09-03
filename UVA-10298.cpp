#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[1000005];

int main() {
	while(scanf("%s", s) && strcmp(s, ".")!=0){
		int len=strlen(s), ans=0;
		for(int i=1; i<=len; ++i){
			if(len%i == 0){
				bool fail=false;
				int count=0;
				for(int j=0; j<len; ++j){
					if(count == i)	count=0;
					if(s[j]!=s[count]){
						fail=true;
						break;
					}
					++count;
				}
				if(!fail){
					ans=i;
					break;
				}
			}
		}
		printf("%d\n", len/ans);
	}
	return 0;
}

