#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>

using namespace std;

class Faculty //A class to implement faculty details
{
private: string name; //Name of the faculty
         int id_no;
         int age; //Age of the faculty
         string email_id; //Email Id of the faculty
         char Department[40];  //Department of the faculty
         char mobile_no[11]; //Mobile number of the faculty
         char phd_university[50];  //The University where the faculty has completed his Phd

public: Faculty() // Default Constructor
        {
            name = email_id = " ";
            age = 0;
            id_no = 0;
            strcpy(Department, " ");
            strcpy(mobile_no," ");
            strcpy(phd_university," ");
        }
 
        void Enter_Details_Faculty() //A function to enter the details of the faculty (New Record)
        {
            fflush(stdin);
            cout<<"\nENTER NAME OF THE FACULTY: ";
            getline(cin, name);
            fflush(stdin);
            cout<<"ENTER ID NO: ";
            cin>>id_no;
            fflush(stdin);
            cout<<"ENTER AGE OF THE FACULTY: "  ;
            cin>>age;
            fflush(stdin);
            cout<<"ENTER EMAIL ID OF THE FACULTY: ";
            getline(cin, email_id);
            fflush(stdin);
            cout<<"ENTER DEPARTMENT OF THE FACULTY: ";
            gets(Department);
            fflush(stdin);
            cout<<"ENTER MOBILE NUMBER OF THE FACULTY: ";
            gets(mobile_no);
            fflush(stdin);
            cout<<"ENTER THE UNIVERSITY NAME WHERE THE FACULTY HAS COMPLETED HIS PHD: ";
            gets(phd_university);
            fflush(stdin);
        }

        void Display_Details_Faculty() //A member function to display details of the faculty
        {
            cout<<"\n\nDETAILS";
            cout<<"\nNAME: "<<name;
            cout<<"\nAGE: "<<age;
            cout<<"\nID NUMBER: "<<id_no;
            cout<<"\nEMAIL ID: "<<email_id;
            cout<<"\nDEPARTMENT: "<<Department;
            cout<<"\nCONTACT NUMBER: "<<mobile_no;
            cout<<"\nUNIVERSITY WHERE PHD WAS COMPLETED: "<<phd_university;
        }

        void Update_Record_Faculty() //A function to update the record of the faculty
        {
            fflush(stdin);
            cout<<"\nENTER NEW NAME OF THE FACULTY: ";
            getline(cin, name);
            fflush(stdin);
            cout<<"ENTER NEW ID NO: ";
            cin>>id_no;
            fflush(stdin);
            cout<<"ENTER NEW AGE OF THE FACULTY: "  ;
            cin>>age;
            fflush(stdin);
            cout<<"ENTER NEW EMAIL ID OF THE FACULTY: ";
            getline(cin, email_id);
            fflush(stdin);
            cout<<"ENTER NEW DEPARTMENT OF THE FACULTY: ";
            gets(Department);
            fflush(stdin);
            cout<<"ENTER NEW MOBILE NUMBER OF THE FACULTY: ";
            gets(mobile_no);
            fflush(stdin);
            cout<<"ENTER THE NEW UNIVERSITY NAME WHERE THE FACULTY HAS COMPLETED HIS PHD: ";
            gets(phd_university);
            fflush(stdin);  
        }

        int Id_number() //Return Id number of the faculty
        {
            return id_no;
        }

};

class FilesFaculty //The main class to write faculty details from files and reads them
{
private:   fstream fileobj; //A file object of type fstream
           Faculty obj;     //An object of type faculty

public: void MainMenu()
        {
            short int menu;
            cout<<"\nMENU";
            cout<<"\n1. ENTER FACULTY RECORDS.\n2. DISPLAY ALL FACULTY RECORDS";
            cout<<"\n3. DELETE RECORDS\n4. UPDATE RECORDS\n5. DISPLAY A PARTICULAR FACULTY RECORD";
            cout<<"\n6. EXIT";

            cout<<"\nENTER YOUR CHOICE (in serial number): ";
            cin>>menu;

            switch(menu)
            {
                case 1: system("CLS");
                        Enter();
                        break;
                case 2: system("CLS");
                        Display();
                        break;
                case 3: system("CLS");
                        Delete();
                        break;
                case 4: system("CLS");
                        Update();
                        break;
                case 5: system("CLS");
                        Display_Particular();
                        break;
                case 6: exit(0);

                default: break;
            }
        }

