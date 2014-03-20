

// for struct define

typedef struct node
{	
	char * value;
	char * option;
	struct node * next;

}node;

// for function define

void usage();

//
int processargs(node * list,int argc,char * argv[]);

int freelist(node * list);

void printinfo(node * list);