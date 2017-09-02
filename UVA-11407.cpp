#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int num[101];
int ans[10001];

void build() {
    for(int i=1; i<=100; ++i)   num[i]=i*i;

    for(int i=1; i<=100; ++i){
        for(int j=num[i]; j<=10000; ++j){
            if(ans[j] == 0) ans[j]=ans[j-num[i]]+1;
            else{
                ans[j] = min(ans[j], ans[j-num[i]]+1);
            }
        }
    }
}

int main() {

    int n;
    scanf("%d", &n);
    build();
    while(n--){
        int x;
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
    return 0;
}