        void Enter()    //function to enter records to the file
        {
            bool var1;
            fileobj.open("Faculty.dat", ios::app | ios::out | ios::binary);
            do{
                cout<<"\nENTER RECORDS:";
                obj.Enter_Details_Faculty();
                fileobj.write((char *)&obj, sizeof(obj));
                cout<<"\nFILES WRITTEN SUCCESSFULLY";
                cout<<"\nDO YOU WANT TO ADD RECORDS AGAIN? (1 for yes/0 for no): ";
                cin>>var1;
            }while(var1);
            
            fileobj.close();
        }

        void Display() //function to display all faculty details
        {
            fileobj.open("Faculty.dat", ios::in | ios::binary);
            fileobj.seekg(0);

            while(fileobj.read((char *)&obj, sizeof(obj)))
            {
                obj.Display_Details_Faculty();
            }
            fileobj.close();
        }

        void Delete() //function to delete a record of the fauclty
        {
            fstream temp;
            int id_temp;
            bool find = 1;
            temp.open("Temp.dat", ios::out | ios::binary);
            fileobj.open("Faculty.dat", ios::in | ios::binary);
            
            while(find)
            {
                fileobj.seekg(0);
                cout<<"\nENTER ID NUMBER IN WHICH HIS/HER RECORDS IS TO BE DELETED: ";
                cin>>id_temp;

                while(fileobj)
                {
                    fileobj.read((char*)&obj, sizeof(obj));
                    if(obj.Id_number() != id_temp) //If the id number of the faculty is not same as the user input
                    {
                        temp.write((char*)&obj, sizeof(obj));
                    }
                }

                cout<<"\nRECORDS HAVE BEEN REMOVED.";
                cout<<"\nDO YOU WISH TO DELETE MORE RECORDS? (1 for yes/0 for no): ";
                cin>>find;
            }
            fileobj.close();
            temp.close();
            system("erase Faculty.dat"); //Removing the main Faculty File
            system("rename Temp.dat Faculty.dat"); //Renaming the Temp.txt file
        }

        void Display_Particular() //Function to display a particular details
        {
            int id_temp; //Id_number
            cout<<"\nENTER ID NUMBER WHOSE RECORD IS TO BE DISPLAYED: ";
            cin>>id_temp;

            fileobj.open("Faculty.dat", ios::in | ios::binary);
            fileobj.seekg(0, ios::beg);

            while(fileobj.read((char*)&obj, sizeof(obj)))
            {
                if(obj.Id_number() == id_temp)
                {
                    obj.Display_Details_Faculty();
                    break;
                }
            }

            fileobj.close();
        }

        void Update() //function to update the record of the faculty
        {
            Faculty temp; // A temporary object of class Faculty
            int id_temp; //Id number
            cout<<"\nENTER ID NUMBER WHOSE RECORD IS TO BE UPDATED: ";
            cin>>id_temp;

            fileobj.open("Faculty.dat", ios::in | ios::out | ios::binary | ios::ate);
            fileobj.seekg(0, ios::beg);

            while(fileobj.read((char*)&obj, sizeof(obj)))
            {
                if(obj.Id_number() == id_temp)
                {
                    temp.Update_Record_Faculty();
                    fileobj.seekp(-sizeof(obj), ios::cur);
                    fileobj.write((char*)&temp, sizeof(temp));
                    break;
                }
            }

            fileobj.close();
        }
};

int main()
{
    system("CLS");
    bool check;
	check=1;
    FilesFaculty object; //An complex object of type FilesFaculty
    while(check)
    {
        object.MainMenu();
        cout<<"\n\nDO YOU WANT TO SEE MENU AGAIN? (1 for yes/0 for no) ";
        cin>>check;
        system("CLS");
    }

    return 0;
}
