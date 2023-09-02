#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

void Mode();
void Login();
void Page();
void Display();
void menu();
void food();
void drink();
void dessert();
void cake();
void icecream();
void set();
void bill();
void pay();
void member();
void membermenu();
void memberbill();
void memberpay();
void adminlogin();
void management();


/* List of Menus */
char chicken_chop[]="Chicken Chop";
char burger[]="Burger";
char cheesy_wedges[]="Cheesy Wedges";
char fried_chicken[]="Fried Chicken";
char fries[]="French Fries";

char lemonade[]="Lemonade";
char iced_coffee[]="Iced Coffee";
char coke[]="Coke";
char apple_juice[]="Apple Juice";

char cheesecake[]="Cheesecake";
char chococake[]="Chocolate Cake";
char redvelvet[]="Red Velvet Cake";
char lavacake[]="Lava Cake";

char chocochip[]="Choco Chip Ice Cream";
char oreo[]="Oreo Ice Cream";
char greentea[]="Green Tea";
char durian[]="Durian";

char setA[]="Set A";
char setB[]="Set B";
char setC[]="Set C";

char membername[100];

/* q = quantity */
int qchicken_chop=0;
int qburger=0;
int qcheesy_wedges=0;
int qfried_chicken=0;
int qfries=0;

int qlemonade=0;
int qiced_coffee=0;
int qcoke=0;
int qapple_juice=0;

int qcheesecake=0;
int qchococake=0;
int qredvelvet=0;
int qlavacake=0;

int qchocochip=0;
int qoreo=0;
int qgreentea=0;
int qdurian=0;

int qsetA=0;
int qsetB=0;
int qsetC=0;

int discount;

/* p = price */
float pchicken_chop=12.30;
float pburger=10.50;
float pcheesy_wedges=5.75;
float pfried_chicken=4.20;
float pfries=3.95;

float plemonade=2.15;
float piced_coffee=5.20;
float pcoke=3.40;
float papple_juice=4.0;

float pcheesecake=3.80;
float pchococake=3.20;
float predvelvet=4.50;
float plavacake=4.35;

float pchocochip=1.90;
float poreo=2.00;
float pgreentea=2.10;
float pdurian=2.75;

float psetA=10.90;
float psetB=15.0;
float psetC=16.15;

float price, totalprice, cash, discountprice;
float grossprofit=0; //for admin
int turnnumber=0; //for turn number code

int main()
{	
	char Next;
	printf("=================================++++++=====================================\n");
	printf("\t\t\tRESTAURANT ORDER SYSTEM\n");
	printf("=================================++++++=====================================\n");
	printf("\n\t\t     ~~Welcome to AIN.Co Restaurant~~\n");
	
	do
	{
		Mode();
		system("cls");
		printf("\n\nPLEASE LEAVE IT FOR NEXT USER.\n");
		printf("\nNEXT USER/CUSTOMER? Y-Yes \n\t\t"); //pressing other keys would terminate this system, only admin can do that
		scanf(" %c", &Next);
	}
	while (Next=='Y'||Next=='y');
	
	if(Next!='Y'|| Next!='y')
	{
	char username[20], password[15];
	int choice;
	
	printf("ONLY ADMIN CAN PERFORM THIS.\nNOT AN ADMIN? PRESS 0. ADMIN? PRESS 1\n");
	scanf("%d", &choice);
	system("cls");
	
		if(choice==1)
		{
			printf("\nEnter your username: ");
			scanf("%s", &username);
			printf("Enter your password: ");
			scanf("%s", &password); 
				if(strcmp(username,"ain.co")==0)
				{
					if(strcmp(password,"008975")==0)
					{
						printf("\nLogin Authorized! Welcome HAIFIA ADMIN.");
						printf("\nThat's all for today. Restaurant closed.\nTotal gained for today RM%.2f\n", grossprofit);
					}
					else
					{
						printf("\nWrong username or password\n");
						printf("Press any keys to go back to main\n");
						getch();
						main();
					}	
				}
				else
				{
					printf("\nWrong username or password\n");
					printf("Press any keys to go back to main\n");
					getch();
					main();
				}
		}
	
		else if(choice==0)
		{
			main();
		}
	
		else
		{
		printf("\nINVALID. SYSTEM AUTOMATICALLY GOES TO MAIN\n");
		main();
		}
	}
	
	return 0;	
}

