#include "CB.hpp"

void PHONEBOOK::add()
{
    if(NB_contacts >=8)
        NB_contacts =0;
  
    cout<<"\n first name :"<<endl;
    cin>>contacts_array[NB_contacts].first_name;
    cout<<"\n last name :"<<endl;
    cin>>contacts_array[NB_contacts].last_name; 
    cout<<"\n nickname :"<<endl;
    cin>>contacts_array[NB_contacts].nickname;
    cout<<"\n phone number :"<<endl;
    cin>>contacts_array[NB_contacts].phone_number;
    NB_contacts+=1;

}

void PHONEBOOK::search(int i)
{
    if(i > NB_contacts)
        cout<<"wrong index "<<endl;
    else
    {
        cout<<"phonebook :"<<endl;
        DISPLAY();
        cout<<"contact :"<<endl;
        CONTACT c = contacts_array[i-1];
        c.display_details(i-1);
    }
}

void PHONEBOOK::exit()
{
    contacts_array = {};
}

int main()
{
    PHONEBOOK phonebook ;
    int j=0;
    while(j<3)
    {
        cout<<"insert 1 to add a contact , 2 to search for a contact  , 3 to exit "<<'\n';
        cin>>j;
        if (j==1) phonebook.add(); 
        if(j==2)
        {
            int i=0 ;
            cout<<"index of contact "<<endl;
            cin>>i;
            phonebook.search(i);
        } 
        if(j==3) phonebook.exit();
    }
}




