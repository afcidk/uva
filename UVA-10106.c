#include<stdio.h>
#include<string.h>
#define M 600

int main() {
	char a[M], b[M];
	int ans[M];
	while(fgets(a, M, stdin) && fgets(b, M, stdin)){
		memset(ans, 0, sizeof(ans));
		int lena = strlen(a)-1;
		int lenb = strlen(b)-1;

		int i, j, k, l;
		for(i=0, k=lena-1; i<lena; i++, k--){
			for(j=0, l=lenb-1; j<lenb; j++, l--){
				ans[i+j] += (a[k]-'0')*(b[l]-'0');
			}
		}

		for(i = 0; i<M-1; i++){
			ans[i+1] += ans[i]/10;
			ans[i] %= 10;
		}

		for(i = M-1; i>0&&ans[i]==0; i--);
		for(;i>=0; i--)	printf("%d", ans[i]);
		printf("\n");
	}
	return 0;
}
