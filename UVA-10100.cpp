#include<cstdio>
#include<vector>
#include<sstream>
#include<iostream>
#define MAX 1005
using namespace std;

void clean(string *);

int main() {
	string origin, temp, comp;
	int count=0;
	while(getline(cin, origin) && getline(cin, comp)){

		clean(&origin);
		clean(&comp);
		stringstream ss(origin);
		stringstream st(comp);

		vector<string> vec, com;
		int vec_len=0, com_len=0;
		while(ss>>temp){
			vec.push_back(temp);
			vec_len++;
		}

		while(st>>temp){
			com.push_back(temp);
			com_len++;
		}

		int xx[MAX][MAX]={0};
		int i, j;

		for(i=1; i<=vec_len; ++i){
			for(j=1; j<=com_len; ++j){
				if(vec[i-1]==com[j-1])	xx[i][j] = xx[i-1][j-1]+1;
				else xx[i][j] = max(xx[i-1][j], xx[i][j-1]);
			}
		}

		if(xx[vec_len][com_len]==0)	printf("%2d. Blank!\n", ++count);
		else printf("%2d. Length of longest match: %d\n", ++count, xx[vec_len][com_len]);
	}
}

void clean(string *s){
	int i, len=(*s).length();
	for(i=0; i<len; ++i)	{
		if(!isalnum((*s).at(i)))	(*s).at(i)=' ';
	}
}
