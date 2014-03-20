#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "head.h"

int main(int argc, char * argv[]){

	
	if (argc<2)
	{
		usage();
		return 0;
	}

	node * list=(node*)malloc(sizeof(node));
	list->value=NULL;
	list->option=NULL;
	list->next=NULL;
	
	processargs(list,argc-1,argv+1);
	printinfo(list);

	freelist(list);

	return 0;
}

