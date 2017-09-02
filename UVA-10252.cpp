#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    char a[1005], b[1005];
    while(fgets(a, 1005, stdin) && fgets(b, 1005, stdin)){
        a[strlen(a)-1]='\0'; b[strlen(b)-1]='\0';
        int lena=strlen(a), lenb=strlen(b);
        sort(a, a+lena);
        sort(b, b+lenb);

        int rec[lena+1][lenb+1], ins[lena+1][lenb+1];
        memset(rec, 0, sizeof(rec));
        memset(ins, 0, sizeof(ins));
        for(int i=1; i<=lena; ++i){
            for(int j=1; j<=lenb; ++j){
                if(a[i-1] == b[j-1]){
                    rec[i][j] = rec[i-1][j-1]+1;
                    ins[i][j] = 1;
                }
                else{
                    rec[i][j] = max(rec[i-1][j], rec[i][j-1]);
                    if(rec[i-1][j]>rec[i][j-1]){
                        ins[i][j]=2;
                    }
                    else ins[i][j]=3;
                }
            }
        }
        string ans="";
        while(lena>0 && lenb>0){
            switch(ins[lena][lenb]){
                case 1:
                    ans = a[lena-1]+ans;
                    --lena; --lenb;
                    break;
                case 2:
                    --lena;
                    break;
                case 3:
                    --lenb;
                    break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

