#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int prime[500];
int visited[20];
int numList[20], len;
void solve(int cur, int end);
void build(){
    for(int i=2; i<500; ++i)    prime[i]=1;
    for(int i=2; i<500; ++i){
        if(prime[i]){
            for(int j=i*i; j<500; j+=i){
             prime[j]=0;
            }
        }
    }
}

int main() {
    int n, count=0;
    build();
    while(scanf("%d", &n) == 1){
        memset(visited, 0, sizeof(visited));
        len=0;
        numList[len++]=1;
        visited[1]=1;
        if(count)   puts("");
        printf("Case %d:\n", ++count);
        solve(1, n);
    }
    return 0;
}

void solve(int cur, int end){

    for(int i=1; i<=end; ++i){
        if(!visited[i]){
            if(len < end-1){
                if(prime[numList[len-1]+i]){
                    visited[i]=1;
                    numList[len++]=i;
                    solve(i, end);
                    visited[i]=0;
                    --len;
                }
            }
            else{
                if(prime[numList[0]+i] && prime[numList[end-2]+i]){
                    for(int j=0; j<len; ++j)    printf("%d ", numList[j]);
                    printf("%d\n", i);
                    return ;
                }
            }
        }
    }
}
