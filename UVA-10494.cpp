#include<cstdio>
#include<iostream>
using namespace std;

string mult(string, int);

int main() {
	string a;
	string b;
	char ch;
	while(cin>>a>>ch>>b){
		int lena=a.length(), lenb=b.length();
		int start=0, last=0;
		int i, j;
		string ans="";

		if(lena>lenb || (lena==lenb && a>=b)){
			while(lena-start>lenb || (lena-start==lenb && a.substr(start, lena-start)>=b)){
				int temps=start, first=1;
				string buf="";
				for(i=start; i<=last; i++){	//add previous remainder
					if(a.at(temps)!='0')	first=0;
					else if(first){
						temps++;
						start++;
					}
	
					if(!first)	buf+=a.at(temps++);
				}
				while(buf.length()<lenb || (buf.length()==lenb && buf<b)){ // add 0 while remainder+1digit < b
					if(temps==lena)	break;
					ans+="0";
	
					buf+=a.at(temps++);
				}
	
				for(i=1; i<=10; i++){ //multiply b 
					string btest=mult(b, i);
					if(btest.length()>buf.length() ||(btest.length()==buf.length() && btest>buf))	break;
				}
				ans+=char(i-1+'0');
				string nowb=mult(b, i-1);
	
				for(i=temps-1, j=nowb.length()-1; i>=start&&j>=0; --j, --i){ //minus
					a.at(i)-=nowb.at(j);
					if(a.at(i)<0 && i-1>=0)	{
						a.at(i)+=10;
						a.at(i-1)--;
					}
					a.at(i)+='0';
				}
				
				for(i=start; i<temps && a.at(i)=='0'; i++);//record start position and end position of the remainder
				start=i;
				if(start == lena)	break;
				last=temps;
			}
			if(ch == '/'){
				int x;
				for(x=0; x<ans.length() && ans.at(x)=='0'; x++);
				for(;x<ans.length(); x++)	cout<<ans.at(x);
				for(;x<lena; x++)	cout<<"0";
				cout<<endl;
			}
			else{
				if(start==lena)	printf("0");
				for(i=start; i<lena; i++)	cout<<a.at(i);
				cout<<endl;
			}
		}
		else
		{
			if(ch == '/')	printf("0\n");
			else cout<<a<<endl;
		}
	}
	return 0;
}

string mult(string s, int x){
	int len=s.length();
	int i;
	string ret="";
	for(i=len-1; i>=0; i--){
		char now=(s.at(i)-'0')*x;
		ret=now+ret;
	}

	for(i=len-1; i>=1; i--){
		if(ret.at(i)>=10){
			ret.at(i-1)+=ret.at(i)/10;
			ret.at(i)%=10;
		}
		ret.at(i)+='0';
	}

	while(ret.at(0)>=10){
		ret = char(ret.at(0)/10)+ret;
		ret.at(1)%=10;
		ret.at(1)+='0';
	}
	ret.at(0)+='0';
	return ret;
}
