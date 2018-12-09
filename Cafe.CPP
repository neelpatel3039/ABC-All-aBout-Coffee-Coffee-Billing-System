#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<process.h>
#include<time.h>
#include<stdlib.h>
#include<iomanip.h>
#include<ctype.h>
class cafe
	{
		char *strs[10], *coupon[10], *orders[5];		//items
		float rate[10], bill, orderrate[5], discount;  //rates
		int i, k, j, t, quantity, countcorrect, countitem, m, n, orderquantity[5];
		char item[19];		//order

		char dateSTR[9], timeSTR[9], code[10]; //displaying  time and date
		public:
			cafe()
				{
					k = 0;
					m = 0;
					n = 0;
					bill = 0.0;
					discount = 0;
					strs[0] = "CAPPUCHINO";
					strs[1] = "DECAF";
					strs[2] = "FRAPPUCHINO";
					strs[3] = "IRISH-COFFEE";
					strs[4] = "GARLIC-BREAD";
					strs[5] = "OREO-SHAKE";
					strs[6] = "BADAM-MILK";
					strs[7] = "ASSAM-TEA";
					strs[8] = "CHEESE-GARLIC-BREAD";
					strs[9] = "PANEER-ROLL";
					rate[0] = 150;
					rate[1] = 200;
					rate[2] = 300;
					rate[3] = 250;
					rate[4] = 310;
					rate[5] = 150;
					rate[6] = 200;
					rate[7] = 100;
					rate[8] = 400;
					rate[9] = 390;
					coupon[1] = "ABC1";
					coupon[2] = "ABC2";
					coupon[3] = "ABC3";
				}
			void display();	//display menu
			void readdata(); //taking order from user
			void displaybill();  //displaying final bill
			void quiz();
			void getcode();
	};
void cafe :: display()
	{
		int i;
		cout<<"\t\tMENU"<<endl;
		cout<<"ITEM"<<"\t\t\t"<<"\t\t\t\t"<<"RATE"<<endl;
		for(i=0; i<10; i++)
			{
				if(i==1)
				{cout<<strs[i]<<"\t\t\t"<<"\t\t\t\t";
				cout<<setw(4)<<rate[i]<<endl;}

				else if(i==8)
				{cout<<strs[i]<<"\t\t\t"<<"\t\t";
				cout<<setw(4)<<rate[i]<<endl;}

				else
				{cout<<strs[i]<<"\t\t\t"<<"\t\t\t";
				cout<<setw(4)<<rate[i]<<endl;}
			}
	}
void cafe :: readdata()	  //taking order from user
	{
			int ch;
			countitem = 0;
			while(countitem <= 5)
			{
			cout<<"Enter item you want to buy"<<endl;
			cin>>item;
			//cout<<item;
			for(int i = 0; i < 10; i++)
				{
					 j = strncmp(strs[i], item, 19);
					 if(j == 0)
						{
							countitem++;
							n++;
							orderrate[n] = rate[i];
							cout<<"Enter quantity"<<endl;
							cin>>quantity;
							m++;
							orderquantity[m] = quantity;
							k++;
							orders[k] = strs[i];
							//k++;
							//cout<<orders[k]<<endl;
							bill += rate[i] * quantity;
							break;
						}
				}
			cout<<endl<<"Do you want to buy something else?"<<endl;
			cout<<"1 --------------> YES"<<endl;
			cout<<"2 --------------> NO"<<endl;
			cout<<"Enter your choice";
			cin>>ch;
			if(ch == 2)
				{
					break;
				}
			}
	}
