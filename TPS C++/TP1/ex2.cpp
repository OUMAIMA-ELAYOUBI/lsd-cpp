
#include <iostream>
using namespace std;

typedef struct point
{
    int element;
    struct point* suivant;
  
}point ;

// link is list of points 

typedef struct link
{
    point * start;
    point * end;
    unsigned len;
}link;


 
typedef struct cellule
{
    link lien;
    struct cellule * next;

}cellule; 


typedef struct queue

{
    cellule * debut;
    cellule * fin;

} queue;

int len(queue Q)
{
    int n=0;
    queue temp=Q;
    while(temp.debut!=NULL)
    {
        n++;
        temp.debut=temp.debut->next;
    }
    return n;
        
}



int ifexist(int x, link l)
{
    int test=0;
    if(l.start==NULL && l.len==0)
            test=0;
    else
    {
        link temp = l;
        while(temp.start!=NULL)
        {
            if(temp.start->element==x)
                test=1;
            temp.start=temp.start->suivant;
        }
    }   
  return test;
}



void ajoutFin(int x,link *l)
{
    if(ifexist(x,*l)==0)
    {
        point * c=(point *)malloc(sizeof(point));
        c->element=x;
        c->suivant=NULL;
    
        if(l->start==NULL && l->len==0)
        {
            (*l).start=c;
            (*l).end=c;
            l->len=1;
            return;
    
        } 
        else
        {   
            (*l).end->suivant=c;
            (*l).end=c;
            l->len+=1;
        return;
        }
    }
    else
        return;
}



int queueVide(queue Q)
{
    if(Q.debut==NULL)
        return 1;
    else
        return 0;
}



void enfiler(link l,queue * Q)
{
    cellule * C=(cellule *)malloc(sizeof(cellule));
    C->lien=l;
    C->next=NULL;

    if(queueVide(*Q)==1)
    {
        (*Q).debut=C;
        (*Q).fin=C;
    }
    else
    {
  
        Q->fin->next=C;
        (*Q).fin=C;
    }
}




void affichageroute(link l)
{
    
    if(l.start==NULL && l.len==0)
    {
        printf("[]\n");
        return;
    }


    point *temp=l.start;
    printf("(");
    while(temp->suivant!=NULL)
    {
        printf("%d --> ",temp->element);
        temp=temp->suivant;
    }
    if(temp!=NULL)
        printf("%d",temp->element);
    printf(")\n");
}




void affichagequeue(queue Q)
{
    if(queueVide(Q)==1)
    {
        printf("[]\n");
        return;
    }

    

    cellule * temp=Q.debut;
    printf("[\n");
    while(temp->next!=NULL)
    {
        affichageroute(temp->lien);
        temp=temp->next;
    }
    if(temp!=NULL)
        affichageroute(temp->lien);
    printf("]\n");
}










queue allLinked (int n , queue Q)
{
    queue temp=Q;
    queue   result={NULL,NULL};
    int visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    for(int j=0;j<n;j++)
    {
        if(visited[j]==0)
        {
            link l={NULL,NULL,0};
            ajoutFin(j+1,&l);
            enfiler(l,&result);
            while(temp.debut!=NULL)
            {   
                if(l.end->element==temp.debut->lien.start->element)
                {
                    if (ifexist(temp.debut->lien.end->element,l)==0)
                    {
                         ajoutFin(temp.debut->lien.end->element,&l);
                         visited[temp.debut->lien.end->element-1]=1;
                    }
                }
                temp.debut=temp.debut->next;
            }
            temp=Q;
        }
    }
    return result;

}



int main()
{
    int x[6][6] = {{0,1,1,0,0,0},{1,0,1,0,0,0},{1,1,0,0,0,0},{0,0,0,0,1,0},{0,0,0,1,0,0},{0,0,0,0,0,0}};
    link l = { NULL,NULL,0};
    queue Q = {NULL,NULL};
    queue S = {NULL,NULL};
    for(int i=0 ; i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if (x[i][j]==1)
            {
                 ajoutFin(i+1,&l);
                 ajoutFin(j+1,&l);
                 enfiler(l,&Q);
                 l={ NULL,NULL,0};
            }
        }
    }

    affichagequeue(Q);
    S= allLinked(6,Q);
    cout<<"Linked components "<<endl;
    affichagequeue(S);
    
}
