/*
 * Darnel Clayton
 * 6/4/2014
 * Final Assignment
 * final.cpp
 */

/*
 * Reevaluation: Please reevaluate Assignment 5. a5project.cpp
 * At this time I found diffuculty using bool variables only showing availble letters.Here,I use bools a primary tool to display items, control inventroy, and current shopping cart.
 * Three bool arrays are declared and intialized on lines 50,57,and 64. Items are taken out of inventory by reassigning values to false in the Add2cart functions. 
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <new>
#include <istream>
using namespace std;

class clothing{
private:
	double price;
	string name,description;
	char size;
public:
	clothing(double cost,string title,string detail, char smallBIG ){
	setPrice(cost);
	setName(title);
	setDescription(detail);
	setSize(smallBIG);}
        
	void setPrice(double &cost){price=cost;}
	void setName(string &title){name=title;}
	void setDescription(string &detail){description=detail;}
	void setSize(char &smallBIG){size=smallBIG;}
	
	double getPrice(){return price;}
	string getName(){return name;}
	string getDescription(){return description;}
	char getSize(){return size;}
};
double total=0.00,userPay=0.00;
int selection=0;

clothing watch(18.50,"Blue Watch","Blue-Oval face, Tan Leather Band, Analog Watch",'S');
clothing hat(12.50,"Red hat","Red trucker hat. Adjustable.",'S');
clothing band(8.00,"Yellow Wrist Band","Yellow athletic sweat band. Elastic",'M');
clothing chain(55.00,"Gold Necklace","100 Link Gold Necklace. Classic Style.",'M');
clothing *itemPTR[4]={&watch,&hat,&band,&chain};
bool show_Acc[5]={true,true,true,true,true};//REEVALUATE This array of bool valriables will serve to display items in current inventory, and items in shopping cart.

clothing tshirt(19.75,"Black T-Shirt"," DC logo, text reads: \"The MIND is a powerful tool\"",'M');
clothing sweatshirt(26.75,"White Long Sleeve Shirt","Plain,features no images or text.",'L');
clothing buttonUP(40.20,"Green-Blue Plaid Shirt","Shirt is a green and blue and plaid in design. \nRECNTLY MARKED DOWN. PREVIOUSLY $55.00",'L');
clothing designershirt(109.00,"Eggplant Classic Design","This Eggplant colored design is the latest from the DC collection!",'M');
clothing *shirtPTR[4]={&tshirt,&sweatshirt,&buttonUP,&designershirt};
bool show_Shirt[5]={true,true,true,true,true};

clothing cargoshort(22.25,"Olive Cargo Shorts","Shorts feature 5 pockets.",'S');
clothing bluejeans(44.35,"Classic Blue Jeans", "Comfortable fitting jeans.",'S');
clothing grayjeans(54.35,"Gray Jeans","Slim fitting jeans.",'M');
clothing designerpants(116.00,"Stylish Slacks","Slacks are made from the best materials.",'M');
clothing *pantPTR[4]={&cargoshort,&bluejeans,&grayjeans,&designerpants};
bool show_Pant[5]={true,true,true,true,true};

/*
 * Description: Function will print item name, price, details and size if the item is available. False if item is in the cart.
 * Input: Item pointers and user selection.
 * Output: Item pointers and bool arrays.
 */
void displayItem(clothing*itemPTR[], int &selection);

/*
 * Description: Functions serve as confirmation to add item to the shopping cart. User may cancel or add item to cart. Cost updated.
 * Input: Item pointers, user selection, and total cost.
 * Output: No values returned.
 */
void ringUp(double &total,clothing *itemPTR[], int &selection);
void ringupShirt(double &total,clothing *itemPTR[], int &selection);
void ringupPant(double &total,clothing *itemPTR[], int &selection);

/*
 * Description: Adds item of respective category to the shopping cart. Sets bool array to false if item is added.
 * Input: Total cost, item pointers and bool arrays
 * Output: No values returned.
 */
void addAcc2Cart(double &total, clothing *itemPTR[], int &selection,bool show_Acc[]);
void addPant2Cart(double &total, clothing *itemPTR[], int &selection, bool show_Shirt[]);
void addShirt2Cart(double &total, clothing *itemPTR[], int &selection, bool show_Pant[]);

/*
 * Description: Using bool arrays only display items that are 'false' and out of the inventory.
 * Total cost, Item pointers and bool arrays.
 * Output: No values returned.
 */
void viewCart(double &total,clothing *itemPTR[],bool show_Acc[],clothing *shirtPTR[],bool show_Shirt[]);

/*
 * Description: Shopper may clear cart with [y] or [Y] and set total to 0.00.
 * Input: Total cost, Item pointers and bool arrays.
 * Output:No values returned.
 */