void cafe :: displaybill()
	{
		cout<<"\t\t\tWELCOME TO ALL ABOUT COFFEE"<<endl;
		cout<<"PLOT NO. 2, IRISH LANE"<<endl;
		cout<<"NEXT TO 24 KARAT CINEMAS"<<endl;
		cout<<"VERSOVA EAST"<<endl;
		cout<<"MUMBAI - 400 097"<<endl;
		cout<<"___________________________________________________________________________";
		cout<<endl;
		cout<<"DATE: "<<_strdate(dateSTR)<<"\t\t\t"<<"CASHIER: JIMIL"<<endl;
		cout<<"TIME: "<<_strtime(timeSTR)<<endl;
		cout<<"________________________________________________________________________________";
		cout<<endl;
		cout<<"\t\t\t\t CASH MEMO "<<endl;
		cout<<setw(19)<<"ITEM\t\t\t";
		cout<<setw(-4)<<"RATE\t\t";
		cout<<setw(-6)<<"QUANTITY\t";
		cout<<setw(-6)<<"AMOUNT"<<endl;
		t=k;
		while(t>=1)
		{
			if(orders[t] == "DECAF")
			{
				cout<<setw(19)<<orders[t]<<"\t\t\t\t";
				cout<<setw(-1)<<orderrate[t]<<"\t\t\t";
				cout<<setw(-5)<<orderquantity[t]<<"\t\t\t\t";
				cout<<setw(-5)<<orderrate[t]*orderquantity[t]<<endl;
			}
			else if(orders[t] == "CHEESE-GARLIC-BREAD")
			{
				cout<<setw(19)<<orders[t]<<"\t";
				cout<<setw(-4)<<orderrate[t];
				cout<<setw(-6)<<orderquantity[t];
				cout<<setw(-6)<<orderrate[t]*orderquantity[t]<<endl;
			}
			else
			{
				cout<<setw(15)<<orders[t]<<"\t\t\t";
				cout<<setw(-4)<<orderrate[t]<<"\t\t";
				cout<<setw(-6)<<orderquantity[t]<<"\t";
				cout<<setw(-6)<<orderrate[t]*orderquantity[t]<<endl;
			}
			t--;
		}
		cout<<"________________________________________________________________________________";
		cout<<"\t\t\t BILL: "<<bill<<endl;
		cout<<"\t\t\t TAX : 10%"<<endl;
		cout<<"\t\t\t TOTAL BILL :"<<bill+(0.1*bill)<<endl;
		cout<<"\t\t\t DISCOUNT :"<<discount<<"%"<<endl;
		cout<<"\t\t\t AMOUNT PAYABLE: "<<bill+(0.1*bill)-((discount/100.0)*bill)<<endl;
		cout<<"________________________________________________________________________________";
		cout<<"\t\t\t THANK YOU"<<endl;
		cout<<"\t\t DO VISIT US AGAIN"<<endl;
	}
