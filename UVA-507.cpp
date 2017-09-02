#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n, count=0;
    scanf("%d", &n);
    while(n--){
        int m;
        scanf("%d", &m);
        long long num[m];
        for(int i=0; i<m-1; ++i)    scanf("%lld", &num[i]);

        long long sum=0, max_sum=0;
        long long start=0, mStart=1, mEnd=0;
        for(int i=0; i<m-1; ++i){
            sum += num[i];
            if(sum<0){
                sum = 0;
                start = i+1;
            }
            if(max_sum == sum){
                if(mEnd-mStart < i-start){
                    mStart = start;
                    mEnd = i;
                }
            }
            else if(max_sum < sum){
                max_sum = sum;
                mStart = start;
                mEnd = i;
            }
        }
        if(max_sum <= 0){
            printf("Route %d has no nice parts\n", ++count);
        }
        else
            printf("The nicest part of route %d is between stops %lld and %lld\n", ++count, mStart+1, mEnd+2);
    }
    return 0;
}
