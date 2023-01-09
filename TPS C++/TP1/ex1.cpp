#include <iostream>
#include <vector>
using namespace std;


typedef struct cellule
{
    vector<int> path;
    struct cellule * next;

}cellule; 


typedef struct paths

{
    cellule * start;
    cellule * end;

} paths;

int len(paths Q)
{
    int n=0;
    paths temp=Q;
    while(temp.start!=NULL)
    {
        n++;
        temp.start=temp.start->next;
    }
    return n;
        
}

int ifexist(int x, vector<int> l)
{
    int test=0;
    if(l.empty()==true)
            test=0;
    else
    {
        for(int i =0 ;i<l.size();i++)
        {
            if(l[i]==x)
            {
                test=1;
                break;
            }
        }
    }   
  return test;
}

int paths_empty(paths Q)
{
    if(Q.start==NULL)
        return 1;
    else
        return 0;
}



void push(vector<int> l,paths * Q)
{
    cellule * C=new cellule;
    C->path=l;
    C->next=NULL;

    if(paths_empty(*Q)==1)
    {
        (*Q).start=C;
        (*Q).end=C;
    }
    else
    {
  
        (*Q).end->next=C;
        (*Q).end=C;
    }
    return;
}




void PRINT(vector<int> l)
{
    
    if(l.empty()==true )
    {
        printf("[]\n");
        return;
    }
    int n=l.size();
    for(int i =0 ;i<n-1;i++)
    {
        printf(" %d --> ",l[i]);
    }
    printf("%d\n",l[n-1]);
}




void PRINTPATHS(paths Q)
{

    if(paths_empty(Q)==1)
    {
        printf("[]\n");
        return;
    }

    cellule * temp=Q.start;
    printf("[\n");
    while(temp->next!=NULL)
    {
        PRINT(temp->path);
        temp=temp->next;
    }
    if(temp!=NULL)
        PRINT(temp->path);
    printf("]\n");
}



vector<int> pop(paths * Q)
{
    vector<int> res;
    if(paths_empty(*Q)==1)
    {
        return {};
    }
    else
    {
        res=Q->start->path;
        cellule * temp=Q->start;
        Q->start=Q->start->next;
        delete(temp);
      
    }
    return res;
}




paths allshortests(paths Q , int source, int destination)  
{
    int countshort =0;
    unsigned n=0;
    paths essai={NULL,NULL}, result={NULL,NULL},temp=Q,temp1=Q;
    while(temp.start!=NULL)
    {
        if(temp.start->path[0]==source)
            {
            push(temp.start->path,&essai);
            }
        temp.start=temp.start->next;
    }
    while(essai.start!=NULL)
    {
        vector<int> res=pop(&essai);
        
        if(res.back()==destination)
         {
            
            if(paths_empty(result)==0)
            {
                n = result.start->path.size();
                if(res.size()>n)
                {
                            return result;          
                }
            }
            push(res,&result);
            countshort+=1;
       }
        
        else
        {
            
            while(temp1.start!=NULL)
            {

                if(res.back()==temp1.start->path[0]) 
               { 
                        vector<int> res1=res;
                        int m=ifexist(temp1.start->path.back(),res1);
                        
                        if (m==0)
                        {
                            res1.push_back(temp1.start->path.back());
                            push(res1,&essai);
                        }
               } 
              temp1.start=temp1.start->next;
            } 
             temp1= Q;  
        }
    }
    if(essai.start==NULL)
    {
        return result;
        
    }
  return paths();  

}

int main()
{
    int x[6][6] = {{0,1,1,0,0,0},{1,0,1,0,0,0},{1,1,0,1,0,0},{0,0,0,0,1,0},{0,0,0,1,0,0},{0,0,0,0,0,0}};
    vector<int> l;
    paths Q = {NULL,NULL};
    paths S = {NULL,NULL};
    for(int i=0 ; i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if (x[i][j]==1)
            {
                 l.push_back(i+1);
                 l.push_back(j+1);
                 push(l,&Q);
                 l.clear();
            }
        }
    }

   
 
    PRINTPATHS(Q);
    S=allshortests( Q , 1, 5);
    PRINTPATHS(S);
    
    

}
