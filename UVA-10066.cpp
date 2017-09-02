#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int n, m, count=0;
    while(scanf("%d%d", &n, &m)==2 && (n||m)){
        int a[105], b[105];
        int rec[105][105]={0};
        for(int i=0; i<n; ++i)  scanf("%d", &a[i]);
        for(int i=0; i<m; ++i)  scanf("%d", &b[i]);

        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j){
                if(a[i-1] == b[j-1])    rec[i][j]=rec[i-1][j-1]+1;
                else rec[i][j]=max(rec[i-1][j], rec[i][j-1]);
            }
        }
        printf("Twin Towers #%d\n", ++count);
        printf("Number of Tiles : %d\n", rec[n][m]);
        puts("");
    }
    return 0;
}

