#include<stdio.h>
#include<stdlib.h>
#include<time.h>
static int I;
struct card
{
	string shape[];
	char face;
	int value;
	struct card* pnext;
};
struct card *create()
{
<<<<<<< HEAD
	struct card* pnew,pend,phead;
	phead=pnew=pend=(struct card*)malloc(sizeof(struct card));
	int i,j;
	for(i=1;i<53;i++)
	{	
		if(i<14)
		    pnew->shape[]="spade";
		if(i<27)
		    pnew->shape[]="heart";
		if(i<40)
		    pnew->shape[]="diamond";
		if(i<53)
		    pnew->shape[]="club";		
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
=======
	struct card *pnew,*pend,*phead;
	phead=pnew=pnext=(struct card*)malloc(struct card);
	int i,j;
	for(i=1;i<53;i++)
	{
		switch
		{
			case i<14;
			pnew_>shape=spade;
			break;
			case i<27;
			pnew_>shape=heart;
			break;
			case i<40;
			pnew_>shape=diamond;
			break;
			case i<53;
			pnew_>shape=club;
		}
		switch
		{
			case 1<(i%13)<11;
			pnew_>face=i;
			break;
			case (i%13)==1;
			pnew_>face=A;
			break;
			case (i%13)==11;
			pnew_>face=J;
			break;
			case(i%13)==12;
			pnew_>face=Q;
			break;
			case (i%13)==13;
			pnew_>face=K;
		}
		switch
		{
			case (i%13==0)||(i%13>=10);
			pnew_>value=10;
			break;
			case i%13==1;
			pnew_>value==11;
			break;
			default;
			pnew_>value=i;
>>>>>>> a44adadff306eab90749cc4235a82750aafc8243
		}
		pnew=(struct card*)malloc(struct card);
		pend_>pnext=pnew;
		pend=pnew;
<<<<<<< HEAD
		pnew->pnext=NULL;
	free(struct card* pnew);
	return phead;
}
int order(int i)                                             //剩余牌数 返回随机值 
=======
		pnew_>pnext=NULL;
	}
	free(pew);
	return phead;
}
int order(int i)
>>>>>>> a44adadff306eab90749cc4235a82750aafc8243
{
	int j;
	srand((unsigned int)time(NULL));
	j=(rand()%i);
	return i;
}
struct card* getcard(int i,struct card* ph)
{
	int j;
	struct card* p1;
	p1=ph;
	
	for(j=1;j<i;j++)
	{
		p1=ph_>pnext;
	}
	return p1;
}
int y_reaction(int i,int Value)
{
	struct card *temp;
	printf("OK");
	temp=getcard(i);
	printf("%s\n%c",temp_>shape,temp_>face);
	dropcard(i);
	Value+=temp_>value;
	return Value;
}
void dropcard(int i,struct card* ph)
{
	int n;
	struct card* p1,p2;
	p1=ph;
    p2=ph_>pnext;
	for(n=1;n<i-1;n++)
	{
		p1=p1_>pnext;
		p2=p2_>pnext;
	}
	if(i==1)
	{
		ph=ph_>next;
		free(ph);
	}
	else
	{
	    p1_>pnext=p2_>pnext;
	    free(p2);
    }
}
int game(int left)
{
	char C;
	int j;
	int value=0;
	printf("Get it rolling");
	for(j=0;j<1;j++)
	{
<<<<<<< HEAD
	    	if(s=='y')
	    	{
	    	    y_reaction(order(left));
	     	    value=y_reaction;
	    	    break;
	    	    if(s=='n')
	    	}
	    	if(s=='n')
	    	{
	    	    printf("not bad\n");
	    	    value=0;
	    	    break;
	    	}
	    	else
	    	{
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
	
	    {
			if(v1>21):
		 	    printf("YOU LOSE\n%d %d",v1,v2);
			if(v2>21):
			    printf("YOU WIN\n%d %d",v1,v2);
		}
		printf("your choice(y/n/q)");
		scanf("%c",&c);
		if(c=='q')
		{
			printf("bye");
		    break;
		}
		else
		    v1=player(Left,c);
		if(c=='y');
		    Left--;
		v2=player(Left,c);
	    if(c=='y');
		    Left--;
	}
			if(v1>v2)
		        printf("YOU WIN\n%d %d",v1,v2);
		    if(v1<v2)
		        printf("YOU LOSE\n%d %d",v1,v2);
			if(v1=v2)
			    printf("push\n%d %d",v1,v2);
		return 0;
}
=======
	    scanf("%c",&C);
	    switch
	    {
	    	case C=='y';
	    	y_reaction(order(left));
	    	left--;
	    	value+=y_reaction;
	    	break;
	    	case C=='n';
	    	printf("not bad");
	    	break;
	    	case C=='q';
	    	printf("bye");
	    	break;
	    	default;
	    	printf("exm");
	    	j--;
	    }
    }
    return value;
}
>>>>>>> a44adadff306eab90749cc4235a82750aafc8243
