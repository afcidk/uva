#include<iostream>
#include<cstring>
using namespace std;

int main() {
	string s;
	while(getline(cin,s)){
		if(s == "ENDOFINPUT")	break;
		getline(cin,s);
		int len = s.length(), i;
		for(i = 0; i<len; i++){
			if(s.at(i)<='E' && s.at(i)>='A')	cout<<char(s.at(i)-'A'+'V');
			else if(s.at(i)<='Z' && s.at(i) >='F')	cout<<char(s.at(i)-'F'+'A');
			else cout<<char(s.at(i));
		}
		cout<<endl;
		getline(cin, s);
	}
	return 0;
}