void Mode() // mode, and list of zero valued variables
{
    qchicken_chop=0;
    qburger=0;
    qcheesy_wedges=0;
    qfried_chicken=0;
    qfries=0;

    qlemonade=0;
    qiced_coffee=0;
    qcoke=0;
    qapple_juice=0;

    qcheesecake=0;
    qchococake=0;
    qredvelvet=0;
    qlavacake=0;

    qchocochip=0;
    qoreo=0;
    qgreentea=0;
    qdurian=0;

    qsetA=0;
    qsetB=0;
    qsetC=0;
    
    discount=0;
    
	int option;
	printf("\n\t\t\t\t*************************\n");
	printf("\t\t\t\t 1. Current User Mode\n");
	printf("\t\t\t\t 2. Guest Mode\n");
	printf("\t\t\t\t 3. Gross Profit(Admin Only)\n");
	printf("\n\t\t\t\t*************************\n");
	printf("\t\t\t\t   Enter your option:\n\t\t\t\t\t  ");
	scanf("%d", &option);
	printf("\t\t\t\t  Executing option %d...\n", option);
	
	system("cls");
	
	if(option==1)
	{
		price=0;
		Login();	
	}
	
	else if(option==2)
	{
		price=0;
		Display();
	}
	
	else if(option==3)
	{
		adminlogin();
	}
	
	else
	{
		printf("Invalid choice.\n");
		Mode();
	}
}

void Login() //there are list of members signed in here
{
	char username[20], password[15];
	int i;
	
	
	printf("\n-------WELCOME-------\n");
	printf("PLEASE ENTER YOUR DETAILS\n");
	printf("\nEnter your username: ");
	scanf("%s", &username);
	printf("Enter your password: ");
	scanf("%s", &password);

	if(strcmp(username,"mizlqrn00")==0)
	{
		if(strcmp(password,"is_donut3")==0)
		{
			printf("\nLogin Authorized! Welcome Iskandar.");
			member();
		}
		else
		{
			printf("\nWrong username or password");
			printf("\nPress any keys to continue\n");
			getch();
			Mode();
		}
	}
	
	else if(strcmp(username,"izzamharith")==0)
	{
		if(strcmp(password,"Jamcem")==0)
		{
			printf("\nLogin Authorized! Welcome Izzam.");
			member();
		}
		else
		{
			printf("\nWrong username or password");
			printf("\nPress any keys to continue\n");
			getch();
			Mode();
		}
	}
	
	else if(strcmp(username,"azrulazmii")==0)
	{
		if(strcmp(password,"ackermann")==0)
		{
			printf("\n\nLogin Authorized! Welcome Azrul.\n");
			member();
		}
		else
		{
			printf("\nWrong username or password");
			printf("\nPress any keys to continue\n");
			getch();
			Mode();
		}
	}
	
	else if(strcmp(username,"AzimNazlen")==0)
	{
		if(strcmp(password,"Jackdaw")==0)
		{
			printf("\nLogin Authorized! Welcome Azim.");
			member();
		}
		else
		{
			printf("\nWrong username or password");
			printf("\nPress any keys to continue\n");
			getch();
			Mode();
		}
	}
	
	else if(strcmp(username,"farithhaikal69")==0)
	{
		if(strcmp(password,"farithGd96")==0)
		{
			printf("\nLogin Authorized! Welcome Farith.");
			member();
		}
		else
		{
			printf("\nWrong username or password");
			printf("\nPress any keys to continue\n");
			getch();
			Mode();
		}
	}
	
	else if(strcmp(username,"harishaikal29")==0)
	{
		if(strcmp(password,"kafka2911")==0)
		{
			printf("\nLogin Authorized! Welcome Haris.");
			member();
		}
		else
		{
			printf("\nWrong username or password");
			printf("\nPress any keys to continue\n");
			getch();
			Mode();
		}
	}
	else
	{
		printf("\nUnregistered user. Please select Guest mode.\n");
		printf("Press any keys to continue\n");
		getch();
		Mode();
	}
}

