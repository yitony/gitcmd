
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#include"head.h"


/*
   输出程序的帮助信息
*/
void usage(){

	//make sure have git installed

	printf("this is a git inputline explain tool\n");

	if(system("git help") > 0){

		//in case no git env installed
		printf("It seems you do not have a git installed\n");
		printf("this website[https://github.com/git/git] may help you,have fun.\n");
	}

}


// 结束后清理内存
void cleanlist(){


}

// 输出最后的option信息
void listinfo(){

}

//
int initlist(node * list){

}

//
int processargs(node * list,char * args){
	
}
