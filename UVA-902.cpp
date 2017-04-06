#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

int main(){
    int n;
    string s;
    while(cin>>n>>s){
        map<string, int> m;
        int i, j;
        int len=s.length(), ma=-1;
        string ans;
        for(i=0; i<len-n+1; ++i){
            string subs=s.substr(i, n);
            if(m.find(subs)!=m.end()) m[subs]++;
            else m[subs]=1;
            if(ma<m[subs]){
                ma = m[subs];
                ans=subs;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
