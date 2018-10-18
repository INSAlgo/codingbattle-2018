#include <stdio.h>
#include <stdlib.h>


int main(){
	const int STRING_LENGTH = 101;
	
	int nb_parrots=0;
	char *trainer_name = (char*)malloc(sizeof(char)*STRING_LENGTH);

	int G, N;
	scanf("%d %d", &G, &N);
	
	char* trainer = (char*)malloc(sizeof(char)*STRING_LENGTH);
	for(int i=0; i<N; ++i){		
		int a, b;
		scanf("%s %d %d", trainer, &a, &b);
		
		if( ((G-b)/a)>nb_parrots ){
			nb_parrots = ((G-b)/a);
			free(trainer_name);
			trainer_name = trainer;
			trainer = (char*)malloc(sizeof(char)*STRING_LENGTH);
		}
		
	}

	if(nb_parrots==0)
		printf("Impossible\n");
	else
		printf("%d\n%s\n", nb_parrots, trainer_name);

	free(trainer);

	return 0;
}
