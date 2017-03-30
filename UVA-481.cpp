#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	vector<int> num, lis, p;
	num.push_back(-99999999);
	while(scanf("%d", &n) == 1)	num.push_back(n);

	int i, len=num.size(), lis_size=1;
	lis.push_back(-1);lis.push_back(num[1]);
	p.push_back(-1);p.push_back(1);

	for(i=2; i<=len; ++i){
		
		if(num[i] > lis[lis_size]){
			lis.push_back(num[i]);
			lis_size++;
			p.push_back(lis_size);
		}

		else{
			int pos = lower_bound(lis.begin(), lis.end(), num[i])-lis.begin();
			p.push_back(pos);
			lis[pos] = num[i];
		}
	}

	int xx=0;
	vector<int> rec_ind;
	int step=lis_size;
	for(i=len; i>=1; --i){
		if(p[i] == step){
			step--;
			rec_ind.push_back(i);
			xx++;
		}
	}
	printf("%d\n-\n", xx);
	for(i=rec_ind.size()-1; i>=0; i--)
		printf("%d\n", num[rec_ind[i]]);


	return 0;
}
