#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
using namespace std;
 fstream f,fi,f1;
class record{
	char time[10];
	char name[30];
	char place[25];
	char duration[10];
	char note[500];
    char passwords[25]="ameesha";
	public:
		void add_record();
		void view_record();
		void modify_record();
		void delete_record();
		void edit_password();
		int password();
};

void record::add_record()
{
    int i=0;
 system("cls");
				char another = 'Y' ,time[10];
				record e;
				char filename[15];
				int choice;
int count=0;
				cout<<"\n\n\t\t***************************\n";
				cout<<"\t\t* WELCOME TO THE ADD MENU *";
				cout<<"\n\t\t***************************\n\n";
				cout<<"\n\n\tENTER DATE OF YOUR RECORD:[dd-mm-yyyy]:";
				cin.ignore();
				cin.getline(filename,15);
				f.open(filename,ios::in|ios::binary|ios::app|ios::out);
				if(!f.is_open())
				{
					 f.open(filename,ios::in|ios::binary|ios::app|ios::out);
					 if(!f.is_open())
					{
					 	cout<<"\nSYSTEM ERROR...";
					 	cout<<"\nPRESS ANY KEY TO EXIT";
					 	getch();
                    return ;
					 }

				}
				 while ( another == 'Y'|| another=='y' )
                {
                    choice=0;
               if(i++>0)
                cin.ignore();
                cout<<"\n\tENTER TIME:[hh:mm]:";
                cin.getline(time,10);
               while(f.is_open())
                {
                    if(strcmp(e.time,time)==0&&count==0)
                    {
                        count++;
                        cout<<"\n\tTHE RECORD ALREADY EXISTS.\n";
                        choice=1;
                    }
                    count=0;
                    f.close();
                }
                    if(choice==0)
                    {
                        f.open(filename,ios::in|ios::binary|ios::app|ios::out);
                        strcpy(e.time,time);
                        cout<<"\tENTER NAME:";
                        cin.getline(e.name,30);
                        cout<<"\tENTER PLACE:";
                        cin.getline(e.place,25);

                    cout<<"\tENTER DURATION:";
                        cin.getline(e.duration,10);

                        cout<<"\tNOTE:";
                        cin.getline(e.note,500);
                           f.write((char *)&e,sizeof(e));
                        cout<<"\nYOUR RECORD IS ADDED...\n";
                    }
                        cout<<"\n\tADD ANOTHER RECORD...(Y/N) ";

                        another = getchar( ) ;
                }
                f.close() ;
                cout<<"\n\n\tPRESS ANY KEY TO EXIT...";
                getch();
    }
