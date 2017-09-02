#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

void parse(vector<string>&, string&);

int main() {
    string a, b;
    int count=0;
    while(getline(cin, a) && getline(cin, b)){

        vector<string> sta, stb;
        parse(sta, a);
        parse(stb, b);

        int rec[sta.size()+1][stb.size()+1];
        memset(rec, 0, sizeof(rec));
        for(int i=1; i<=sta.size(); ++i){
            for(int j=1; j<=stb.size(); ++j){
                if(sta[i-1] == stb[j-1])    rec[i][j] = rec[i-1][j-1]+1;
                else rec[i][j] = max(rec[i-1][j], rec[i][j-1]);
            }
        }

        if(a.length()==0 || b.length()==0)  printf("%2d. Blank!\n", ++count);
        else printf("%2d. Length of longest match: %d\n", ++count, rec[sta.size()][stb.size()]);
    }
    return 0;
}

void parse(vector<string> &x, string &s){
    int len=s.length();
    int start=0;
    for(int i=0; i<len; ++i){
        if(!(('a'<=s[i]&&s[i]<='z') || ('A'<=s[i]&&s[i]<='Z') || ('0'<=s[i]&&s[i]<='9'))){
            if(i-start>0){
                x.push_back(s.substr(start, i-start));
            }
            start=i+1;
        }
    }
    if(start != len){
        x.push_back(s.substr(start, len-start));
    }
}
