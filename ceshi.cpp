#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct card
{
	char shape;
	char face;
	int value;
	struct card* pnext;
};
struct card* create()                                       //发牌 返回头 
{
	struct card* pnew;
	struct card* pend;
	struct card* phead;
	pnew=(struct card*)malloc(sizeof(struct card));
	pend=pnew;
	phead=pnew;
	int i,j;
	for(i=1;i<53;i++)
	{	
		if(i<14)
		    pnew->shape="spade";
		if(i<27)
		    pnew->shape="heart";
		if(i<40)
		    pnew->shape="diamond";
		if(i<53)
		    pnew->shape="club";
		if(1<(i%13)<11)
	 	    pnew->face=i;
		if((i%13)==1)
		    pnew->face='A';
		if((i%13)==11)
		pnew->face='J';
		if((i%13)==12)
		    pnew->face='Q';
		if((i%13)==13)
		    pnew->face='K';
	}
			if((i%13==0)||(i%13>=10))
			    pnew->value=10;
			if(i%13==1)
			    pnew->value==11;
			else
			    pnew->value=i;
		pnew=(struct card*)malloc(sizeof(struct card));
		pend->pnext=pnew;
		pend=pnew;
		pnew->pnext=NULL;
	free(pnew);
	return phead;
}
int order(int i)                                             //剩余牌数 返回随机值
{
	int j;
	srand((unsigned int)time(NULL));
	j=(rand()%i);
	return i;
}
struct card* getcard(int i,struct card* ph)                  //取牌    输入随机数  牌 
{
	int j;
	struct card* p1;
	p1=ph;
	
	for(j=1;j<i;j++)
	{
		p1=ph->pnext;
	}
	return p1;
}
void dropcard(int i,struct card* ph)                                //牌转移 
{
	int n;
	struct card* p1;
	struct card* p2;
	p1=ph;
    p2=ph->pnext;
	for(n=1;n<i-1;n++)
	{
		p1=p1->pnext;
		p2=p2->pnext;
	}
	if(i==1)
	{
		ph=ph->pnext;
		free(p1);
	}
	else
	{
	    p1->pnext=p2->pnext;
	    free(p2);
    }
}
int y_reaction(int i,int Value,struct card* pHead)                                 //输入Y 
{
	struct card* temp;
	printf("OK\n");
	temp=getcard(i,pHead);
	printf("%s\n%c",temp->shape,temp->face);
	dropcard(i,pHead);
	Value+=temp->value;
	return Value;
}
int player(int left,char s,struct card* phead)
{
	int j;
	int value;
	printf("Get it rolling");
	for(j=0;j<1;j++)
	{
	    	if(s=='y')
	    	{
	    	    y_reaction(order(left),value,phead);
	     	    value=y_reaction(order(left),value,phead);
	    	}
	    	if(s=='n')
	    	{
	    	    printf("not bad\n");
	    	    value=0;
	    	}
	    	else
	    	{
	    	    printf("exm");
	    	    j--;
	    	}
    }       
    return value;
}
void deletecard(struct card* p)                               //清场 
{
	struct card* p1;
	struct card* p2;
	p1=p;
	while(p1->pnext!=NULL)
	{
		p2=p1->pnext;
		free(p1);
		delete(p2);
	}
}
int main()
{
    int Left=50;
	struct card* pHead=create();
	char c;
	int v1,v2;
	v1=y_reaction(52,0,pHead);
	v2=y_reaction(51,0,pHead);
	printf("COME ON");
	for(;;)
	{
		if(v1>21)
		{
	 	    printf("YOU LOSE\n%d %d",v1,v2);
	 	    getchar();
	 	    deletecard(pHead);
	 	    exit(0);
	 	}
		if(v2>21)
		{
			printf("YOU WIN\n%d %d",v1,v2);
		    getchar();
		    deletecard(pHead);
		    exit(0);
	    }
		printf("your choice(y/n/q)");
		scanf("%c",&c);
		if(c=='q')
		{
			printf("bye");
			if(v1>v2)
		        printf("YOU WIN\n%d %d",v1,v2);
		    if(v1<v2)
		        printf("YOU LOSE\n%d %d",v1,v2);
			if(v1=v2)
			    printf("push\n%d %d",v1,v2);
			getchar();
			deletecard(pHead);
			exit(0);
		}
		else
		    v1=player(Left,c,pHead);
		if(c=='y');
		    Left--;
		if(v2>18)
		    v2=player(Left,'n',pHead);
		else
		{
			if(v2<v1)
			{
			    v2=player(Left,'y',pHead);
			    Left--;
			}
		}
	}
	    getchar();
	    deletecard(pHead);
		exit(0);
}
