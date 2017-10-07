#include <iostream>
using namespace std;

void addUp(string&, string&, int);

int main() {
    ios::sync_with_stdio(false);
    string s;
    while(getline(cin, s)){
        
        s = '['+s+']';
        int len = s.length();
        string tmp="", ret="";
        int last=0; //0=[ 1=]
        for(int i=0; i<len; ++i){
            if(s[i]=='['){
                addUp(ret, tmp, last);
                last=0;
            }
            else if(s[i]==']'){
                addUp(ret, tmp, last);
                last=1;
            }
            else{
                tmp += s[i];
            }
        }
        cout<<ret<<'\n';
    }
    return 0;
}

void addUp(string &ret, string &tmp, int last){
    if(tmp!=""){
        if(!last)    ret = tmp+ret;
        else ret = ret+tmp;
        tmp="";
    }
}