void clearCart(double &total,clothing *itemPTR[],bool show_Acc[],clothing *shirtPTR[],bool show_Shirt[]);

/*
 * Description: Shopper decides to pay with CASH or CREDIT. CASH gets change in return. Loop if not enough cash entered.
 * Input: Double parameters and char variables in-function.
 * Output: No values returned.
 */
void checkOUT(double &total);

/*
 * Description: Functions call respective display functions and ringup functions based on user decsion.
 * Input: Numerical  Numerical input to represent shopper decision.
 * Output: No values returned but calls other functions based on user.
 */
void accessories(double &total);
void shirts(double &total);
void pants(double &total);

/*
 * Decription: Main menu serves as central control to call other functions.
 * Input: Numerical input to represent shopper decision.
 * Output: No values returned but uses switch statement to call chosen function.
 */
void menu();

/*
 * Description: Check and validate inpt is a # and is 1-5
 * Input: Numerical input.
 * Output: Numerical input that is sure to be a # and 1-5.
 */
void optionCheck(int &x);

/*
 * Description: Shopper confirms exit or returns to main menu function.
 * Input: No parameters
 * Output: Returns no values.
 */
void userExit();
////////////////////////////////////////////////
int main(){
menu();
return 0;}
//menu
//do while.back 2 menu
//'Q' anytime to quite and 'empty' cart.
//USER SELECT ITEMS (BOOL
//bool to show cart contents?
//add prices
//credit or cash
//overload payment function either int CREDIT or double CASH?
//
//

void menu() {
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n"
"\n"
"   *****Welcome to the C++ Clothing Store*****\n"
"\n"
"Shopping Guide:\n"
"        -Select category of clothing\n"
"\t-Compare prices\n"
"\t-Compare sizes\n"
"\t-Pay with Cash or Credit (Pay with Cash and receive change!)\n"
"\n"
"Select [1] to enter the ACCESSORY AISLE  \n"
"Select [2] to enter the SHIRT AISLE\n"
"Select [3] to enter the PANTS AISLE\n"
"Select [4] to view your SHOPPING CART\n"
"Select [5] to exit the C++ CLOTHING STORE\n"
"\n"
"** Current Cart total is: $"<<total<<"**\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n";
    int option = 0;
    while (option != 5) {
        cin>>option;
        switch(option) {
            case 1:
                accessories(total);
                break;
            case 2:
                shirts(total);
                break;
            case 3:
                pants(total);
                break;
            case 4:
                viewCart(total,itemPTR,show_Acc,shirtPTR,show_Shirt);
                break;
            case 5:
		userExit();
	}   
    }
}

void optionCheck(int &x){
        while(cin.fail()){//Check that input in numerical and 1 or 2. Will loop till input is satisfactory.
        cin.fail();
        cout<<"ERROR: Selection must be either [1],[2],[3],[4],OR [5].\n";//Alert user.
        cin.clear();//Clear stream.
        cin.ignore(9999,'\n');
        cout<<"User, please reenter your selection."<<endl;
        cin>>x;}//Re-enter input.
        while(x<1||x>5){
        cin.fail();
        cout<<"ERROR: option must be either [1],[2],[3],[4],OR [5].\n";//Alert user.
        cin.clear();//Clear stream.
        cin.ignore(9999,'\n');
        cout<<"User, please reenter your selection."<<endl;
        cin>>x;}//Re-enter input.
}
void userExit(){
int pick=0;
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n"
"\n"
"              *****THANK YOU FOR VISITING!*****\n"
"   *****PLEASE COME AGAIN!  ENJOY YOUR DAY!*****\n"
"\n"
" *****SELECT [1],[2],[3] OR,[4] TO RETURN TO THE MAIN MENU*****\n"
"            *****SELECT [5] TO EXIT*****\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl;
cin>>pick;
optionCheck(pick);
if(pick==1||pick==2||pick==3||pick==4){
menu();}
if(pick==5){
exit(EXIT_FAILURE);}
}
void accessories(double &total){
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n"
"\n"
"   ***** YOU ARE IN THE ACCESSORY AISLE!*****\n"
"   ***** ONLY AVAILABLE ITEMS ARE SHOWN *****\n";
for(int i=0;i<4;i++){
if(show_Acc[i]==true){
cout<<endl<<"   *****Select ["<<i+1<<"] for the item below*****  "<<endl;
displayItem(itemPTR,i);}
}
cout<<"\n"
"** Current Cart total is: $"<<total<<"   **\n"
"            *****SELECT [5] TO EXIT*****\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl;
cin>>selection;
optionCheck(selection);
if(show_Acc[selection-1]==true){
if(selection==1||selection==2||selection==3||selection==4){
ringUp(total,itemPTR, selection);}
}
if(show_Acc[selection-1]==false){
cout<<"ERROR: Shopper, that item is already in your Cart. Item is now out of stock."<<endl;
accessories(total);}
if(selection==5){
menu();}
}

