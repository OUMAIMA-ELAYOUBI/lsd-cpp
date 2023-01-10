#include <iostream>
#include <vector>
#include<array>
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



int ifexist(int x, vector<int> l)
{
    int test=0;
    if(l.empty()==true)
            test=0;
    else
    {
        for(int i =0 ;i<l.size();i++)
        {
            if(l.at(i)==x)
            {
               // test=1;
               // break;
                return 1;
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


const int n =6;


vector<int> explore(array<array<int,n> ,n> x, vector<int> path, int a)
{
    vector<int> s;
    s.push_back(a);
    path.push_back(a);

    while (!s.empty())
    {
        int y = s.front();
        s.erase(s.begin());
        for (int i = 0; i < n; i++)
        {
            if (x[y][i]==1 && !ifexist(i, path))
            {
                s.push_back(i);
                path.push_back(i);
           
            }
        }
    }
    return path;
}





paths allLinked ( array<array<int,n> ,n> x)
{
    paths  result= {NULL,NULL};
    vector<int> path;
    vector<int> visited(n,0);
    vector<int> v=explore( x, path, 0);
    push(v,&result);
     for(int i=0;i<v.size();i++)
      {
          int j=0;
          j=v[i];
          visited[j]=1;
      }
            v.clear();
    
    for (int i = 1; i < n; i++)
    {
        // If node i has not been visited, explore all linked components from i
        if (visited[i]==0)
        { 
           vector<int> v=explore( x, path, i);
            push(v,&result);
            for(int i=0;i<v.size();i++)
            {
                int j=0;
                j=v[i];
                visited[j]=1;
            }
            v.clear();

        }
        
    }
    return result;

}



int main()
{
array<array<int,n>,n> x = {{
{0,1,1,0,0,0},
{1,0,1,0,0,0},
{1,1,0,0,0,0},
{0,0,0,0,1,0},
{0,0,0,1,0,0},
{0,0,0,0,0,0}}};
  
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
    S= allLinked(x);
    cout<<"Linked components "<<endl;
    PRINTPATHS(S);
    
    
}
