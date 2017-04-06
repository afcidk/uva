#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    getchar();
    while(n--){
        string s;
        int total=0;
        map<string, int> m;
        map<string, int>::iterator iter;
        while(getline(cin, s)){
            if(s=="")   break;
            if(m.find(s)!=m.end())  ++m[s];
            else m[s]=1;
            ++total;
        }

        for(iter=m.begin(); iter!=m.end(); ++iter){
            cout<<iter->first;
            printf(" %.4lf\n", (float)iter->second/total*100);
        }
        if(n)   puts("");
    }
}
