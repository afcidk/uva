#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

void fail(string, int*);
int match(string, string, int*);

int main(){
	int n;
	scanf("%d", &n);
	while(n--){

		string a, b;
		cin>>a>>b;
		int lena=a.length(), lenb=b.length();
		int pi[10005];

		fail(a, pi);
		printf("%d\n", match(a, b, pi));

	}
	return 0;
}

void fail(string s, int *pi){
	
	int len = s.length(), i;
	int cur_pos = -1;
	pi[0]=-1;
	for(i=1; i<len; ++i){

		while(~cur_pos && s[i]!=s[cur_pos+1])
			cur_pos = pi[cur_pos];
		if(s[i] == s[cur_pos+1])	++cur_pos;
		pi[i] = cur_pos;

	}
}

int match(string a, string b, int *pi){

	int lena = a.length(), lenb=b.length();
	int cur_pos = -1, i;
	int ans=0;

	for(i=0; i<lenb; ++i){
		while(~cur_pos && a[cur_pos+1]!=b[i])
			cur_pos = pi[cur_pos];
		if(b[i] == a[cur_pos+1])	++cur_pos;
		if(cur_pos+1 == lena){
			ans++;
			cur_pos = pi[cur_pos];
		}

	}
	return ans;
}
