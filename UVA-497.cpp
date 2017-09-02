#include <iostream>
#include <cstdio>
#include <vector> 
#include <cstring>
#include <cstdlib>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    getchar();
    while(n--){
        vector<int> num;
        string str;
        int count=0;
        while(getline(cin, str) && str!=""){
            num.push_back(atoi(str.c_str())); 
        }

        int len=num.size(); 
        int stack[len];
        int rec[len], ma=0;
        for(int i=0; i<len; ++i)    stack[i]=0x7fffffff;

        for(int i=0; i<len; ++i){
            int ind=lower_bound(stack, stack+len, num[i])-stack;
            stack[ind]=num[i];
            rec[i]=ind;
            if(ma<ind)  ma=ind;
        }
        
        printf("Max hits: %d\n", ma+1);
        vector<int> p;
        for(int i=len-1; i>=0 && ma!=-1; --i){
            if(rec[i] == ma){
                --ma;
                p.push_back(num[i]);
            }
        }
        for(int i=p.size()-1; i>=0; --i)   printf("%d\n", p[i]);
        if(n)   puts("");
    }
    return 0;
}