void shirts(double &total){
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n"
"\n"
"   ***** YOU ARE IN THE SHIRT AISLE!*****\n"
"   ***** ONLY AVAILABLE ITEMS ARE SHOWN *****\n";
for(int i=0;i<4;i++){
if(show_Shirt[i]==true){
cout<<endl<<"   *****Select ["<<i+1<<"] for the item below*****  "<<endl;
displayItem(shirtPTR,i);}
}
cout<<"\n"
"** Current Cart total is: $"<<total<<"   **\n"
"            *****SELECT [5] TO EXIT*****\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl;
cin>>selection;
optionCheck(selection);
if(show_Shirt[selection-1]==true){
if(selection==1||selection==2||selection==3||selection==4){
ringupShirt(total,shirtPTR, selection);}
}
if(show_Shirt[selection-1]==false){
cout<<"ERROR: Shopper, that item is already in your Cart. Item is now out of stock."<<endl;
shirts(total);}
if(selection==5){
menu();
}
}

void pants(double &total){
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n"
"\n"
"   ***** YOU ARE IN THE PANTS AISLE!*****\n"
"   ***** ONLY AVAILABLE ITEMS ARE SHOWN *****\n";
for(int i=0;i<4;i++){
if(show_Pant[i]==true){
cout<<endl<<"   *****Select ["<<i+1<<"] for the item below*****  "<<endl;
displayItem(pantPTR,i);}
}
cout<<"\n"
"** Current Cart total is: $"<<total<<"   **\n"
"            *****SELECT [5] TO EXIT*****\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl;
cin>>selection;
optionCheck(selection);
if(show_Pant[selection-1]==true){
if(selection==1||selection==2||selection==3||selection==4){
ringupPant(total,pantPTR, selection);}
}
if(show_Pant[selection-1]==false){
cout<<"ERROR: Shopper, that item is already in your Cart. Item is now out of stock."<<endl;
pants(total);}
if(selection==5){
menu();}
//userExit();}
//viewCart(total,itemPTR,show_Acc,shirtPTR,show_Shirt);}
}

void ringUp(double &total,clothing *itemPTR[], int &selection){
int option=0;
cout<<"  *~*~*~*   You Selected an item!   *~*~*~*\n"
"        *****   \""<<itemPTR[selection-1]->getName()<<"\"   *****\n"
"Description: \""<<itemPTR[selection-1]->getDescription()<<"\"\n"
"Size: "<<itemPTR[selection-1]->getSize()<<"\n"
"Price: $"<<itemPTR[selection-1]->getPrice()<<"\n"
"\n   *~*~*~*   ADD TO YOUR CART?   *~*~*~*\n"
"Select [1],[2],[3] OR,[4] to add this item to your cart.\n"
"Select [5] to cancel the item.\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n";
cin>>option;
optionCheck(option);
if(option==1||option==2||option==3||option==4){
addAcc2Cart(total,itemPTR, selection,show_Acc);}
if(option==5){
userExit();}
}

void ringupShirt(double &total,clothing *itemPTR[], int &selection){
int option=0;
cout<<"  *~*~*~*   You Selected an item!   *~*~*~*\n"
"        *****   \""<<itemPTR[selection-1]->getName()<<"\"   *****\n"
"Description: \""<<itemPTR[selection-1]->getDescription()<<"\"\n"
"Size: "<<itemPTR[selection-1]->getSize()<<"\n"
"Price: $"<<itemPTR[selection-1]->getPrice()<<"\n"
"\n   *~*~*~*   ADD TO YOUR CART?   *~*~*~*\n"
"Select [1],[2],[3] OR,[4] to add this item to your cart.\n"
"Select [5] to cancel the item.\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n";
cin>>option;
optionCheck(option);
if(option==1||option==2||option==3||option==4){
addShirt2Cart(total,shirtPTR, selection,show_Shirt);}
if(option==5){
userExit();}
}

void ringupPant(double &total,clothing *itemPTR[], int &selection){
int option=0;
cout<<"  *~*~*~*   You Selected an item!   *~*~*~*\n"
"        *****   \""<<itemPTR[selection-1]->getName()<<"\"   *****\n"
"Description: \""<<itemPTR[selection-1]->getDescription()<<"\"\n"
"Size: "<<itemPTR[selection-1]->getSize()<<"\n"
"Price: $"<<itemPTR[selection-1]->getPrice()<<"\n"
"\n   *~*~*~*   ADD TO YOUR CART?   *~*~*~*\n"
"Select [1],[2],[3] OR,[4] to add this item to your cart.\n"
"Select [5] to cancel the item.\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n";
cin>>option;
optionCheck(option);
if(option==1||option==2||option==3||option==4){
addPant2Cart(total,pantPTR, selection,show_Pant);}
if(option==5){
userExit();}
}

