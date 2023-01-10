#include <iostream>
#include <string>
#include <array>

using namespace std;

class book
{
    private:
        string name;
        string author;
        string link;
        long int ISBN;
    public:
        string get_name(){return name;}
        string get_author(){return author;}
        void set_name(string s){name = s;}
        void set_author(string s){author=s;}
        void set_link(string s){link=s;}
        void set_ISBN(long int s){ISBN=s;}
        void display(int i);
        void display_details(int i);
    friend class library;    
};

class library
{
    private:
    std::array<book,8> books_array{};
    int NB_books=0; 
    public:
        void add();
        void search(int i);
        void exit();
        void DISPLAY();
        int get_NB(){return NB_books;}
        void set_NB(int N){NB_books=N;}
     
        
    
};


void PRINT(string s)
{
    int n=s.length();
    if (n<10)
    {
        int c=(10-n)/2;
        if((10-n)%2==0)
        {
            cout<<std::string(c,' ')<<s<<std::string(c,' ')<<'|';
        }
        else 
            cout<<std::string(c+1,' ')<<s<<std::string(c, ' ')<<'|';

    }
    else
    {
    cout<<s.substr(0,9)<<'.'<<'|';
    }
}



void book::display(int i)
{
   PRINT(to_string(i+1));
   PRINT(get_name());
   PRINT(get_author());
   cout<<'\n'; 
}

void book::display_details(int i)
{
    cout<<"index : "<<i+1<<endl;
    cout<<"name : "<<get_name()<<endl;
    cout<<"author : "<<get_author()<<endl;
    cout<<'\n';
}


void library::DISPLAY()
{
    PRINT("index");
    PRINT("name");
    PRINT("author");
    cout<<"\n";
    for(int i =0 ; i<get_NB(); i++)
    {
         books_array[i].display(i);
        
    }

}
