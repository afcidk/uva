#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int main() {
	string s;
	set<string> list;
	while(getline(cin, s))	list.insert(s);
	for(auto iter=list.begin(); iter!=list.end(); ++iter){
		string tmp=*iter;
		int len=(*iter).length();
		for(int i=0; i<len; ++i){
			string s1=tmp.substr(0, i);
			string s2=tmp.substr(i, len-i);

			if(list.find(s1)!=list.end() && list.find(s2)!=list.end()){
				cout<<tmp<<endl;
				break;
			}
		}
	}

	return 0;
}