void Display() //menu, then asking for another order?
{
	char cont;
	do
	{
		menu();
		printf("\n\nDo you want to add another order? (Y-Yes N-no): ");
		scanf(" %c", &cont);
	}while(cont=='Y'||cont=='y');
    pay();
}

void member() //menu, then asking for another order? (member)
{
	char cont;
	do
	{
		membermenu();
		printf("\n\nDo you want to add another order? (Press Y if yes): ");
		scanf(" %c", &cont);
	}
	
	while(cont=='Y'||cont=='y');
	
	memberpay();

}
void menu() //food, drink, dessert, set, pay
{
	int order;
	printf("\n---WELCOME TO OUR RESTAURANT!---\n");
	printf("\n________________________________\n");
	printf("\nWhat do you want to order?\n");
	printf("1 Food\n2 Drink\n3 Dessert\n4 Set\n");
	printf("Your choice: ");
	scanf("%d", &order);
	
	if(order==1)
	food();
	
	else if(order==2)
	drink();
	
	else if(order==3)
	dessert();
	
	else if(order==4)
	set();
    
	else
	{
	    system("cls");
	    printf("INVALID INPUT. PLEASE RE-ENTER\n");
		menu();
	}
}

void membermenu()//food, drink, dessert, set
{
	int order;
	printf("\t\t\t\t\n---WELCOME TO OUR RESTAURANT!---\n");
	printf("\n________________________________\n");
	printf("\nWhat do you want to order?\n");
	printf("1 Food\n2 Drink\n3 Dessert\n4 Set\n");
	printf("Your choice: ");
	scanf("%d", &order);
	
	system("cls");
	
	if(order==1)
	food();
	
	else if(order==2)
	drink();
	
	else if(order==3)
	dessert();
	
	else if(order==4)
	set();
    
	else
	{
		system("cls");
	    printf("INVALID INPUT. PLEASE RE-ENTER\n");
		membermenu();
	}
}

void food()
{
	int choice;
	printf("\n\n");
	printf("\tFood\t\tFood\t\tItem\n");
	printf("\tNumber\t\tName\t\tPrice(RM)\n\n");
	printf("\t 1\t%s\t\t%.2f\n", chicken_chop, pchicken_chop);
	printf("\t 2\t%s\t\t\t%.2f\n", burger, pburger);
	printf("\t 3\t%s\t\t%.2f\n", cheesy_wedges, pcheesy_wedges);
	printf("\t 4\t%s\t\t%.2f\n", fried_chicken, pfried_chicken);
	printf("\t 5\t%s\t\t%.2f\n", fries, pfries);
	
	printf("\nYour choice (press 0 to cancel): ");
	scanf("%d", &choice);
	
	if(choice==1)
	{
		printf("How many %s would you like to order?\n", chicken_chop);
		scanf("%d", &qchicken_chop);
		
		price += qchicken_chop * pchicken_chop;
		system("cls");
		printf("Total price is RM%.2f", price);
	}
	
	else if(choice==2)
	{
		printf("How many %s would you like to order?\n", burger);
		scanf("%d", &qburger);
				
		price += qburger * pburger;
		system("cls");
		printf("Total price is RM%.2f", price);
	}
	
	else if(choice==3)
	{
		printf("How many %s would you like to order?\n", cheesy_wedges);
		scanf("%d", &qcheesy_wedges);
		
		price += qcheesy_wedges * pcheesy_wedges;
		system("cls");
		printf("Total price is RM%.2f", price);
	}
	
	else if(choice==4)
	{
	printf("How many %s would you like to order?\n", fried_chicken);
    scanf("%d", &qfried_chicken);
		
	price += qfried_chicken * pfried_chicken;
	system("cls");
	printf("Total price is RM%.2f", price);	
	}
	
	else if(choice==5)
	{
	printf("How many %s would you like to order?\n", fries);
	scanf("%d", &qfries);
				
	price += qfries * pfries;
	system("cls");
	printf("Total price is RM%.2f", price);	
	}
	
	else if(choice==0)
	{
		system("cls");
		menu();
	}
	else
	{
		system("cls");
		printf("\nINVALID INPUT. PLEASE RE-ENTER\n");
		food();
	}
			
}

