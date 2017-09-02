#include <iostream>
#include <cstdio>
using namespace std;

long long int num[505];

int main() {
    int n;
    scanf("%d", &n);
    while(n--){
        int k, m;
        scanf("%d%d", &k, &m);
        long long int left=0, right=0;
        for(int i=0; i<k; ++i){
            scanf("%lld", &num[i]);
            left = left>num[i]?left:num[i];
            right += num[i];
        }

        //find maximum volume
        while(left<right){

            long long int sum=0, count=0;
            long long int mid = (left+right)/2;
            for(int i=0; i<k; ++i){
                sum += num[i];
                if(sum>mid){
                    sum=num[i];
                    ++count;
                }
                if(sum==mid){
                    sum=0;
                    ++count;   
                }
            }
            if(sum>0)   ++count;

            if(count>m) left=mid+1;
            else right=mid;
        }

        //pair and record with max volume, start from end
        int rec[m-1]={0}, sum=0;
        for(int i=k-1, j=m-2; i>=0 && j>=0; --i){
           sum += num[i];
           if(sum>left){
               sum=num[i];
               rec[j--]=i+1;
           }
           if(i == j){// everyone must have at least one book
               while(j>=0){
                   rec[j--]=i+1;
                   --i;
               }
               break;
           }
        }

        for(int i=0; i<rec[0]; ++i) printf("%lld ", num[i]);
        printf("/ ");
        for(int i=0; i<m-1; ++i){
            int end=(i==m-2)?k:rec[i+1];
            for(int j=rec[i]; j<end; ++j){
                printf("%lld", num[j]);
                if(j!=end-1)    printf(" ");
            }
            if(i!=m-2)  printf(" / ");
        }
        puts("");
    }
    return 0;
}

