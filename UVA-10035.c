#include<stdio.h>
#include<string.h>

int main() {
	char a[100], b[100];
	while(scanf("%s %s", a, b)==2){
		if(strcmp(a,"0")==0 && strcmp(b,"0")==0)	break;
		int ans[100]={0};
		int i, j;
		int count = 0;
		for(i = strlen(a)-1, j=0; i>=0; i--,j++)	ans[j]+=a[i]-'0';
		for(i = strlen(b)-1, j=0; i>=0; i--,j++){
			ans[j]+=b[i]-'0';
		}

		for(i = 0; i<100-1; i++){
			if(ans[i]>=10){
				count++;
				ans[i+1]++;
			}
		}
	
		if(count == 0)	printf("No carry operation.\n");
		else if(count == 1)	printf("1 carry operation.\n");
		else printf("%d carry operations.\n", count);
	}
	return 0;
}