void drink()
{
	int choice;
	printf("\n\n");
	printf("\tDrink\t\tDrink\t\tItem\n");
	printf("\tNumber\t\tName\t\tPrice(RM)\n\n");
	printf("\t 1\t%s\t\t%.2f\n", lemonade, plemonade);
	printf("\t 2\t%s\t\t%.2f\n", iced_coffee, piced_coffee);
	printf("\t 3\t%s\t\t\t%.2f\n", coke, pcoke);
	printf("\t 4\t%s\t\t%.2f\n", apple_juice, papple_juice);	
	
	printf("\nYour choice (press 0 to cancel): ");
	scanf("%d", &choice);
	
	if(choice==1)
	{
		printf("How many %s would you like to order?\n", lemonade);
		scanf("%d", &qlemonade);
		
		price += qlemonade * plemonade;
		system("cls");
		printf("Total price is RM%.2f", price);
	}
	
	else if(choice==2)
	{
		printf("How many %s would you like to order?\n", iced_coffee);
		scanf("%d", &qiced_coffee);
		
		price += qiced_coffee * piced_coffee;
		system("cls");
		printf("Total price is RM%.2f", price);
	}
	
	else if(choice==3)
	{
		printf("How many %s would you like to order?\n", coke);
		scanf("%d", &qcoke);
		
		price += qcoke * pcoke;
		system("cls");
		printf("Total price is RM%.2f", price);
	}
	
	else if(choice==4)
	{
	printf("How many %s would you like to order?\n", apple_juice);
	scanf("%d", &qapple_juice);
	
	price += qapple_juice * papple_juice;
	system("cls");
	printf("Total price is RM%.2f", price);
	
	}
	
	else if(choice==0)
	{
		system("cls");
		menu();
	}
	else
	{
	   system("cls");
	   printf("\nINVALID INPUT. PLEASE RE-ENTER\n");
	   drink();
	}
	
}
void dessert()
{
	int  order;
	printf("\n>>>>>>>>>>>>DESSERT<<<<<<<<<<<<");
	printf("\n1 Cake");
	printf("\n2 Ice cream\n");
	printf(">>>>>>>>>>>>>>>>><<<<<<<<<<<<<<\n");
	printf("Your choice (press 0 to cancel): ");
	scanf("%d",&order);
	
	if (order==1)
	{
		cake();
	}

	else if (order==2)
	{
    	icecream();
	}
	
	else if(order==0)
	{
		menu();
	}
	
	else
	{
		printf("\nINVALID INPUT\n");
		dessert();
	}
}

void cake()
{
	int choice;
		printf("\n\n");
		printf("\tDessert\t\tDessert\t\tItem\n");
		printf("\tNumber\t\tName\t\tPrice(RM)\n\n");
		printf("\t 1\t%s\t\t%.2f\n", cheesecake, pcheesecake);
		printf("\t 2\t%s\t\t%.2f\n", chococake, pchococake);
		printf("\t 3\t%s\t\t%.2f\n", redvelvet, predvelvet);
		printf("\t 4\t%s\t\t%.2f\n", lavacake, plavacake);
	
		printf("\nYour choice (press 0 to cancel): ");
		scanf("%d", &choice);
	
    		if(choice==1)
			{
				printf("How many %s would you like to order?\n",cheesecake );
				scanf("%d", &qcheesecake);
		
				price += qcheesecake * pcheesecake;
				system("cls");
				printf("Total price is RM%.2f", price);
			}
	
			else if(choice==2)
			{
				printf("How many %s would you like to order?\n",chococake );
				scanf("%d", &qchococake);
		
				price += qchococake * pchococake;
				system("cls");
				printf("Total price is RM%.2f", price);
			}
	
			else if(choice==3)
			{			
				printf("How many %s would you like to order?\n",redvelvet );
				scanf("%d", &qredvelvet);
		
				price += qredvelvet * predvelvet;
				system("cls");
				printf("Total price is RM%.2f", price);
			}		
	
			else if(choice==4)
			{
				printf("How many %s would you like to order?\n", lavacake );
				scanf("%d", &qlavacake);
	
				price += qlavacake * plavacake;
				system("cls");
				printf("Total price is RM%.2f", price);
	
			}
	
			else if(choice==0)
			{
				system("cls");
				dessert();
			}
			
			else
			{
				system("cls");
				printf("\nINVALID INPUT. PLEASE RE-ENTER\n");
				cake();
			}
		
		
}

