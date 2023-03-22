#include <iostream>
#include<conio.h>
#include <fstream>
using namespace std;
class contact{
	private:
		char fname[50],lname[50],address[50],email[50];
		long long phno;
		public:
			void create_contact()
			{
			cout<<"enter your first name:";
			cin>>fname;
			cout<<"enter your last name:";
			cin>>lname;
			cout<<"enter phone:";
			cin>>phno;
			cout<<"enter address:";
			cin>>address;
			cout<<"enter email:";
			cin>>email;	
			}
			void show_contact()
			{
				cout<<"name:"<<fname<<" "<<lname<<endl;
				cout<<"phone:"<<phno<<endl;
				cout<<"address:"<<address<<endl;
				cout<<"email:"<<email<<endl;	
			}
			void writeonfile()
			{
				char ch;
				ofstream f1;
				f1.open("CMS.dat",ios::binary|ios::out);
				do
            {
				create_contact();
				f1.write(reinterpret_cast<char*>(this),sizeof(*this));
				cout<<"do you have next data?(y/n)";
	            cin>>ch;
	        }while(ch=='y');
	        cout<<endl<<endl<<"Contact Has Been Sucessfully Created...";
				f1.close();
			}
			void readonfile()
			{
                ifstream f2;
                cout<<"\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n";
				f2.open("CMS.dat",ios::binary|ios::in);
				while(!f2.eof())
        	{
	            if(f2.read(reinterpret_cast<char*>(this),sizeof(*this))>0)
	            {
				show_contact();
	            cout<<endl<<"=================================================\n"<<endl;
	        }
            }
            f2.close();
		}
			void searchfile()
			{
				fstream f3;
				long long phone;
				cout<<"enter phone no.:";
				cin>>phone;
				f3.open("CMS.dat",ios::binary|ios::in|ios::out);
				while(!f3.eof())
			{
				if(f3.read(reinterpret_cast<char*>(this), sizeof(*this))>0)
				{
						if (phone==phno)
						{
							show_contact();
							return;
						}
				}
			}
			cout<<"\n\n No record not found";
			f3.close(); 
			}
			void deletefile()
			{
				long long num;
				cout<<"enter phone no. to delete";
				cin>>num;
				fstream f4;
				ifstream f5;
				f5.open("CMS.dat",ios::binary);
				f4.open("temp.dat",ios::binary|ios::out);
				while(!f5.eof())
				{
					if(f5.read(reinterpret_cast<char*>(this),sizeof(*this))>0)
					{
						if(phno!=num)
						{
							f4.write(reinterpret_cast<char*>(this),sizeof(*this));
						}
				    }
			    }
				f5.close();
				f4.close();
				remove("CMS.dat");
				rename("temp.dat","CMS.dat");
				cout<<endl<<endl<<"\tContact Deleted...";
			}
			void edit_contact()
			{
				long long no;
				fstream f6;
				int n=0;
				cout<<"Edit contact\n===============================\n\n\t";
				cout<<"enter the phone number to be edit:";
				cin>>no;
				f6.open("CMS.dat",ios::binary|ios::out|ios::in);
				while(!f6.eof())
				{
					if(f6.read(reinterpret_cast<char*>(this),sizeof(*this))>0)
				    {
				        if (phno==no)
						{
							cout<<"Enter new record";
							create_contact();
							int pos=-1*sizeof(*this);
		                	f6.seekp(pos,ios::cur);
						f6.write(reinterpret_cast<char*>(this),sizeof(*this));
							cout<<endl<<endl<<"\t Contact Successfully Updated...";
							return;
						}
		}
	}
				cout<<"\n\n No record not found";
			    f6.close(); 
				}
		};
			int main()
			{
				system("cls");
	         system("color 03F");
	         cout<<"\n\n\n\n\n\n\n\n\t\t\t\t * WELCOME TO CONTACT MANAGEMENT SYSTEM *";
		getch();
		while(1)
		{
			contact c1;
		int choice;
			system("cls");
		system("color 03");
		cout<<"\n\t\t\t\t\t CONTACT MANAGEMENT SYSTEM";
        cout<<"\n\n\n\t\t\t\t\t\tMAIN MENU\n\t\t\t\t\t=====================\n";
        cout<<"\t\t\t\t\t[1] Add a new Contact\n";
        cout<<"\t\t\t\t\t[2] List all Contacts\n";
        cout<<"\t\t\t\t\t[3] Search for contact\n";
        cout<<"\t\t\t\t\t[4] Delete a Contact\n";
        cout<<"\t\t\t\t\t[5] Edit a Contact\n";
        cout<<"\t\t\t\t\t[0] Exit\n\t\t\t\t\t=================\n\t\t\t\t\t";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
        	case 1:
        		system("cls");
        		c1.writeonfile();
        		break;
        	case 2:
			system("cls");
        		c1.readonfile();
        		break;
			case 3:
        		system("cls");
        		c1.searchfile();
        		break;
        	case 4:
			     system("cls");
        		c1.deletefile();
        		break;	
        	case 5:
			    system("cls");
        		c1.edit_contact();
        		break;
        	case 0:
        		system("cls");
        		cout<<"\n\n\n\t\t\tThank you for using CMS."<<endl<<endl<<endl;
        		exit(0);
        		break;
        	default:
        	cout<<"\t\t\t\tINVALID CHOICE!!"<<endl;	
			cout<<"\t\tPlease enter the correct option!!"<<endl;
			break;	
		}
		int opt;
		cout<<"\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n";
		cin>>opt;
        system("cls");
		switch (opt)
		{
 			case 1:
				continue;
 		
			case 0:
				cout<<endl<<endl<<"\t\t\tThank u for using CMS"<<endl<<endl;
				exit(0);
				break;
			default:
        	cout<<"\t\t\t\tINVALID CHOICE!!"<<endl;	
			cout<<"\t\tPlease enter the correct option!!"<<endl;
			break;
		}
	}
		return 0;
			}