void record::view_record()
{
	system("cls");
	record customer;
	char time[10],choice,filename[14];
	int ch;
	cout<<"\n\n\t\t*******************************\n";
	cout<<"\t\t*   HERE IS THE VIEWING MENU  *";
	cout<<"\n\t\t*******************************\n\n";
		choice=password();
		 if(choice!=0)
            {
                return ;
            }
            do
            {
            	cout<<"\n\tENTER THE DATE OF RECORD TO BE VIEWED:[dd-mm-yyyy]:";
            	cin.ignore();
            	cin.getline(filename,15);
            	f.open(filename,ios::in|ios::binary);
            	if(!f)
            	{
            		 puts ( "\nTHE RECORD DOES NOT EXIST...\n" ) ;
            		 cout<<"PRESS ANY KEY TO EXIT...";
            		 getch();
                                return ;
            	}
            	system("cls");
            	cout<<"\n\tHOW WOULD YOU LIKE TO VIEW:\n";
            	cout<<"\n\t1.WHOLE RECORD OF THE DAY.";
            	cout<<"\n\t2.RECORD OF FIX TIME.";
            	cout<<"\n\t\tENTER YOUR CHOICE:";
            	cin>>ch;
            	switch(ch)
            	{
            		case 1:
            			cout<<"\nTHE WHOLE RECORD FOR:"<<filename;
            			while (f.read((char *)&customer,sizeof(record)))
                        {
            				cout<<"\n";
            				cout<<"\nTIME:"<<customer.time;
            				cout<<"\nMEETING WITH:"<<customer.name;
            				cout<<"\nMEETING AT:"<<customer.place;
            				cout<<"\nDURATION:"<<customer.duration;
            				cout<<"\nNOTE:"<<customer.note;
            				cout<<"\n";
            			}
            			break;
            			case 2:
            				cin.ignore();
            				cout<<"\nENTER TIME:[hh:mm]:";
            				cin.getline(time,10);
            				while( f.read((char *)&customer,sizeof(customer)))
            				{

            					if(strcmp(customer.time,time)==0)
            					{
            						cout<<"\nYOUR RECORD IS:";
            						cout<<"\nTIME:"<<customer.time;
                                    cout<<"\nMEETING WITH:"<<customer.name;
                                    cout<<"\nMEETING AT:"<<customer.place;
                                    cout<<"\nDURATION:"<<customer.duration;
                                    cout<<"\nNOTE:"<<customer.note;
            					}
            				}
            				break;
            				default:
            					cout<<"\nYOU TYPED SOMETHING ELSE...\n";
            					break;
            	}
            	cout<<"\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):";
            	cin>>choice;
                f.close () ;
            }while(choice=='Y'||choice=='y');
               cout<<"\n\n\tPRESS ANY KEY TO EXIT...";
                getch();
                return ;
}
void record::modify_record()
{
	 system("cls");
	 record customer;
     char time[10],choice,filename[14];
	 int num,count=0,cnt=0;
	 int pos;
	 cout<<"\n\n\t\t*******************************\n";
	 cout<<"\t\t* WELCOME TO THE EDITING MENU *";
	 cout<<"\n\t\t*******************************\n\n";
    choice=password();
    if(choice!=0)
    {
	   	return;
    }
    do{
	   	cout<<"\n\tENTER THE DATE OF RECORD TO BE EDITED:[dd-mm-yyyy]:";
	   	cin.ignore();
	   	cin.getline(filename,15);
	   	cout<<"\n\tENTER TIME:[hh:mm]:";
	   	cin.getline(time,10);
	   	 f.open(filename,ios::binary|ios::in);
	   	 if (!f)

        {
                            	cout<<"\nRECORD DOES NOT EXISTS:";
                            	cout<<"\nPRESS ANY KEY TO GO BACK";
                            	getch();
                                return;
	   }
	   while ( f.read((char *)&customer,sizeof(customer)))
	   {
            cnt++;
	   	if(strcmp(customer.time,time)==0)
	   	{
                            cout<<"\nYOUR OLD RECORD WAS AS:";
                            cout<<"\nTIME:"<<customer.time;
            				cout<<"\nMEETING WITH:"<<customer.name;
            				cout<<"\nMEETING AT:"<<customer.place;
            				cout<<"\nDURATION:"<<customer.duration;
            				cout<<"\nNOTE:"<<customer.note;
            				cout<<"\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..";
            				cout<<"\n1.TIME.";
            				cout<<"\n2.MEETING PERSON.";
            				cout<<"\n3.MEETING PLACE.";
            				cout<<"\n4.DURATION.";
            				cout<<"\n5.NOTE.";
            				cout<<"\n6.WHOLE RECORD.";
            				cout<<"\n7.GO BACK TO MAIN MENU.";
            				do{
            					cout<<"\n\tENTER YOUR CHOICE:";

            					cin>>num;

            					switch(num)
            					{
            						case 1:
            						    cin.ignore();
            							cout<<"\nENTER THE NEW DATA:";
            							cout<<"\nNEW TIME:[hh:mm]:";
            							cin.getline(customer.time,10);
                                                    break;

                                     case 2:
                                         cin.ignore();
                                     	cout<<"\nENTER THE NEW DATA:";
            							cout<<"\nNEW MEETING PERSON:";
            							cin.getline(customer.name,30);
                                                    break;
                                    case 3:
                                        cin.ignore();
                                    		cout<<"\nENTER THE NEW DATA:";
            							cout<<"\nNEW MEETING PLACE:";
            							cin.getline(customer.place,25);
                                                    break;
                                    case 4:
                                        cin.ignore();
                                    		cout<<"\nENTER THE NEW DATA:";
            							cout<<"\nDURATION:";
            							cin.getline(customer.duration,10);
                                                    break;
                                    case 5:
                                        cin.ignore();
                                    		cout<<"\nENTER THE NEW DATA:";
            							cout<<"\nNOTE:";
            							cin.getline(customer.note,500);
                                                    break;
                                    case 6:
                                        cin.ignore();
                                    	cout<<"\nENTER THE NEW DATA:";
                                    	cout<<"\nNEW TIME:[hh:mm]:";
                                    	cin.getline(customer.time,10);
                                    	cout<<"\nNEW MEETING PERSON:";
                                    	cin.getline(customer.name,30);
                                    	cout<<"\nNEW MEETING PLACE:";
                                    	cin.getline(customer.place,25);
                                    	cout<<"\nDURATION:";
                                    	cin.getline(customer.duration,10);
                                    	cout<<"\nNOTE:";
                                    	cin.getline(customer.note,500);
                                    	 break;
                                    case 7:
                                        cin.ignore();
                                    	cout<<"\nPRESS ANY KEY TO GO BACK...\n";
                                    	 getch();
                                                    return ;
                                                    break;
                                    default:
                                        cin.ignore();
                                    	cout<<"\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n";
                                    	break;
            					}
            				}while(num<1||num>8);
            				f.close();
            				f.open(filename,ios::in|ios::binary|ios::out|ios::ate);
            				int location=(cnt-1)*sizeof(customer);
            				 f.seekp(location);
                            f.write((char *)&customer,sizeof(record));
                            f.close();
                            f.open(filename,ios::binary|ios::in);
                             f.seekp(location);
                            f.read((char *)&customer,sizeof(record));
                            choice=5;
                            break;
	   	}
	   }
	    if(choice==5)
                    {
                    system("cls");
                    cout<<"\n\t\tEDITING COMPLETED...\n";
                    cout<<"--------------------\n";
                    cout<<"THE NEW RECORD IS:\n";
                    cout<<"--------------------\n";
                    		cout<<"\nTIME:"<<customer.time;
            				cout<<"\nMEETING WITH:"<<customer.name;
            				cout<<"\nMEETING AT:"<<customer.place;
            				cout<<"\nDURATION:"<<customer.duration;
            				cout<<"\nNOTE:"<<customer.note;
            				f.close();
            				cout<<"\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)";
            				cin>>choice;
            				count++;}
            				else{
            					cout<<"\nTHE RECORD DOES NOT EXIST::\n";
            					cout<<"\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)";
            					cin>>choice;
            					 f.close () ;
            					 cnt=0;
            				}
            			}while(choice=='Y'||choice=='y');

            if(count==1)
            cout<<count<<" FILE IS EDITED...\n";
            else if(count>1)
            cout<<count<<" FILES ARE EDITED..\n";
            else
            cout<<"\nNO FILES EDITED...\n";
            cout<<"\tPRESS ENTER TO EXIT EDITING MENU.";
            getch();
}
int record::password()
{
        f.open("PASS",ios::in);
        f.read((char*)&passwords,sizeof(passwords));
        f.close();
        char pass[15]={0},check[15]={0},ch;
        int i=0,j;
        cout<<"::FOR SECURITY PURPOSE::";
        cout<<"::ONLY THREE TRIALS ARE ALLOWED::";
        for(j=0;j<3;j++)
        {
                        i=0;
                        cout<<"\n\n\tENTER THE PASSWORD:";
                        pass[0]=getch();
                        while(pass[i]!='\r')
                        {
                            if(pass[i]=='\b')
                            {
                                i--;
                                cout<<"\b";
                                cout<<" ";
                                cout<<"\b";
                                 pass[i]=getch();
                             }
                             else
                             {
                             	cout<<"*";
                                i++;
                                pass[i]=getch();
                             }
                         }
                         pass[i]='\0';
                         i=0;
                         if(strcmp(pass,passwords)==0)
                        {
                            cout<<"\n\n\tACCESS GRANTED...\n";
                            return 0;
                        }
                        else
                        {
                        	 cout<<"\n\n\tWRONG PASSWORD..\n\n\tACCESS DENIED...\n";
                        }
                     }
                       cout<<"\n\n\t::YOU ENTERED WRONG PASSWORD::YOU ARE NOT ALLOWED TO ACCESS ANY FILE::\n\n\tPRESS ANY KEY TO GO BACK...";
        getch();
        return 1;
}
void record::edit_password()
{
	system("cls");
    cout<<"\n";
    char pass[15]={0},confirm[15]={0},ch;
    int choice,i,check;
        check=password();
    if(check==1)
    {
        return ;
    }
    do
    {
        if(check==0)
                    {
                        i=0;
                        choice=0;
                        cout<<"\n\n\tENTER THE NEW PASSWORD:";
                        cin.ignore();
                        pass[0]=getch();
                        while(pass[i]!='\r')
                        {
                            if(pass[i]=='\b')
                            {
                                i--;
                                cout<<"\b";
                                cout<<" ";
                                cout<<"\b";
                                pass[i]=getch();
                            }
                            else
                            {
                                cout<<"*";
                                i++;
                                pass[i]=getch();
                            }
                        }
                         pass[i]='\0';
                        i=0;
                        cout<<"\n\tCONFIRM PASSWORD:";
                        confirm[0]=getch();
                        while(confirm[i]!='\r')
                        {
                            if(confirm[i]=='\b')
                            {
                                i--;
                                cout<<"\b";
                                cout<<" ";
                                cout<<"\b";
                                confirm[i]=getch();
                            }
                             else
                            {
                                cout<<"*";
                                i++;
                                confirm[i]=getch();
                            }
                        }
                        confirm[i]='\0';
                        if(strcmp(pass,confirm)==0)
                        {
                           strcpy(passwords,pass);
                           f.open("PASS",ios::in|ios::out);
                           f.seekg(0,ios::beg);
                           f.write((char*)&passwords,sizeof(passwords));
                           f.close();
                           cout<<"\n\n\tPASSWORD CHANGED SUCCESSFULLY.";
                           cout<<"\n\n\tPRESS ANY KEY TO CONTINUE...";
                           getch();
                                return ;
                            }
                        else
                        {
                            cout<<"\n\tTHE NEW PASSWORD DOES NOT MATCH.";
                            choice=1;
                        }
                    }
}while(choice==1);
    cout<<"\n\n\tPASSWORD CHANGED...\n\n\tPRESS ANY KEY TO GO BACK...";
    getch();
}
void record::delete_record()
{
                system("cls");
                record file;
                char filename[15],another = 'Y' ,time[10];;
                int choice,check;
                cout<<"\n\n\t\t*************************\n";
                cout<<"\t\t* WELCOME TO DELETE MENU*";
                cout<<"\n\t\t*************************\n\n";
                check = password();
                    if(check==1)
                    {
                        return ;
                    }
                      while ( another == 'Y' || another=='y')
                {
                cout<<"\n\n\tHOW WOULD YOU LIKE TO DELETE.";
                cout<<"\n\n\t#DELETE WHOLE RECORD\t\t\t[1]";
                cout<<"\n\t#DELETE A PARTICULAR RECORD BY TIME\t[2]";
                do
                {
                        cout<<"\n\t\tENTER YOUR CHOICE:";
                        cin>>choice;
                    switch(choice)
                        {
                            case 1:
                            cout<<"\n\tENTER THE DATE OF RECORD TO BE DELETED:[dd-mm-yyyy]:";
                            cin.ignore();
                            cin.getline(filename,15);
                           f.open (filename,ios::in|ios::binary) ;
                            if (!f)
                             {
                                cout<<"\nTHE FILE DOES NOT EXISTS";
                                cout<<"\nPRESS ANY KEY TO GO BACK.";
                                getch();
                                return ;
                            }
                            f.close();
                            remove(filename);
                            cout<<"\nDELETED SUCCESFULLY...";
                            break;
                            case 2:
                            cout<<"\n\tENTER THE DATE OF RECORD:[dd-mm-yyyy]:";
                            cin.ignore();
                            cin.getline(filename,15);
                             f.open (filename,ios::in|ios::binary) ;
                            if (!f)
                             {
                                cout<<"\nTHE FILE DOES NOT EXISTS";
                                cout<<"\nPRESS ANY KEY TO GO BACK.";
                                getch();
                                return ;
                            }
                            fi.open("temp",ios::in|ios::out|ios::binary|ios::app|ios::ate);
                            if(!fi)
                            {
                                cout<<"\nSYSTEM ERROR";
                            cout<<"\nPRESS ANY KEY TO GO BACK";
                                getch();
                                return ;
                            }
                            cout<<"\n\tENTER THE TIME OF RECORD TO BE DELETED:[hh:mm]:";
                            cin.getline(time,10);
                            while(f.read((char*)&file,sizeof(file)))
                            {
                                if(strcmp(file.time,time)!=0)
                                fi.write((char*)&file,sizeof(file));
                            }
                            f.close();
                            fi.close();
                            remove(filename);
                            rename("temp",filename);
                            cout<<"\nDELETED SUCCESFULLY...";
                            break;
                    default:
                            cout<<"\n\tYOU ENTERED WRONG CHOICE";
                            break;
                    }
                }while(choice<1||choice>2);
                 cout<<"\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):";
                    cin>>another;
                }
                cout<<"\n\n\tPRESS ANY KEY TO EXIT...";
                getch();
            }