void icecream()
{
	int choice;
		printf("\n\n");
		printf("\tDessert\t\tDessert\t\tItem\n");
		printf("\tNumber\t\tName\t\tPrice(RM)\n\n");
		printf("\t 1\t%s\t%.2f\n", chocochip, pchocochip);
		printf("\t 2\t%s\t\t%.2f\n", oreo, poreo);
		printf("\t 3\t%s\t\t%.2f\n", greentea, pgreentea);
		printf("\t 4\t%s\t\t\t%.2f\n", durian, pdurian);
	
		printf("\nYour choice (press 0 to cancel): ");
		scanf("%d", &choice);

			if(choice==1)
			{
				printf("How many %s would you like to order?\n", chocochip);
				scanf("%d", &qchocochip);
		
				price += qchocochip * pchocochip;
				system("cls");
				printf("Total price is RM%.2f", price);
			}
	
			else if(choice==2)
			{
				printf("How many %s would you like to order?\n", oreo );
				scanf("%d", &qoreo);
		
				price += qoreo * poreo;
				system("cls");
				printf("Total price is RM%.2f", price);
			}
	
			else if(choice==3)
			{
				printf("How many %s would you like to order?\n", greentea );
				scanf("%d", &qgreentea);
		
				price += qgreentea * pgreentea;
				system("cls");
				printf("Total price is RM%.2f", price);
			}
	
			else if(choice==4)
			{
				printf("How many %s would you like to order?\n", durian);
				scanf("%d", &qdurian);
	
				price += qdurian * pdurian;
				system("cls");
				printf("Total price is RM%.2f", price);
	
			}		
	
			else if(choice==0)
			{
				system("cls");
				dessert();
			}
					
			else
			{
				system("cls");
				printf("\nINVALID INPUT. PLEASE RE-ENTER\n");
				icecream();
			}
}

void set()
{
	int choice;
	printf("\n\n");
	printf("\t\t\t\t\t\n");
	printf("\tNumber\t\t\t\tPrice(RM)\n\n");
	printf("\t 1\t%s\t\t\t%.2f\n", setA, psetA);
	printf("\t\t%s\n\t\t%s\n\t\t%s\n\n", fried_chicken, cheesy_wedges, coke);
	printf("\t 2\t%s\t\t\t%.2f\n", setB, psetB);
	printf("\t\t%s\n\t\t%s\n\t\t%s\n\n", burger, fries, coke);
	printf("\t 3\t%s\t\t\t%.2f\n", setC, psetC);
	printf("\t\t%s\n\t\t%s\n\t\t%s\n\n", chicken_chop, chocochip, lemonade);
	
	printf("\nYour choice (press 0 to cancel): ");
	scanf("%d", &choice);
	
	if (choice==1)
	{
	    printf("How many %s would you like to order?\n", setA);
		scanf("%d", &qsetA);
		
		price += qsetA * psetA;
		system("cls");
		printf("Total price is RM%.2f", price);
	}
	
	else if (choice==2)
	{
		printf("How many %s would you like to order?\n", setB);
		scanf("%d", &qsetB);
		
		price += qsetB * psetB;
		system("cls");
		printf("Total price is RM%.2f", price);
	}
	
	else if (choice==3)
	{
		printf("How many %s would you like to order?\n", setC);
		scanf("%d", &qsetC);
		
		price += qsetC * psetC;
		system("cls");
		printf("Total price is RM%.2f", price);
	}
	
	else if(choice==0)
	{
		system("cls");
		menu();
	}
	
	else
	{
		system("cls");
		printf("\nINVALID INPUT. PLEASE RE-ENTER\n");
		set();
	}

}

