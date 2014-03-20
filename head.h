
//
#define STRLEN 10240


// for struct define

typedef struct node
{	
	char * value;
	char * option;
	struct node * next;

}node;

// for function define
void usage();

// 结束后清理内存
void cleanlist();

// 输出最后的option信息
void listinfo();

//
int initlist(node * list);

//
int processargs(node * list,char * args);