#include<fstream>
#include<iostream>
#include<string.h>

#define price_room 1000;
#define price_noodle 100;
#define price_rice 100;
#define price_shake 50;
#define price_chicken 150;

using namespace std;

class Hotel
{
    int quantity; //Temp variable to hold the amount entered
    int choice; //Holds the choices to be selected from menu
    int Qrooms; //Store the amount of rooms available
    int Qnoodle, Qrice , Qshake , Qchic ; //To hold amount of food items we have
    int Srooms; //Amount of rooms we sold
    int Snoodle, Srice, Sshake , Schic; //Amount of food items we sold
    int Total_rooms; //Total price of room
    int Total_noodle, Total_rice , Total_shake, Total_chic ; //Total price of each food items
    bool flag;

public: Hotel()
        {
            Qrooms = Srooms = Total_rooms = 0;
            Qnoodle = Qrice = Qshake = Qchic = 0;
            Snoodle = Srice = Sshake = Schic = 0;
            Total_noodle = Total_rice = Total_shake = Total_chic = 0 ;
            flag = true;
        }

        void Start()
        {
            do
            {
                system("CLS");
                cout<<"\t\tWELCOME TO HOTEL MANAGEMENT SYSTEM";
                cout<<"\n\nPLEASE CONSIDER THE MENU BELOW\n";
                cout<<"\n1. Input Hotel Items (Password Required)";
                cout<<"\n2. View Hotel Items";
                cout<<"\n3. Information Regarding Sales";
                cout<<"\n4. Exit";
    
                cout<<"\n\nEnter Your Choice: ";
                cin>>choice;
                fflush(stdin);
                switch(choice)
                {
                    case 1: Admin_Input();
                            break;
                    case 2: Hotel_Menu();
                            break;
                    case 3: Sales_Info();
                            break;
                    case 4: flag = false;
                            exit(0);
                    default: cout<<"Please select the option number mentioned above";
                            break;
                }
            } while (flag);
            
        }

        void Admin_Input()
        {
            system("CLS");
            string password;
            cout<<"\nEnter admin password: ";
            getline(cin, password);
            fflush(stdin);
            if( password == "admin123" )
            {
                //Inputing the items that act as availability in the hotel. Admin will enter these
                cout<<"\nQUANTITY OF ITEMS WE HAVE";
                cout<<"\n\nEnter Rooms Available: ";
                cin>>Qrooms;
                cout<<"Enter Noodles Available: ";
                cin>>Qnoodle;
                cout<<"Enter Rice Available: ";
                cin>>Qrice;
                cout<<"Enter Shakes Available: ";
                cin>>Qshake;
                cout<<"Enter Chicken Available: ";
                cin>>Qchic;
                prompt();
            }
            else
            {
                cout<<"Wrong Password!";
                prompt();
                flag = true;
            }
        }

        void Hotel_Menu()
        {
            system("CLS");
            cout<<"\t\tSELECT THE OPTIONS BELOW";
            cout<<"\n1. Rooms";
            cout<<"\n2. Noodles";
            cout<<"\n3. Rice";
            cout<<"\n4. Shakes";
            cout<<"\n5. Chicken";
            cout<<"\n6. Information Regarding Sales";
            cout<<"\n7. Exit";

            cout<<"\n\nENTER YOUR CHOICE: ";
            cin>>choice;
            Items_Evaluate();
        }

        void Items_Evaluate()
        {
            switch(choice)
            {
                case 1: Evaluate_Rooms();
                        break;
                case 2: Evaluate_Noodles();
                        break;
                case 3: Evaluate_Rice();
                        break;
                case 4: Evaluate_Shakes();
                        break;
                case 5: Evaluate_Chicken();
                        break;
                case 6: Sales_Info();
                        break;
                default: break;
            }
        }

        void Evaluate_Rooms() //Calculate Room items
        {
            system("CLS");
            cout<<"\nTotal amount of rooms available =  "<<Qrooms;
            cout<<"\nEnter amount of rooms you want? ";
            cin>>quantity;

            if(quantity <= Qrooms)
            {
                Srooms = quantity;
                Qrooms = Qrooms - quantity;//Update the amount available in hotel
                Total_rooms = Total_rooms + quantity * price_room;
                cout<<"\n\n"<<quantity<<" rooms/room has been alloted to you";
                prompt();
            }
            else
            {
                cout<<"Only "<<Qrooms<<" rooms available in hotel";
                prompt();
            }
        }