void cafe::quiz()
{
	int correct=0,ans, ch;
	char name[20];
	cout<<"WELCOME TO COFFEE TRIVIA "<<endl;
	cout<<"____________________________________________________________"<<endl;
	cout<<"ENTER YOUR NAME "<<endl;
	cin>>name;
	cout<<"____________________________________________________________"<<endl;
	cout<<"TO GET A DISCOUNT YOU HAVE TO ANSWER MORE THAN 2 ANSWERS CORRECTLY"<<endl;
	cout<<"____________________________________________________________"<<endl;
	for(int j = 1; j<=3; j++)
	{
		srand(time(NULL));
		ch = rand()%10;
		switch(ch)
		{
		case 0: cout<<"QUESTION " <<j<<": WHAT'S A CAPPUCCINO MADE OUT OF ?"<<endl;
			cout<<"1.espresso and milk\t\t2.espresso,chocolate syrup and milk foam"<<endl<<"3.espresso,milk and milk foam\t\t4.espresso,water and milk foam"<<endl;
			cin>>ans;
			if(ans==3)
			{
				correct++;
				cout<<"right answer"<<endl;
			}
			else
			{
				cout<<"wrong answer"<<endl;
			}
			break;
		case 1:	cout<<"QUESTION "<<j<<": WHERE WAS COFFEE FIRST DISCOVERED ?"<<endl;
			cout<<"1.Ethiopia\t\t2.Brazil"<<endl<<"3.Columbia\t\t4.Ghana"<<endl;
			cin>>ans;
			if(ans==1)
			{
				correct++;
				cout<<"right answer"<<endl;
			}
			else
			{
				cout<<"wrong answer"<<endl;
			}
			break;
		case 2:	cout<<"QUESTION "<<j<<": ESPRESSO LITERALLY MEANS ? "<<endl;
			cout<<"1.speed it up\t\t2.to go"<<endl<<"3.forced out\t\t4.black and intense";
			cin>>ans;
			if(ans==3)
			{
				correct++;
				cout<<"right answer"<<endl;
			}
			else
			{
				cout<<"wrong answer"<<endl;
			}
			break;
		case 3:	cout<<"QUESTION "<<j<<": COFFEE BEANS GROW ON ? "<<endl;
			cout<<"1.a low,spreading vine\t\t2.a bush"<<endl<<"3.a tree\t\t4.the roots of a coffee plant"<<endl;
			cin>>ans;
			if(ans==2)
			{
				correct++;
				cout<<"right answer"<<endl;
			}
			else
			{
				cout<<"wrong answer"<<endl;
			}
			break;
		case 4:	cout<<"QUESTION "<<j<<": MOST COFFEES ARE A BLEND OF ?"<<endl;
			cout<<"1.light and dark roasts\t\t2.caffeine and essential oils"<<endl<<"3.arabica and robusta beans\t\t4.african and south american beans"<<endl;
			cin>>ans;
			if(ans==3)
			{
				correct++;
				cout<<"right answer"<<endl;
			}
			else
			{
				cout<<"wrong answer"<<endl;
			}
			break;
		case 5: cout<<"QUESTION "<<j<<": WHAT IS MADE OF ESPRESSO, MILK AND MILK FOAM"<<endl;
			cout<<"1.coffee\t\t2.tea"<<endl<<"3.milkshake\t\t4.cappuchino"<<endl;
			cin>>ans;
			if(ans==4)
			{
				correct++;
				cout<<"right answer"<<endl;
			}
			else
			{
				cout<<"wrong answer"<<endl;
			}
			break;
		case 6: cout<<"QUESTION "<<j<<": WHICH TYPE OF COFFEE HAS THE MOST CAFFEINE BY PERCENTAGE?"<<endl;
			cout<<"1.mild roasted coffee\t\t2.light roasted coffee"<<endl<<"3.black coffee\t\t4.strong coffee"<<endl;
			cin>>ans;
			if(ans==2)
			{
				correct++;
				cout<<"right answer"<<endl;
			}
			else
			{
				cout<<"wrong answer"<<endl;
			}
			break;
		case 7: cout<<"QUESTION "<<j<<": WHICH PROGRAMMING LANGUAGE IS RELATED TO COFFEE?"<<endl;
			cout<<"1.java\t\t2.C++"<<endl<<"3.MapReduce\t\t4.fortran"<<endl;
			cin>>ans;
			if(ans==1)
			{
				correct++;
				cout<<"right answer"<<endl;
			}
			else
			{
				cout<<"wrong answer"<<endl;
			}
			break;
		case 8: cout<<"QUESTION "<<j<<": WHICH STATE IS THE BIGGEST PRODUCER OF COFFEE IN INDIA?"<<endl;
			cout<<"1.rajasthan\t\t2.kerala"<<endl<<"3.telangana\t\t4.karnataka"<<endl;
			cin>>ans;
			if(ans==4)
			{
				correct++;
				cout<<"right answer"<<endl;
			}
			else
			{
				cout<<"wrong answer"<<endl;
			}
			break;
		case 9: cout<<"QUESTION "<<j<<": COFFEE CAN BE GROWN ALONGSIDE WHICH CROP ?"<<endl;
			cout<<"1.rice and corn\t\t2.wheat and jowar"<<endl<<"3.wheat and bajra\t\t4.none"<<endl;
			cin>>ans;
			if(ans==1)
			{
				correct++;
				cout<<"right answer"<<endl;
			}
			else
			{
				cout<<"wrong answer"<<endl;
			}
			break;
		}
	}
	if(correct>=2)
	{
		cout<<"CONGRATULATION "<<name<<" YOU HAVE ANSWERED MORE THAN 2 ANSWERS CORRECT"<<endl<<" YOU GET A DISCOUNT OF 5% ON YOUR BILL"<<endl;
		discount += 5.0;
	}
	else
	{
		cout<<"SORRY!"<<endl<<"YOU HAVE ANSWERED ONLY"<<correct<<"ANSWERS CORRECTLY"<<endl<<"YOU CANNOT GET THE DISCOUNT"<<endl;
	}
}
void cafe :: getcode()
	{
		int ans;
		cout<<endl<<"Enter coupon code:";
		cin>>code;
		for(int j = 0; j<3; j++)
			{
				ans = strncmp(coupon[j],code,4);
				if(ans == 0)
					{
						discount = j*10;
						cout<<endl<<"CONGRATULATIONS! YOU GET A WHOPPING DISCOUNT OF "<<j*10<<"%"<<endl;
						break;
					}
			}
	}
void main()
	{
		clrscr();
		cafe obj;
		int ch;
		cout<<"1 -----------> NORMAL BILL"<<endl;
		cout<<"2 -----------> COFFEE TRIVIA"<<endl;
		cout<<"3 -----------> DISCOUNT COUPON"<<endl;
		cout<<"Enter your choice";
		cin>>ch;
		cout<<endl;
		switch(ch)
			{
				case 1: obj.display();
					obj.readdata();
					obj.displaybill();
					break;
				case 2: obj.quiz();
					obj.display();
					obj.readdata();
					obj.displaybill();
					break;
				case 3: obj.getcode();
					obj.display();
					obj.readdata();
					obj.displaybill();
					break;
				default : cout<<endl<<"SORRY! WRONG CHOICE";
					  break;
			}
		getch();
	}