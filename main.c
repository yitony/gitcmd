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

	node * list = (node*)malloc(sizeof(node));
	list->value = NULL;
	list->option = NULL;
	list->next = NULL;
	
	//处理输入的参数，在list中生成相应的option and value.
	processargs(list, argc-1, argv+1);

	//输出相应的信息
	printinfo(list);

	//清理内存。
	freelist(list);

	return 0;
}

