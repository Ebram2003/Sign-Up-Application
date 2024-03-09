#include<iostream>
#include<array>
#include<string>
enum class option
{
    ADDRECORD=1,
    FETCHRECORD,
    EXIT,
    ERRORSTATE
};
void print_msg(std::string msg);
const option User_Select();
std::istream & operator >> (std::istream &input_istream,  option &result)
{
    int input_option;
    input_istream>>input_option;
    result=static_cast<option>(input_option);
    return input_istream;
}
std::string operator+(int number, std::string text )
{
    std::string result=std::to_string(number).append(text);
    return result;
}
std::string to_string(const option opt);
class List
{
    public:
    std::array<option,3>options
    {option::ADDRECORD, option::FETCHRECORD, option::EXIT};
    void show()
    {
        print_msg("\nPlease select an option:\n");
        for (option op : options)
        {
            print_msg(to_string(op));
        }
    
    }
};

class User
{
    public:
    std::string Name="";
    int age=0;
    int ID=0 ;
    
    void Add_Record()
    {
        print_msg("Name: ");
        std::cin>>Name;
        print_msg("Age: ");
        std::cin>>age;
        print_msg(Name);
    }
    bool Fetch_Record(int UserID)
    {
        if(UserID)
        {
            
            return 1;
        }
        
        return 0;
    }
    void setID(const int User_ID)
    {
        ID=User_ID;
    }

    
};
constexpr option DEFAULT_OPTION = option::ERRORSTATE;
int main()
{
    std::array<User,10>Users;
    int index=0;
    List New_List;
    option Option;
    bool isRunning = true;
    int UserID=0;
    int Temp=0;
    print_msg("User SignUp Application\n");
    while(isRunning)
    {
        New_List.show();
        option Option=User_Select();
        UserID=0;
        switch (Option)
        {
        case option::ADDRECORD:
            print_msg("\nAdd User. Please enter your name and age:\n");
            Users[index].Add_Record();
            Users[index].setID(index+1);
            index++;
            break;
        case option::FETCHRECORD:
            print_msg("\nPlease enter User ID: ");
            std::cin>>UserID;
            if(Users[UserID-1].Fetch_Record(UserID)==1)
            {
                print_msg("\nYour ID is: "+ std::to_string(Users[UserID-1].ID));
                print_msg("\nYour Name is: "+ Users[UserID-1].Name);
                print_msg("\nYour Age is "+ std::to_string(Users[UserID-1].age));
            }
            break;
        case option::EXIT:
            isRunning=false;
            break; 
        default:
            break;
        }      
    }
}
void print_msg(std::string msg)
{
    std::cout << msg;
}
std::string to_string(const option opt)
{
   switch (opt)
    {
    case option::ADDRECORD:
        print_msg("1: Add Recodrd\n");
        break;
    case option::FETCHRECORD:
        print_msg("2: Fetch Recodrd\n");
        break;
    case option::EXIT:
        print_msg("3: Quit\n");
        break;
    default:
        print_msg("Invalid choice , try again\n");
        break;
    }
    return "";
}
const option User_Select()
{

    option option = DEFAULT_OPTION;
    std::cin>>option;
    return option;
}
