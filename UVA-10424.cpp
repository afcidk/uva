#include<iostream>
#include<cstdio>
using namespace std;

int trans(int);

int main() {
	string a, b;
	while(getline(cin, a) && getline(cin, b)){
		int lena = a.length(), lenb = b.length();
		int i;
		int ca=0, cb=0;
		for(i = 0; i<lena; i++){
			if(a.at(i)<='Z' && a.at(i)>='A')	ca+=a.at(i)-'A'+1;
			else if(a.at(i)<='z' && a.at(i)>='a')	ca+=a.at(i)-'a'+1;
		}
		ca = trans(ca);

		for(i = 0; i<lenb; i++){
			if(b.at(i)<='Z' && b.at(i)>='A')	cb+=b.at(i)-'A'+1;
			else if(b.at(i)<='z' && b.at(i)>='a')	cb+=b.at(i)-'a'+1;
		}
		cb = trans(cb);

		if(ca>cb)	printf("%.2lf %%\n", (double)cb/(double)ca*100);
		else printf("%.2lf %%\n", (double)ca/(double)cb*100);
	}
	return 0;
}

int trans(int x){
	int ret = 0;
	while(x){
		ret+=x%10;
		x/=10;
	}
	if(ret>=10)	return trans(ret);
	return ret;
}