        void Evaluate_Noodles() //Calculate Noodles items
        {
            system("CLS");
            cout<<"\nTotal amount of noodles available =  "<<Qnoodle;
            cout<<"\nEnter amount of noodles you want? ";
            cin>>quantity;

            if(quantity <= Qnoodle)
            {
                Snoodle = quantity;
                Qnoodle = Qnoodle - quantity;//Update the amount available in hotel
                Total_noodle = Total_noodle + quantity * price_noodle;
                cout<<"\n\n"<<quantity<<" noodles/noodle has been sold to you";
                prompt();
            }
            else
            {
                cout<<"Only "<<Qnoodle<<" noodles available in hotel";
                prompt();
            }
        }

        void Evaluate_Rice() //Calculate Rice items
        {
            system("CLS");
            cout<<"\nTotal amount of rice available =  "<<Qrice;
            cout<<"\nEnter amount of rice you want? ";
            cin>>quantity;

            if(quantity <= Qrice)
            {
                Srice = quantity;
                Qrice = Qrice - quantity; //Update the amount available in hotel
                Total_rice = Total_rice + quantity * price_rice; //calculate total price sold
                cout<<"\n\n"<<quantity<<" rice has been sold to you";
                prompt();
            }
            else
            {
                cout<<"Only "<<Qrice<<" rice available in hotel";
                prompt();
            }
        }

        void Evaluate_Shakes() //Calculate shake items
        {
            system("CLS");
            cout<<"\nTotal amount of shakes available =  "<<Qshake;
            cout<<"\nEnter amount of shakes you want? ";
            cin>>quantity;

            if(quantity <= Qshake)
            {
                Sshake = quantity;
                Qshake = Qshake - quantity; //Update the amount available in hotel
                Total_shake = Total_shake + quantity * price_shake;
                cout<<"\n\n"<<quantity<<" shakes/shake has been sold to you";
                prompt();
            }
            else
            {
                cout<<"Only "<<Qshake<<" shakes available in hotel";
                prompt();
            }
        }

        void Evaluate_Chicken()//Calculate chicken items
        {
            system("CLS");
            cout<<"\nTotal amount of chicken available =  "<<Qchic;
            cout<<"\nEnter amount of chicken you want? ";
            cin>>quantity;

            if(quantity <= Qchic)
            {
                Schic = quantity;
                Qchic = Qchic - quantity; //Update the amount available in hotel
                Total_chic = Total_chic + quantity * price_chicken;
                cout<<"\n\n"<<quantity<<" Chicken has been sold to you";
                prompt();
            }
            else
            {
                cout<<"Only "<<Qchic<<" chicken available in hotel";
                prompt();
            }
        }

        void Sales_Info() //This display all the money made in a day & quantity of items sold
        {
            //Money Made
            cout<<"TOTAL SALES MADE FOR ROOMS = RS. "<<Total_rooms;
            cout<<"\nTOTAL SALES MADE FOR NOODLES =  RS. "<<Total_noodle;
            cout<<"\nTOTAL SALES MADE FOR RICE = RS. "<<Total_rice;
            cout<<"\nTOTAL SALES MADE FOR SHAKES = RS. "<<Total_shake;
            cout<<"\nTOTAL SALES MADE FOR CHICKEN = RS. "<<Total_chic<<endl;

            //Quantity of items sold
            cout<<"\nTOTAL QUANTITY SOLD FOR ROOMS =  "<<Srooms;
            cout<<"\nTOTAL QUANTITY SOLD FOR NOODLES =  "<<Snoodle;
            cout<<"\nTOTAL QUANTITY SOLD FOR RICE =  "<<Srice;
            cout<<"\nTOTAL QUANTITY SOLD FOR SHAKES =  "<<Sshake;
            cout<<"\nTOTAL QUANTITY SOLD FOR CHICKEN =  "<<Schic<<endl;

            //Quantity Available
            cout<<"\nTOTAL QUANTITY AVAILABLE FOR ROOMS = "<<Qrooms;
            cout<<"\nTOTAL QUANTITY AVAILABLE FOR NOODLES = "<<Qnoodle;
            cout<<"\nTOTAL QUANTITY AVAILABLE FOR RICE = "<<Qrice;
            cout<<"\nTOTAL QUANTITY AVAILABLE FOR SHAKES = "<<Qshake;
            cout<<"\nTOTAL QUANTITY AVAILABLE FOR CHICKEN = "<<Qchic;

            prompt();
        }

        void prompt() //To delay the sudden change in output screen
        {
            char c;
            cout<<"\n\nPress 'y' to go back to menu: ";
            cin>>c;
        }

};

int main()
{
    system("CLS");
    Hotel hotel_obj;
    hotel_obj.Start();
    return 0;
}