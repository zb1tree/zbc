#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
struct card
{
	char shape[8];
	char face[3];
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
	int i;
	float j;
	
	for(i=1;i<53;i++)
	{	
	    switch ((int)(floor((i-1)/13)))
	    {
		case 0:
		    strcpy(pnew->shape,"spade  ");
		    break;
		case 1:
		    strcpy(pnew->shape,"heart  ");
		    break;
		case 2:
		    strcpy(pnew->shape,"diamond");
		    break;
	    case 3:
		    strcpy(pnew->shape,"club   ");
		    break;
		}
		switch(i%13)
		{
			case 1:
			strcpy(pnew->face,"A ");
			break;
			case 11:
		    strcpy(pnew->face,"J ");
		    break;
		    case 12:
		    strcpy(pnew->face,"Q ");
		    break;
            case 0:
		    strcpy(pnew->face,"K ");
		    break;
            case 2:
            strcpy(pnew->face,"2 ");
			break;
			case 3:
            strcpy(pnew->face,"3 ");
			break;
			case 4:
            strcpy(pnew->face,"4 ");
			break;
			case 5:
            strcpy(pnew->face,"5 ");
			break;
			case 6:
            strcpy(pnew->face,"6 ");
			break;
			case 7:
            strcpy(pnew->face,"7 ");
			break;
			case 8:
            strcpy(pnew->face,"8 ");
			break;
			case 9:
            strcpy(pnew->face,"9 ");
			break;
			case 10:
            strcpy(pnew->face,"10");
			break;
	    }
		 if((i%13==0)||(i%13>=10))
		     pnew->value=10;
		 else
		 {
		     if(i%13==1)
			     pnew->value=11;
		     else
		         pnew->value=(i%13);
		 }
		pnew=(struct card*)malloc(sizeof(struct card));
		pend->pnext=pnew;
		pend=pnew;
		pnew->pnext=NULL;
	}
	return phead;
}
int order(int i)                                             //剩余牌数 返回随机值
{
	printf("or\n");
	int j;
	srand((unsigned int)time(NULL));
	j=(rand()%i);
	return j;
}
struct card* getcard(int i,struct card* ph)                  //取牌    输入随机数  牌 
{
	printf("get\n");
	int j;
	struct card* p1;
	p1=ph;
	
	for(j=1;j<i;j++)
	{
		p1=p1->pnext;
	}
	return p1;
}
void dropcard(int i,struct card* ph)                                //牌转移 
{
	printf("DR\n");
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
int y_reaction_(int i,int Value,struct card* pHead)                                 //输入Y 
{
	printf("y_\n");
	struct card* temp;
	temp=getcard(i,pHead);
	printf("%s\n%s\n",temp->shape,temp->face);
	printf("==================================\n");
	Value+=temp->value;
	dropcard(i,pHead);
	return Value;
}
int y_reaction(int i,int Value,struct card* pHead)                                 //输入Y 
{
	printf("y-");
	struct card* temp;
	temp=getcard(i,pHead);
	Value+=temp->value;
	dropcard(i,pHead);
	return Value;
}
int AI(int left,char s,struct card* phead,int value)
{
	printf("AI\n");
	int j;
	for(j=0;j<1;j++)
	{
	    	if(s=='y')
	    	{
	    		printf("AI ch y");
	     	    value=y_reaction(order(left),value,phead);
	    	}
	    	else
	    	{
	    	    if(s=='n')
	    	    {
	    	    	printf("==========n");
	    	        value=0;
	    	    }
	        }
    }       
    return value;
}
int player(int left,char s,struct card* phead,int value)
{
	printf("pl\n");
	int j;
	for(j=0;j<1;j++)
	{
		s=(int)(s);
	    switch(s)
	    {
		    case 121:    	
	        printf("OK\n");
	        value=y_reaction_(order(left),value,phead);
	        break;
	        case 110:	
	        printf("not bad\n");
	        break;
		    default:
		    printf("exm\n");
		    s=getchar();
		    j--;
	    }
    }       
    return value;
}
void deletecard(struct card* p)                               //清场 
{
	printf("DE\n");
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
	struct card* pHead;
	pHead=create();
	char c;
	int v1,v2;
	v1=y_reaction_(order(52),0,pHead);
	v2=y_reaction(order(51),0,pHead);
	printf("COME ON\n");
	for(;;)
	{
		printf("for\n");
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
	    printf("=============%c\n",c);
		printf("your choice(y/n/q)\n");
		c=getchar();
		getchar();
		c=(int)(c);
		printf("%c",c);
		switch (c)
		{
			case 113:
			printf("bye\n");
			if(v1>v2)
			{
		        printf("YOU WIN\nYOU:%d AI:%d",v1,v2);
		    }
		    else
		    {
		    	if(v1<v2)
		        printf("YOU LOSE\nYOU:%d AI:%d",v1,v2);
                else
			    printf("push\nYOU:%d AI:%d",v1,v2);
			}
			deletecard(pHead);
			exit(0);
		    case 121:
		    	printf("y\n");
		    v1=player(Left,'y',pHead,v1);
		    Left--;
		    break;
		    case 110:
		    	printf("n\n");
		    v1=player(Left,'n',pHead,v1);
		    break;
		    default:
		    printf("===================exm \n");
		}
		if(v2>18)
		    v2+=AI(Left,'n',pHead,v2);
		else
		{
			if(v2<v1)
			{
			    v2=AI(Left,'y',pHead,v2);
			    Left--;
			}
		}
	}
}
