
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

	return 0;
}

//
int processargs(node * list,int argc,char * argv[]){

	int index=0;
	node * pare = list;
	node * cur = list->next;
	char * buf= NULL;
	char * cpbuf= NULL;
	int slen=0;
	for (; index<argc; index++) { 

		//printf("%s\n", argv[index] );

		//continue;

		if (argv[index][0] == '-'){
			//get an option
			//printf("get option\n");
			cur=(node*) malloc(sizeof(node));
			pare->next=cur;
			pare=cur;
			cur->option=NULL;
			cur->value=NULL;

			buf= argv[index];
			while( buf && (*buf=='-') )
				++buf;
			slen=strlen(buf);


			if (slen>0)
			{	
				//printf("1:%s\n",buf);
				cur->option=(char*)malloc(slen+1);
				cpbuf= cur->option;
				while( *buf !='\0' && (*buf != '=') ){
					*cpbuf++=*buf++;
				}
				*cpbuf='\0';

				if (*buf=='=')
				{
					//printf("2:%s\n",buf);
					 cur->value=(char*)malloc(slen);
					 strcpy(cur->value, buf+1);
					 cur=NULL;
					 
				}

				


			}else{
				//get an emtpy option like  -
				cur=NULL;
			}


		}else{

			if (cur==NULL)
			{
				//just a value without option.

				cur=(node*) malloc(sizeof(node));
				pare->next=cur;
				pare=cur;
				cur->option=NULL;
				cur->value=NULL;

				buf=argv[index];

				slen=strlen(buf);
				cur->value=(char*)malloc(slen+1);
				strcpy(cur->value,buf);

				cur=NULL;

			}else{

				buf=argv[index];
				slen=strlen(buf);
				cur->value=(char*)malloc(slen+1);
				strcpy(cur->value,buf);
				//an option's value
				cur=NULL;
			}

		}
	}
	return 0;
}


int freelist(node * list){

	node * cur = list;
	node * cn = list->next;
	while (cur != NULL ) {

		if (cur->option)
		{
			free(cur->option);
		}

		if (cur->value)
		{
			free(cur->value);
		}

		cn = cur->next;
		free(cur);
		cur = cn;
	}

	return 0;
}




void printinfo(node * list){

	node * p=list->next;

	while(p){

		if (p->option==NULL&&p->value==NULL)
		{
			printf("just have a '-' or multi '-' without option and value \n");
			p=p->next;
			continue;
		}

		if (p->option&&p->value)
		{
			printf("have an option '%s' with value '%s'\n",p->option,p->value );
		}else if (p->option)
		{
			printf("just have an option:'%s'\n",p->option );
			
		}else{
			printf("just have a avlue:'%s'\n",p->value);
		}
		p=p->next;
	}

}