void bill() // bill then total price
{
	time_t currentTime;
	time(&currentTime);
	
   printf("\nGenerating your receipt...\n\n");
   printf("\n*********************************************************************************\n");
   printf("\t\t\t\tBill\n");
   printf("*********************************************************************************\n");
   printf("\t\tAIN.CO VAR. CUISINE RESTAURANT\n");
   printf("\t\t  PARAMOUNTDIGM MALL, NEW JAUHAR\n");
   printf("\t\t  Haizam (M) Sdn. Bhd. (15011-U)\n");
   printf("\t\tLevel 85, No 176, Jaya Sprint Street,\n");
   printf("\t\t    90432, JAUHAR, SOUTH DIAMOND\n");
   printf("\t\t        Tel: 07-8752916\n");
   printf("\t\t         www.haifia.com\n");
   printf("\n\t\t    %s\n", ctime(&currentTime));
   printf("\n________________________________________________________________________________\n");
   printf("Product\t\t\tQty\tPrice(RM)");
   
   	if(qchicken_chop>0)
	printf("\nChicken Chop\t\t%d\tRM%.2f",qchicken_chop,pchicken_chop*qchicken_chop);
	
    if(qburger>0)
    printf("\nBurger\t\t\t%d\tRM%.2f",qburger,pburger*qburger);
    
    if(qcheesy_wedges>0)
    printf("\nCheesy Wedges\t\t%d\tRM%.2f",qcheesy_wedges,pcheesy_wedges*qcheesy_wedges);
    
    if(qfried_chicken>0)
    printf("\nFried Chicken\t\t%d\tRM%.2f",qfried_chicken,pfried_chicken*qfried_chicken);
    
    if(qfries>0)
    printf("\nFries\t\t\t%d\tRM%.2f",qfries,pfries*qfries);
    
    if(qlemonade>0)
    printf("\nLemonade\t\t%d\tRM%.2f",qlemonade,plemonade*qlemonade);
    
    if(qiced_coffee>0)
    printf("\nIced Coffee\t\t%d\tRM%.2f",qiced_coffee,piced_coffee*qiced_coffee);
    
    if(qcoke>0)
    printf("\nCoke\t\t\t%d\tRM%.2f",qcoke,pcoke*qcoke);
    
    if(qapple_juice>0)
    printf("\nApple Juice\t\t%d\tRM%.2f",qapple_juice,papple_juice*qapple_juice);
    
    if(qcheesecake>0)
    printf("\nCheese Cake\t\t%d\tRM%.2f",qcheesecake,pcheesecake*qcheesecake);
    
    if(qchococake>0)
    printf("\nChocolate Cake\t\t%d\tRM%.2f",qchococake,pchococake*qchococake);
    
    if(qredvelvet>0)
    printf("\nRed Velvet Cake\t\t%d\tRM%.2f",qredvelvet,predvelvet*qredvelvet);
    
    if(qlavacake>0)
    printf("\nLava Cake\t\t%d\tRM%.2f",qlavacake,plavacake*qlavacake);  
	  
	if(qchocochip>0)
    printf("\nChoclate Chip IceCream\t%d\tRM%.2f",qchocochip,pchocochip*qchocochip);
    
    if(qoreo>0)
    printf("\nOreo IceCream\t\t%d\tRM%.2f",qoreo,poreo*qoreo);
    
    if(qgreentea>0)
    printf("\nGreen Tea IceCream\t\%d\tRM%.2f",qgreentea,pgreentea*qgreentea);
    
    if(qdurian>0)
    printf("\nDurian Ice Cream\t\%d\tRM%.2f",qdurian,pdurian*qdurian);
    
    if(qsetA>0)
    {
       printf("\nSet A\t\t\t%d\tRM%.2f",qsetA,psetA*qsetA);
       printf("\n-fried chicken\n-cheesy wedges\n-coke");
    }
    
    if(qsetB>0)
    {
       printf("\nSet B\t\t\t%d\tRM%.2f",qsetB,psetB*qsetB);
       printf("\n-burger\n-fries\n-coke");
	}
	
    if(qsetC>0)
    {
       printf("\nSet C\t\t\t%d\tRM%.2f",qsetC,psetC*qsetC);
       printf("\n-chicken chop\n-chocochip ice cream\n-lemonade");
    }
    
    printf("\n_____________");
    printf("\nTotal Price\t\t\tRM%.2f",price);
    
    grossprofit+=price;
}

