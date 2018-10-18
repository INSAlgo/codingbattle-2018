#include <stdio.h>
#include <stdlib.h>

int main(){
	int b,t,n;
	scanf("%d %d %d", &b, &t, &n);

	if(2*b + 3*t <=n)
		printf("LOOT!\n");
	else
		printf("RHUM!\n");
	
	return 0;
}