void displayItem(clothing *itemPTR[], int &selection){
cout<<"        *****   \""<<itemPTR[selection]->getName()<<"\"   *****\n"
"Description: \""<<itemPTR[selection]->getDescription()<<"\"\n"
"Size: "<<itemPTR[selection]->getSize()<<"\n"
"Price: $"<<itemPTR[selection]->getPrice()<<"\n"<<endl;}

void addAcc2Cart(double &total, clothing *itemPTR[], int &selection, bool show_Acc[]){
if(selection!=5){show_Acc[selection-1]=false;}
total=total+itemPTR[selection-1]->getPrice();
cout<<"New total is: $"<<total<<endl;
return;}

void addShirt2Cart(double &total, clothing *itemPTR[], int &selection, bool show_Shirt[]){
if(selection!=5){show_Shirt[selection-1]=false;}
total=total+itemPTR[selection-1]->getPrice();
cout<<"New total is: $"<<total<<endl;
return;}

void addPant2Cart(double &total, clothing *itemPTR[], int &selection, bool show_Pant[]){
if(selection!=5){show_Pant[selection-1]=false;}
total=total+itemPTR[selection-1]->getPrice();
cout<<"New total is: $"<<total<<endl;
return;}

void viewCart(double &total,clothing *itemPTR[],bool show_Acc[],clothing *shirtPTR[],bool show_Shirt[]){
char empty='n';//Empty Cart. Set bools to true. Total =$0.00
cout<<"\t      *****YOU ARE NOW IN YOUR SHOPPING CART*****\n"
"Contents:\n";
for(int i=0;i<=4;i++){//only show items shopper selected AND confirmed to place in cart.
if(show_Acc[i]==false){
cout<<"        *****   \""<<itemPTR[i]->getName()<<"\"  $"<<itemPTR[i]->getPrice()<<"    *****\n";}
}
for(int i=0;i<=4;i++){
if(show_Shirt[i]==false){
cout<<"        *****   \""<<shirtPTR[i]->getName()<<"\"  $"<<shirtPTR[i]->getPrice()<<"    *****\n";}
}
for(int i=0;i<=4;i++){
if(show_Pant[i]==false){
cout<<"        *****   \""<<pantPTR[i]->getName()<<"\"  $"<<pantPTR[i]->getPrice()<<"    *****\n";}
}
cout<<"Total Cost is: $"<<total<<endl<<"Do you wish to empty your cart?"<<endl;
cout<<"Select [Y] to empty your cart. Select any other key to return to the main menu."<<endl;
cout<<"Select [P] to checkout and pay for the items in your cart."<<endl;
cin>>empty;
if(empty=='y'||empty=='Y'){
clearCart(total,itemPTR,show_Acc,shirtPTR,show_Shirt);}
if(empty=='p'||empty=='P'){
checkOUT(total);}
else{
cout<<"Now returning to main-menu.\n";
menu();}
}

void checkOUT(double &total){
double userMoney=0.00,userChange=0.00;
char pay='n';
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl<<"Select [C] to checkout and pay with a CREDIT CARD."<<endl;
cout<<"Select [D] to checkout and pay with CASH.";
cin>>pay;

if(pay=='c'||pay=='C'){
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl<<" $ "<<total<<" has been charged to your credit card. Thank you for shopping with us!"<<endl;
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl;
total=0.00;
userExit();}

if(pay=='d'||pay=='D'){
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl<<" $ "<<total<<" is the total cost Shopper. How much cash do you have to pay with?"<<endl;
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl;

cin>>userMoney;
	while(userMoney<total){
	cout<<"Hello Shopper that is not enough money unfortunately. Please input more money."<<endl;
	cin>>userMoney;}
userChange=userMoney-total;
total=0.00;
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl<<" $ "<<userChange<<" is your change! Thank you for shopping with us!"<<endl;
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"<<endl;
userExit();}
else{
cout<<"Now returning to main-menu.\n";
menu();}
}



void clearCart(double &total,clothing *itemPTR[],bool show_Acc[],clothing *shirtPTR[],bool show_Shirt[]){
total=0.00;
for(int i=0;i<5;i++){
show_Acc[i]=true;
show_Shirt[i]=true;
show_Pant[i]=true;}
cout<<"SHOPPING CART EMPTIED! 0 CONTENTS!"<<endl;
menu();
//viewCart(total,itemPTR,show_Acc,shirtPTR,show_Shirt);
//userExit();
}

