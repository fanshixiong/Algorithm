#include <stdio.h>
#include <string.h>
#define N 1000
#define HEIGHT 100
#define WIDTH 1000

struct BiTree
{
	int v;
	struct BiTree* l;
	struct BiTree* r;
};

int max(int a, int b)
{
	return a>b? a : b;
}

struct BiTree* init(struct BiTree* p, int v)
{
	p->l = NULL;
	p->r = NULL;
	p->v = v;
	
	return p;
}

void add(struct BiTree* me, struct BiTree* the)
{
	if(the->v < me->v){
		if(me->l==NULL) me->l = the;
		else add(me->l, the);
	}
	else{
		if(me->r==NULL) me->r = the;
		else add(me->r, the);
	}
}

//�����������ʾ�߶�	
int getHeight(struct BiTree* me)
{
	int h = 2;
	int hl = me->l==NULL? 0 : getHeight(me->l);
	int hr = me->r==NULL? 0 : getHeight(me->r);
	
	return h + max(hl,hr);
}

//�����������ʾ���	
int getWidth(struct BiTree* me)
{
	char buf[100];
	sprintf(buf,"%d",me->v); 
	int w = strlen(buf);
	if(me->l) w += getWidth(me->l);
	if(me->r) w += getWidth(me->r);
	return w;
}

int getRootPos(struct BiTree* me, int x){
	return me->l==NULL? x : x + getWidth(me->l);
}

//�ѻ���������ά������ 
void printInBuf(struct BiTree* me, char buf[][WIDTH], int x, int y)
{
	int p1,p2,p3,i;
	char sv[100];
	sprintf(sv, "%d", me->v);
	
	p1 = me->l==NULL? x : getRootPos(me->l, x);
	p2 = getRootPos(me, x);
	p3 = me->r==NULL? p2 : getRootPos(me->r, p2+strlen(sv));
	
	buf[y][p2] = '|';
	for(i=p1; i<=p3; i++) buf[y+1][i]='-';
	for(i=0; i<strlen(sv); i++) buf[y+1][p2+i]=sv[i];
	if(p1<p2) buf[y+1][p1] = '/';
	if(p3>p2) buf[y+1][p3] = '\\';
	
	if(me->l) printInBuf(me->l,buf,x,y+2);
	if(me->r) printInBuf(me->r, buf, p2+strlen(sv), y+2);  //���λ��
}

void showBuf(char x[][WIDTH])
{
	int i,j;
	for(i=0; i<HEIGHT; i++){
		for(j=WIDTH-1; j>=0; j--){
			if(x[i][j]==' ') x[i][j] = '\0';
			else break;
		}
		if(x[i][0])	printf("%s\n",x[i]);
		else break;
	}
}
	
void show(struct BiTree* me)
{
	char buf[HEIGHT][WIDTH];
	int i,j;
	for(i=0; i<HEIGHT; i++)
	for(j=0; j<WIDTH; j++) buf[i][j] = ' ';
	
	printInBuf(me, buf, 0, 0);
	showBuf(buf);
}

int main()
{	
	struct BiTree buf[N];	//�洢�ڵ����� 
	int n = 0;              //�ڵ���� 
	init(&buf[0], 500); n++;  //��ʼ����һ���ڵ� 

	add(&buf[0], init(&buf[n++],200));  //�µĽڵ�������� 
	add(&buf[0], init(&buf[n++],509));
	add(&buf[0], init(&buf[n++],100));
	add(&buf[0], init(&buf[n++],250));
	add(&buf[0], init(&buf[n++],507));
	add(&buf[0], init(&buf[n++],600));
	add(&buf[0], init(&buf[n++],650));
	add(&buf[0], init(&buf[n++],450));
	add(&buf[0], init(&buf[n++],440));
	add(&buf[0], init(&buf[n++],220));
	
	show(&buf[0]);	
	return 0;	
}