void memberbill() // bill then total price but with discount (member)
{ 
   time_t currentTime;
   time(&currentTime);
   
   printf("\nGenerating your receipt...\n\n");
   printf("\n*********************************************************************************\n");
   printf("\t\t\t\tBill\n");
   printf("*********************************************************************************\n");
   printf("\t\tAIN.CO VAR. CUISINE RESTAURANT\n");
   printf("\t\t  PARAMOUNTDIGM MALL, NEW JAUHAR\n");
   printf("\t\t  Haizam (M) Sdn. Bhd. (15011-U)\n");
   printf("\t\tLevel 85, No 176, Jaya Sprint Street,\n");
   printf("\t\t    90432, JAUHAR, SOUTH DIAMOND\n");
   printf("\t\t        Tel: 07-8752916\n");
   printf("\t\t         www.haifia.com\n");
   printf("\n\t\t    %s\n", ctime(&currentTime));
   printf("\n________________________________________________________________________________\n");
   printf("Product\t\t\tQty\tPrice(RM)");
   
  	if(qchicken_chop>0)
	printf("\nChicken Chop\t\t%d\tRM%.2f",qchicken_chop,pchicken_chop*qchicken_chop);
	
    if(qburger>0)
    printf("\nBurger\t\t\t%d\tRM%.2f",qburger,pburger*qburger);
    
    if(qcheesy_wedges>0)
    printf("\nCheesy Wedges\t\t%d\tRM%.2f",qcheesy_wedges,pcheesy_wedges*qcheesy_wedges);
    
    if(qfried_chicken>0)
    printf("\nFried Chicken\t\t%d\tRM%.2f",qfried_chicken,pfried_chicken*qfried_chicken);
    
    if(qfries>0)
    printf("\nFries\t\t\t%d\tRM%.2f",qfries,pfries*qfries);
    
    if(qlemonade>0)
    printf("\nLemonade\t\t%d\tRM%.2f",qlemonade,plemonade*qlemonade);
    
    if(qiced_coffee>0)
    printf("\nIced Coffee\t\t%d\tRM%.2f",qiced_coffee,piced_coffee*qiced_coffee);
    
    if(qcoke>0)
    printf("\nCoke\t\t\t%d\tRM%.2f",qcoke,pcoke*qcoke);
    
    if(qapple_juice>0)
    printf("\nApple Juice\t\t%d\tRM%.2f",qapple_juice,papple_juice*qapple_juice);
    
    if(qcheesecake>0)
    printf("\nCheese Cake\t\t%d\tRM%.2f",qcheesecake,pcheesecake*qcheesecake);
    
    if(qchococake>0)
    printf("\nChocolate Cake\t\t%d\tRM%.2f",qchococake,pchococake*qchococake);
    
    if(qredvelvet>0)
    printf("\nRed Velvet Cake\t\t%d\tRM%.2f",qredvelvet,predvelvet*qredvelvet);
    
    if(qlavacake>0)
    printf("\nLava Cake\t\t%d\tRM%.2f",qlavacake,plavacake*qlavacake);   
	 
	if(qchocochip>0)
    printf("\nChoclate Chip IceCream\t%d\tRM%.2f",qchocochip,pchocochip*qchocochip);
    
    if(qoreo>0)
    printf("\nOreo IceCream\t\t%d\tRM%.2f",qoreo,poreo*qoreo);
    
    if(qgreentea>0)
    printf("\nGreen Tea IceCream\t\%d\tRM%.2f",qgreentea,pgreentea*qgreentea);
    
    if(qdurian>0)
    printf("\nDurian Ice Cream\t\%d\tRM%.2f",qdurian,pdurian*qdurian);
    
    if(qsetA>0)
    {
       printf("\nSet A\t\t\t%d\tRM%.2f",qsetA,psetA*qsetA);
       printf("\n-fried chicken\n-cheesy wedges\n-coke");
    }
    
    if(qsetB>0)
    {
       printf("\nSet B\t\t\t%d\tRM%.2f",qsetB,psetB*qsetB);
       printf("\n-burger\n-fries\n-coke");
	}
	
    if(qsetC>0)
    {
       printf("\nSet C\t\t\t%d\tRM%.2f",qsetC,psetC*qsetC);
       printf("\n-chicken chop\n-chocochip ice cream\n-lemonade");
    }
    
    printf("\n_____________");
    printf("\nTotal Price\t\t\tRM%.2f\n",price);
    
    if(price<=100)
    {
    	discountprice=price;
    	discount=0;
    	
    	grossprofit+=discountprice;
	}
    
    else if(price>100 && price<200)
    {
    	discountprice=price-(price*0.05);
    	discount=5;
    	
    	grossprofit+=discountprice;
	}
    
    
    else if(price>=200 && price<300)
    {
    	discountprice=price-(price*0.1);
    	discount=10;
    	
    	grossprofit+=discountprice;
	}
    
    else if(price>=300)
    {
    	discountprice=price-(price*0.15);
    	discount=15;
    	
    	grossprofit+=discountprice;
	}
    
    printf("Price after discount\t\tRM%.2f (%d percents discount)", discountprice, discount);
    
}

