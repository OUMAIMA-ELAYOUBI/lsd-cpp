# include "exam.hpp"

void library::add()
{
    if(NB_books>8)
        NB_books=0;
    string s1 , s2, s3;
    long int s4;
    cout<<"book name : "<<endl;
    cin>>s1;
    cout<<"author name: "<<endl;
    cin>>s2;
    cout<<"link : "<<endl;
    cin>>s3;
    cout<<" ISBN : "<<endl;
    cin>>s4;
    books_array[NB_books].set_name(s1);
    books_array[NB_books].set_author(s2);
    books_array[NB_books].set_link(s3);
    books_array[NB_books].set_ISBN(s4);
    set_NB(NB_books+1);
    

}

void library::search(int i)
{
    cout<<"library : "<<endl;
    DISPLAY();
    if(i>NB_books || i<1)
        cout<<"wrong index "<<endl;
    book K=books_array[i-1];
    K.display_details(i-1);
}


void library::exit()
{
    books_array={};
}


int main()
{
    library A;
    int j=0;
    while(j<3)
    {
        cout<<"insert 1 to add a book , 2 to search for a book , 3 to exit"<<endl;
        cin>>j;
        if(j==1)
            A.add();
        if(j==2)
        {
            int index;
            cout<<"index : "<<endl;
            cin>>index;
            A.search(index);
        }
        if(j==3)
            A.exit();
    }

}
