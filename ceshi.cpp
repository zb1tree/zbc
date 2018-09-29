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
		}
		pnew=(struct card*)malloc(struct card);
		pend_>pnext=pnew;
		pend=pnew;
		pnew_>pnext=NULL;
	}
	free(pew);
	return phead;
}
int order(int i)
{
	
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
