#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	srand(time(NULL));
	for(int i = 0; i < 15;++i){
		for(int j = 0; j < 20; ++j){
			if(rand() % 19 > 12 ) printf("1");
			else printf("0");
		}
		printf("\n");
	}
}
