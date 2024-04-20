#include<iostream>
#include<fstream>
using namespace std;

void registration();
void login();
void logout_page();

int main()
{
	cout << "------------------------------\n";
	cout << "|  Welcome to Group B!       | \n";
	cout << "| What would you like to do? | \n";
	cout << "------------------------------\n";
	int choice;
    cout<<"-To register a new account, press 1! \n"<<endl;
    cout<<"-To login into an existing account, press 2! \n"<<endl;
    cout<<"-To exit program, press 3! \n"<<endl;
    cin>>choice;

    //This block of code represents the choices that can be accessed in the system.
    //The Switch statement is used here so that the user may choose whhich option they
	//want to choose by inserting a value to get the option.  
	switch(choice)
    {
        case 1:
            registration();
            //The main() is called so that the user can login into their account after registering.
			main(); 
            break;

        case 2:
            login();
            break;

        case 3:
            return 0;
            break;

        default:
            system("cls");
            cout<<"Sorry, option not recognised";
            main();
    }
}


void registration ()
{
	//This block of code is to accept the users username and password
	string username,password;
	cout<<"Please create a username: \n"<<endl;
	cin>>username;
	cout<<"Please create a password: \n"<<endl;
	cin>>password;
	
	//This block of code is to check wether the same username has already been taken.
    ifstream f1_in("Username.txt", ios::in);
    ifstream f2_in("Pass.txt", ios::in);
	string username_in_txt,ary_uname[100];
	while (getline(f1_in, username_in_txt))
    {
    	//If the username entered by the user already exists in the Username.txt file,
    	//then, it will output a message. 
        if (username_in_txt==username) 
        {
            cout<<"Username has been taken. Please create a different username."<<endl;
            return registration();
        }
    }

    //This block of code is to write the respective username and passwords into the 
    //respective .txt files.
	ofstream f1_out("Username.txt", ios::app);
    ofstream f2_out("Pass.txt", ios::app);
    f1_out<<username<<endl;
    f2_out<<password<<endl;
    system("cls");
    cout<<"============================"<<endl;
    cout<<"||Registration successful!||"<<endl;
    cout<<"============================"<<endl;
}


void login()
{
    string username,password;

    cout << "Please enter your username: ";
    cin >> username;

    cout << "Please enter your password: ";
    cin >> password;

    //The following block of codes is to check the number of lines in username.txt.
    ifstream f1_in_0("Username.txt", ios::in);
    string username_in_txt;
    int no_of_lines=0;
    //While there is something in the specific line.
	while (getline(f1_in_0,username_in_txt)) 
    no_of_lines+=1;
    //One has to be minuzed so that i=0. i has to be zero because array counts from zero.
	no_of_lines-=1;
    f1_in_0.close();

    string ary_userN[100],pass,ary_pass[100];
    ifstream f1_in("Username.txt", ios::in);
    ifstream f2_in("Pass.txt", ios::in);
    int i=0;
    //When it is not an empty line.
	while (i<=no_of_lines) 
    {   getline(f1_in,username_in_txt); //This code is to read the line.
        ary_userN[i]=username_in_txt; //This code is to insert the username into the .txt file as an array one by one.
        if (ary_userN[i]==username) //If username entered by the user was found in the .txt file...
        {
            for (int j=0; getline(f2_in,pass);j++) //This code is to check if the password matches the username.
            {
                ary_pass[j]=pass; //This code is to insert the password into the .txt file as an array one by one.
                if (j==i) //This is because the set of user credentials are stored in the same no.of lines in both txt files.
                {
                    if (ary_pass[j]==password) //This block of code is if the password and username matches.
                    {   cout<<"ok"<<endl;
                        system("cls");
                        cout<<"------------------------------\n";
                        cout<<"Welcome "<<username<<" ! \n"; 
                        cout<<"------------------------------\n";
                        cout<<"To log out, press 1!"<<endl;
                        int choice;
                        cin>>choice;
                        if (choice==1)
                            return logout_page();
                    }

                    else
                    //This block of code is if the password and username entered did not match.
                    {
                        cout<<"Invalid username or password. Please try again."<<endl; 
                        return login();
                    }

                }
            }
        }
        if (i==no_of_lines)
        {cout<<"Username not found"<<endl;
        return login();}
    i+=1;
    }



}

void logout_page()
{
    string logout;
    cout<<"Are you sure you would like to logout? Type in Yes if you would: \n";
    cin>>logout;
    cout<<endl;
    if(logout=="Yes"|| logout=="YES"||logout=="yes")
    {
        cout<< "Account logged out. We hope to see you again soon! "<<endl;
        main();
    }
    else
    {
        cout<< "Logout unsuccessful, please try again! \n";
        logout_page();

    }
}
