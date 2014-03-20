#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "head.h"

int main(int argc, char * argv[]){


	int index = 0;
	if (argc<2)
	{
		usage();
		return 0;
	}

	node * list;
	if (initlist()){
		printf("some error happened\n");
		return -1;
	}

	for (index=1; index<argc; index++) { 
		if (argv[index][0] == '-')
		{
			//get an option
			printf("get option\n");
		}
	}


}

