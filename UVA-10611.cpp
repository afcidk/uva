#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) == 1){
        int num[n];
        for(int i=0; i<n; ++i)  scanf("%d", &num[i]);
        int k, t;
        scanf("%d", &k);
        while(k--){
           scanf("%d", &t);
           int ind=lower_bound(num, num+n, t)-num;
           if(ind-1<0)  printf("X");
           else  printf("%d", num[ind-1]);

           ind=upper_bound(num, num+n, t)-num;
           if(ind>=n)  printf(" X\n");
           else  printf(" %d\n", num[ind]);
        }
    }
    return 0;
}