void pay() // bill then pay
{
	++turnnumber;
	bill();
	printf("\nPaid:\t\t\t\tRM");
    scanf("%f",&cash);
    
    if(cash>price)
    printf("Changes\t\t\t\tRM%.2f",cash-price);
    
    else
    {
    	printf("\n\nTHE AMOUNT GIVEN IS NOT ENOUGH\nYOU ARE SHORT RM%.2f\n\n", -(cash-price));
    	pay();
	}
	
	printf("\n\nYOUR ORDER HAS BEEN PLACED.\n");
	printf("YOUR TURN NUMBER CODE IS %04d\n", turnnumber);
	printf("PLEASE PICK UP YOUR FOOD AT COUNTER WHEN IT'S YOUR TURN.\nTHANK YOU!");
	printf("\n\nPress any keys to finish...\n");
	getch();
}

void memberpay() // bill then pay (member)
{
	++turnnumber;
	memberbill();
	printf("\nPaid:\t\t\t\tRM");
    scanf("%f", &cash);
    
    if(cash>discountprice)
    printf("Changes\t\t\t\tRM%.2f",cash-discountprice);
    
    else
    {
    	printf("\n\nTHE AMOUNT GIVEN IS NOT ENOUGH\nYOU ARE SHORT RM%.2f\n\n", -(cash-discountprice));
    	memberpay();
	}
	
	printf("\n\nYOUR ORDER HAS BEEN PLACED.\n");
	printf("YOUR TURN NUMBER CODE IS %04d\n", turnnumber);
	printf("PLEASE PICK UP YOUR FOOD AT COUNTER WHEN IT'S YOUR TURN.\nTHANK YOU!");
	
	printf("\n\nPress any keys to finish\n");
	getch();
}

void adminlogin()
{
	char username[20], password[15];
	int i;
	
	printf("PLEASE ENTER YOUR DETAILS\n");
	printf("\nEnter your username: ");
	scanf("%s", &username);
	printf("Enter your password: ");
	scanf("%s", &password);
	
	if(strcmp(username,"haifia.co")==0)
	{
		if(strcmp(password,"008975")==0)
		{
			printf("\nLogin Authorized! Welcome HAIFIA ADMIN.");
			management();
		}
		else
		{
			printf("\nWrong username or password\n");
			printf("Press any keys to go back\n");
			getch();
			Mode();
		}
	}
	
	else
	{
		printf("\nWrong username or password\n");
		printf("Press any keys to go back\n");
		getch();
		Mode();

	}
}

void management()
{
	printf("\nToday's gross profit is RM%.2f", grossprofit);
	printf("\nPress any keys to continue....");
	getch();
}

