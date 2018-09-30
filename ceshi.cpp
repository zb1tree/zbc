#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int left=50;
struct card
{
	char shape[];
	char face;
	int value;
	struct card* pnext;
};
struct card* create()                                       //发牌 返回头 
{
	struct card *pnew,*pend,*phead;
	phead=pnew=pend=(struct card*)malloc(sizeof(struct card));
	int i,j;
	for(i=1;i<53;i++)
	{
		switch
		{
			case i<14:
			pnew->shape="spade";
			break;
			case i<27:
			pnew->shape="heart";
			break;
			case i<40:
			pnew->shape="diamond";
			break;
			case i<53:
			pnew->shape="club";
		}
		switch
		{
			case 1<(i%13)<11:
			pnew->face=i;
			break;
			case (i%13)==1:
			pnew->face=A;
			break;
			case (i%13)==11:
			pnew->face=J;
			break;
			case(i%13)==12:
			pnew->face=Q;
			break;
			case (i%13)==13:
			pnew->face=K;
		}
		switch
		{
			case (i%13==0)||(i%13>=10):
			pnew->value=10;
			break;
			case i%13==1:
			pnew->value==11;
			break;
			default:
			pnew->value=i;
		}
		pnew=(struct card*)malloc(sizeof(struct card));
		pend->pnext=pnew;
		pend=pnew;
		pnew->pnext=NULL;
	}
	free(pnew);
	return phead;
}
int order(int i)                                             //剩余牌数 返回随机值（未完成） 
{
	
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
int y_reaction(int i,int Value)                                 //输入Y 
{
	struct card* temp;
	printf("OK\n");
	temp=getcard(i,pHead);
	printf("%s\n%c",temp->shape,temp->face);
	dropcard(i,struct card* pHead);
	Value+=temp->value;
	return Value;
}
void dropcard(int i,struct card* ph)                                //牌转移 
{
	int n;
	struct card* p1,p2;
	p1=ph;
    p2=ph->pnext;
	for(n=1;n<i-1;n++)
	{
		p1=p1->pnext;
		p2=p2->pnext;
	}
	if(i==1)
	{
		ph=ph->next;
		free(p1);
	}
	else
	{
	    p1->pnext=p2->pnext;
	    free(p2);
    }
}
int player(int left,char s)
{
	int j;
	int value;
	printf("Get it rolling");
	for(j=0;j<1;j++)
	{
	    switch
	    {
	    	case s=='y':
	    	y_reaction(order(left));
	    	value=y_reaction;
	    	break;
	    	case s=='n':
	    	printf("not bad\n");
	    	value=0;
	    	break;
	    	default:
	    	printf("exm");
	    	j--;
	    }
    }
    return value;
}
void main()
{
	struct card* pHead=create()
	char c;
	int v1,v2;
	v1=y_reaction(52);
	v2=y_reaction(51);
	printf
	printf("COME ON");
	for(;;)
	{
		switch
		{
			case v1>21:
			printf("YOU LOSE\n%d %d",v1,v2);
			break;
			case v2>21:
			printf("YOU WIN\n%d %d",v1,v2);
			break;
			default:
			break;
		}
		printf("your choice(y/n/q)");
		scanf("%c",&c);
		if(c=='q')
		break;
		else
		v1=player(Left,c);
		if(c=='y');
		Left--;
		v2=player(Left,c);
		if(c=='y');
		Left--;
	}
	switch
		{
			case v1>v2:
		    printf("YOU WIN\n%d %d",v1,v2);
		    break;
		    case v1<v2:
		    printf("YOU LOSE\n%d %d",v1,v2);
			break;
			case v1=v2:
			printf("push\n%d %d",v1,v2);
		}
		return 0;
}
