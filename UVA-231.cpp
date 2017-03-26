#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main() {
	int n, count=0;
	int first=1;
	vector<int> num;
	while(scanf("%d", &n)==1){
		if(n==-1){
			int i, j;
			int ma=1;
			vector<int> p;
			for(i=0; i<num.size(); ++i){
				p.push_back(1);
				for(j=0; j<i; ++j){
					if(num[i]<num[j]){
						p[i] = max(p[i], p[j]+1);
						ma = max(ma, p[i]);
					}
				}
			}
			if(!first)	printf("\n");
			first=0;
			printf("Test #%d:\n", ++count);
			printf("  maximum possible interceptions: %d\n", ma);

			scanf("%d", &n);
			if(n==-1)	break;
			else{
				num.clear();
				num.push_back(n);
				continue;
			}
		}

		num.push_back(n);
	}
	return 0;
}