int main()
{
	int ch;
	record d;
	cout<<"\n\n\t***********************************\n";
 cout<<"\t*PASSWORD PROTECTED PERSONAL DIARY*\n";
 cout<<"\t***********************************";
   while(1)
        {
                 cout<<"\n\n\t\tMAIN MENU:";
                 cout<<"\n\t---------------------\n";
                 cout<<"\n\n\tADD RECORD\t[1]";
                 cout<<"\n\tVIEW RECORD\t[2]";
                 cout<<"\n\tMODIFY RECORD\t[3]";
                 cout<<"\n\tDELETE RECORD\t[4]";
                 cout<<"\n\tEDIT PASSWORD\t[5]";
                 cout<<"\n\tEXIT\t\t[6]";
                 cout<<"\n\n\tENTER YOUR CHOICE:";
		cin>>ch;
		switch(ch)
                    {
                            case 1:
                            d.add_record();
                            break;
                            case 2:
                            d.view_record();
                            break;
                            case 3:
                            d.modify_record();
                            break;
                            case 4:
                            d.delete_record();
                            break;
                            case 5:
                            d.edit_password();
                            break;
                            case 6:
                            cout<<"\n\n\t\tTHANK YOU!!!";
                            getch();
                            exit(0);
                            default:
                            cout<<"\nYOU ENTERED WRONG CHOICE..";
                            cout<<"\nPRESS ANY KEY TO TRY AGAIN";
                            getch();
                            break;
                    }
                system("cls");
        }
            return 0;
        }
