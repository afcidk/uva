/*
   floating number precision problem
*/
#include <bits/stdc++.h> 
#define MAX 10005 
using namespace std;

int p[MAX], rec[MAX];
vector<int> prime;
void build(){
    for(int i=0; i<MAX; ++i)    p[i] = 1;
    p[0] = p[1] = 0;

    for(int i=2; i<MAX; ++i){
        if(p[i]){
            for(int j=i*i; j<MAX; j+=i){
                p[j] = 0;
            }
        }
    }
    for(int i=2; i<MAX; ++i)
        if(p[i])    prime.push_back(i);
    int p_size = prime.size();

    for(int i=0; i<=10000; ++i){
        int calc = i*i+i+41;
        bool tag = true;
        for(int j=0; j<p_size && prime[j]<calc; ++j){
            if(calc%prime[j]==0){
                tag = false;
                break;
            }
        }
        rec[i] = tag;
    }
}

int main() {
    build();
    int a, b;
    while(scanf("%d %d", &a, &b) == 2){
        int calc, sum=0;
        for(int i=a; i<=b; ++i){
            if(rec[i])  ++sum;
        }
        printf("%.2f\n", double(sum)/(b-a+1)*100+1e-12);
    }
    return 0;
}
