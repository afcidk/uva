#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

int main() {
	int n, first=1;;
	while(scanf("%d", &n)==1){
		getchar();
		map<string, int> m;
		map<string, int>::iterator it;

		int i;
		string a, b;
		for(i=0; i<n; i++){
			cin>>a;
			getline(cin, b);

			if(m.find(a)!=m.end())	m[a]++;
			else m[a]=1;
		}
		
		if(!first)	printf("\n");
		first=0;
		for(it=m.begin(); it!=m.end(); it++){
			cout<<it->first<<" "<<it->second<<endl;
		}

	}
}
