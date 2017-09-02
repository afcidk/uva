#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    string a, b;
    int count=0;
    while(getline(cin, a) && a!="#"){
        getline(cin, b);

        int lena=a.length(), lenb=b.length();
        int rec[lena+1][lenb+1];
        memset(rec, 0, sizeof(rec));
        for(int i=1; i<=lena; ++i){
            for(int j=1; j<=lenb; ++j){
                if(a[i-1] == b[j-1])    rec[i][j] = rec[i-1][j-1]+1;
                else rec[i][j] = max(rec[i-1][j], rec[i][j-1]);
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n", ++count, rec[lena][lenb]);
    }
    return 0;
}
