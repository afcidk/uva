#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	string a,b;
	while(cin>>a>>b){
		int len = a.length();
		int al[26]={0}, tal[26]={0};
		if(len!=b.length())	printf("NO\n");
		else {
			int i;
			for(i = 0; i<len; i++){
				al[a.at(i)-'A']++;
				tal[b.at(i)-'A']++;
			}

			sort(al, al+26);
			sort(tal, tal+26);
			int flag = 0;
			for(i = 0; i<26; i++){
				if(al[i]!=tal[i]){
					flag = 1;
					break;
				}
			}
			if(flag)	printf("NO\n");
			else printf("YES\n");
		}
	}
}
