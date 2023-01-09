#include <iostream>
#include <string>
#include <array>

using namespace std;

class CONTACT
{
    private:
        string first_name ;
        string last_name ;
        string nickname ;
        long int phone_number;
    public:
        void display(int i);
        void display_details(int i);
    friend class PHONEBOOK ;    
};

class PHONEBOOK
{
    private:
       std::array<CONTACT,8> contacts_array{};
        int NB_contacts;
    public:
        void add();
        void search(int i);
        void exit();
        void DISPLAY();
        PHONEBOOK():NB_contacts{0}{}
    
};


void PRINT(string s)
{
    int len = s.size();
    if (len < 10) {
        if((len-10)%2==0){
                int pad_len = (10 - len) / 2;
                cout << string(pad_len, ' ') + s+ string(pad_len, ' ') << '|'; 
                         }

        else             {
                int pad_len = (10 - len) / 2;
                cout << string(pad_len, ' ') + s+ string(pad_len+1, ' ') << '|';

                         }

                  }
    else{
           string s2=s.substr(0,9);
           cout<<s2<<'.'<<'|';
        }
}

void CONTACT::display(int i)
{
    cout.width(10);
	cout << ( to_string(i)) +"    "<<'|';
    PRINT(first_name);
    PRINT(last_name);
    PRINT(nickname);
    PRINT(to_string(phone_number));
    cout<<endl;
}

void CONTACT::display_details(int i)
{
    cout <<  "index: " << i << endl;
    cout <<  "first name: " << first_name << endl;
    cout <<  "last name: " << last_name << endl;
    cout <<  "nickname: " << nickname << endl;
    cout <<  "phone number:"<< phone_number << endl;
}

void PHONEBOOK::DISPLAY()
{
    cout<< "   index  " << '|';
    cout<< "firstname " << '|';
    cout<< "secondname" << '|';
    cout<< " nickname " << '|';
    cout<< "phone number" << '|';
    cout<<"\n";
    for (int i=0 ; i<NB_contacts ; i++)
    {
        contacts_array[i].display(i);
    }
}
