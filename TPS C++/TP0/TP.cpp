#include <iostream>

using namespace std;

struct node
{
    int element;
    struct node * next;
};
typedef struct node node;
typedef node * stack;


void PRINT(stack P)
{
    stack temp=P;
    while(temp->next!=NULL)
    {
        printf("%d, ",temp->element);
        temp=temp->next;
    }
    if(temp!=NULL)
        printf("%d\n",temp->element);
}

void push(int x,stack * P)
{
    stack C=(stack)malloc(sizeof(node));
    C->element=x;
    C->next=*P;
    *P=C;
    return;
}

int pop(stack * P)
{
    if(*P!=NULL)
    {
        int res=(*P)->element;
        stack temp=*P;
        *P=(*P)->next;
        free(temp);
        return res;
    }
    else
        exit(EXIT_FAILURE);
}

int len(stack P)
{
	int n =0;
	stack temp =P;
	while(temp!=NULL)
	{
		n++;
		temp=temp->next;
	}
	return n;
}

void reverse(stack * P , int i , int j)
{
    int n= len(*P);
    stack temp=*P;
    stack temp1=NULL;
    stack temp2=NULL;
    stack temp3=NULL;
    int k=0;
    while(k<i)
        {
        push (pop(&temp),&temp1);
        k++;
        }
    k=i;
     while(k<j+1)
        {
        push (pop(&temp),&temp2);
        k++;
        }
    k=i;
    while(k<j+1)
        {
        push (pop(&temp2),&temp1);
        k++;
        }
    k=j+1;
    while(k<n)
        {
         int res = pop(&temp);
         push(res,&temp1);
         k++;
        }
  
    while(temp1!=NULL)
    {
        push(pop(&temp1),&temp3);
    }
    *P=temp3;
}


void reverse_link(stack * P , int k)
{
	int n=len(*P);
	int r=n%k;
    stack temp=*P;
    int i;
	for (i=0; i<n-r ; i+=k)
    {
        reverse(&temp,i ,i+k-1);
    }
    reverse(&temp,n-r, n-1);
    *P=temp;

}

int check(int x, stack P)
{
    stack temp= P;
    while(temp != NULL)
    {
        if (temp->element == x)
            return 1;
        temp=temp->next;
    }
    return 0;
}

stack elm_doubl(stack P)
{
    int n=len(P);
    stack L= NULL;
    for(int i=0;i<n ; i++)
    {
        int res = pop(&P);
        if (not(check(res,L)))
            push(res,&L);
    }
    stack P2=NULL;
    while(L!=NULL)
    {
        push(pop(&L),&P2);
    }
    return P2;
    
}




int main()
{
stack P=NULL;
    
    push(2,&P);
    push(3,&P);
    push(4,&P);
    int res=pop(&P);
    int res1= pop(&P);
    push(8,&P);
    push(9,&P);
    push(0,&P);
    push(11,&P);
    push(0,&P);
    push(5,&P);
    reverse_link(&P,3);
    PRINT(P);
    stack L=elm_doubl(P);
    PRINT(L);

    return 0;
    
}
