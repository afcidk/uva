#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	while(n--){
		string s;
		cin>>s;	

		int len=s.length(), ans=0;
		for(int i=1; i<=len; ++i){
			if(len%i == 0){
				bool fail=false;
				int count=0;
				for(int j=0; j<len; ++j){
					if(count == i)	count=0;
					if(s[count]!=s[j]){
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
		printf("%d\n", ans);
		if(n)	puts("");
	}
	return 0;
}
