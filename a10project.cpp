/*
 * Darnel Clayton
 * 6/2/2014
 * Assignment 10
 * a10project.cpp
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class nGuess{
private:
	int playerGuess,nRandom,nGuesses;

public:
/*
 * Decription: Redisgned Secret # guessing game assignment. User guesses # 1-50. 5 guesses alotted. Report if guess is too high/low.
 * Input: Numerical input.
 * Output: No returned value.
 */
	void nGame();
/*
 * Description: Function checks and validates user input is numerical and within 1-50 range
 * Input: Numerical input
 * Output: Numerical output but it is now validated to be numerical and within 1-50 range.
 */
	void nGuessCheck(int &x);
/*
 * Description: Function evaluates for winning guesses when there are > 0 guesses remaining.
 * Input: User's numerical guess, games random-secret #, and # guesses remaing.
 * Output: No returned values. Report to user within funtion and terminates game. User returned to main() function. 
 */
	void nWinner(int playerGuess,int &nRandom,int &nGuesses);
};

class wordGuess{
private:
	string gameWord,userStr;
	int nGuesses;
public:

/*
 * Description: Selects secret word from a string array. 5 guesses given, user guesses word based on hints given.
 * Input: No paramerters but user inputs string input as guess.
 * Output: No output values.
 */
	void wordGame();
/*
 * Description: Senses every user guess is equal to secret word when there are > 0 guesses remaining.
 * Input: Secret word to be guessed, user's guess, and # of guesses.
 * Output: Returns true or false.
 */
	bool wordWinner(string &gameWord,string &userStr,int &nGuesses);
};

class phraseGuess{
private:
	string gamePhrase,userPhrase;
        int nGuesses;
public:
/*
 * Description: Selects secret words from a string array.String combined to make phrase. 10 guesses given, user guesses phrase based on hints given.
 * Input: No paramerters but user inputs string input as guess.
 * Output: No output values.
 */
        void phraseGame();
/*
 * Description: Senses every user guess is equal to secret phrase when there are > 0 guesses remaining.   
 * Input: Secret phrase to be guessed, user's guess, and # of guesses.
 * Output: Returns true or false.
 */
	 bool phraseWinner(string &gamePhrase,string &userPhrase,int &nGuesses);
};

/*
 * Description: Menu function. User chooses available games to play.
 * Input: Numerical inpt represents user decision.
 * Output: Call to game function.
 */
void menu();

/*
 * Description: Function checks and validates user input is numerical and within range
 * Input: Numerical input
 * Output: Numerical output but it is now validated to be numerical and within range.
 */
void optionCheck(int &x);

nGuess what;//Global declarations of available games.
wordGuess who;
phraseGuess where;

int main()
{
char back2Menu;//Return user to menu. Play again?
do{
menu();
cout<<endl<<"~*~GAME OVER~*~"<<endl<<"SELECT [Y] TO THE MAIN MENU!\n";
cin>>back2Menu;//Main menu or quit. 
}while(back2Menu=='Y'||back2Menu=='y');
return 0;
}

void nGuess::nGame(){
srand(time(0));
nRandom=1+(rand()%50);
nGuesses=5;
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n"
"YOU SELECTED [1]\n"
"\n"
"WELCOME to the RANDOM NUMBER GUESSING GAME! \n"
"\n"
"Rules:\n"
"         - Successfully guess a number 1-50. 5 attempts allowed.\n"
"         - Your guess should be a number 1-50.\n"
"\n"
"\"Player, enter a number 1-50."<<nGuesses<<" guesses remaning.\"\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n";
nWinner(playerGuess,nRandom,nGuesses);
if(nGuesses==0){
        cout<<"0 Guesses remaining. The secret # is :"<<nRandom<<endl;
        return;}
}

void nGuess::nWinner(int playerGuess,int &nRandom,int &nGuesses){
while(nGuesses>0){
	cout<<"*** Player, enter a number 1 - 50! ***"<<endl<<"You may guess "<<nGuesses<<" more times!"<<endl;
	cin>>playerGuess;
	nGuessCheck(playerGuess);	
	nGuesses--;
	if (playerGuess==nRandom){
	cout<<"*****WINNER*****"<<endl<<"Congrats Player! You correctly guessed the number with "<<nGuesses<<" guesses remaining!\n";
	nGuesses=0;
	return;}
	if(playerGuess<nRandom){
	cout<<"Your guess is incorrect and TOO LOW. Try again! You may guess "<<nGuesses<<" more times.\n";
	nWinner(playerGuess,nRandom,nGuesses);}	
	if(playerGuess>nRandom){
        cout<<"Your guess is incorrect and TOO HIGH. Try again! You may guess "<<nGuesses<<" more times.\n";
        nWinner(playerGuess,nRandom,nGuesses);}
	}
}

void nGuess::nGuessCheck(int &x){
        while(cin.fail()){//Check that input in numerical and 1 or 2. Will loop till input is satisfactory.
        cin.fail();
        cout<<"ERROR: option numerical value .\n";//Alert user.
        cin.clear();//Clear stream.
        cin.ignore(9999,'\n');
        cout<<"User, please reenter your selection."<<endl;
        cin>>x;}//Re-enter input.
        while(x<1||x>50){
        cin.fail();
        cout<<"ERROR: Your may be at least '1' or at most '50'.\n";//Alert user.
        cin.clear();//Clear stream.
        cin.ignore(9999,'\n');
        cout<<"User, please reenter your selection."<<endl;
        cin>>x;}//Re-enter input.
        }

void wordGuess::wordGame(){
bool winner;
nGuesses=5;
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n"
"YOU SELECTED [2]\n"
"\n"
"**************WELCOME to the RANDOM WORD GUESSING GAME!**********************\n"
"\n"
"\"Rules:\n"
"         -Successfully guess a 5 Letter Word. *HINTS WILL BE GIVEN* 5 attempts allowed.\n"
"\t -Your guess should be 5 characters long. \n"
"\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n";
string wordBank[10]={"phone","movie","acorn","blimp","cache","glare","juice","niche","pilot","quart"};
srand(time(0));
int random5Word=1+(rand()%10);
gameWord=wordBank[random5Word];
cout<<"*****"<<endl<<"HINT:  Player, word begins with \""<<gameWord.at(0)<<"\" and ends with \""<<gameWord.at(4)<<"\".*****"<<endl;
winner=wordWinner(gameWord,userStr,nGuesses);
	if(winner==true){//Player wins
	cout<<"***WOW! CONGRATULATIONS PLAYER! You successfully guessed: \""<<gameWord<<"\" with "<<nGuesses<<" guesses remaining! Great Job!***"<<endl;}
	if(winner==false){
	cout<<"Sorry Player. You did not win. The secret word was: \""<<gameWord<<"\" I hope you had fun and better luck next time!"<<endl;}
return;}

bool wordGuess::wordWinner(string &gameWord,string &userStr,int &nGuesses){
int count=0;//Count how many correct letters correctly.
while(nGuesses>0){
	cout<<"Player, guess the secret word! Secret word begins with \""<<gameWord.at(0)<<"\" and ends with \""<<gameWord.at(4)<<"\" ."<<endl; 
	cout<<"Player, "<<nGuesses<<" guesses remaning."<<endl;
	cin>>userStr;
char temp;
char guess[5];
char word[5];
	if(userStr.length()==gameWord.length()){
		for(int i=0;i<gameWord.length();i++){
			temp=userStr.at(i);
                        guess[i]=temp;
                        word[i]=gameWord.at(i);
		if(userStr.at(i)==gameWord.at(i)){//If character at position 'x' is the same in both strings, report to the user.
        	cout<<"At position "<<i+1<<" both strings share '"<<gameWord.at(i)<<"' in content!\n";
        	count++;}
			if(count==5){//PLAYER WINS!
			return true;}
		}
	count=0;
	}
	nGuesses--;}
return false;//0 GUESSES REMAINING AND PLAYER DOES NOT WIN :/
}

void phraseGuess::phraseGame(){
bool winner;
nGuesses=10;
cout<<cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n"
"YOU SELECTED [3]\n"
"\n"
"**************WELCOME to the RANDOM PHRASE GUESSING GAME!**********************\n"
"\n"
"\"Rules:\n"
"         -Successfully guess a 10 Letter PHRASE. *HINTS WILL BE GIVEN* 10 attempts allowed.\n"
"         -Random phrase is made of 2 words withOUT any space in between.\n"
"\t -Your guess should be 10 characters long. \n"
"\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n";
string phraseBank[5]={"phone","movie","acorn","blimp","cache"};
string phraseBank2[5]={"glare","juice","niche","pilot","boxer"};
srand(time(0));
int random15Phrase=1+(rand()%5);
gamePhrase=phraseBank[random15Phrase]+phraseBank2[random15Phrase];
cout<<"*****"<<endl<<"HINT:  Player, word begins with \""<<gamePhrase.at(0)<<"\" and ends with \""<<gamePhrase.at(9)<<"\".*****"<<endl;
winner=phraseWinner(gamePhrase,userPhrase,nGuesses);
        if(winner==true){//Player wins
        cout<<"***WOW! CONGRATULATIONS PLAYER! You successfully guessed: \""<<gamePhrase<<"\" with "<<nGuesses<<" guesses remaining! Great Job!***"<<endl;}
        if(winner==false){
        cout<<"Sorry Player. You did not win. The secret word was: \""<<gamePhrase<<"\" I hope you had fun and better luck next time!"<<endl;}
return;}

bool phraseGuess::phraseWinner(string &gamePhrase,string &userPhrase,int &nGuesses){
int count=0;//Count how many correct letters correctly.
while(nGuesses>0){
        cout<<"Player, guess the secret word! Secret word begins with \""<<gamePhrase.at(0)<<"\" and ends with \""<<gamePhrase.at(9)<<"\" ."<<endl;
        cout<<"Player, "<<nGuesses<<" guesses remaning."<<endl;
        cin>>userPhrase;
char temp;
char guess[10];
char phrase[10];
	if(userPhrase.length()==gamePhrase.length()){
	        for(int i=0;i<gamePhrase.length();i++){
			temp=userPhrase.at(i);
			guess[i]=temp;
			phrase[i]=gamePhrase.at(i);
                if(userPhrase.at(i)==gamePhrase.at(i)){//If character at position 'x' is the same in both strings, report to the user.
                cout<<"At position "<<i+1<<" both strings share '"<<gamePhrase.at(i)<<"' in content!\n";
                count++;}
                        if(count==10){//PLAYER WINS!
                        return true;}
                }
        count=0;
        }
        nGuesses--;}
return false;//0 GUESSES REMAINING AND PLAYER DOES NOT WIN :/
}

void menu(){
int option=0;
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n"
"WELCOME TO DARNEL CLAYTON'S ARCADE\n"
"*** YOU ARE ARE AT THE MAIN MENU***\n"
"SELECT YOUR [OPTION] AND PRESS [ENTER] TO BEGIN\n"
"[1] - NUMBER GUESS\n"
"\n"
"[2] - WORD GUESS\n"
"\n"
"[3] - PHRASE GUESS\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n";
cin>>option;
optionCheck(option);
switch(option) {
case 1:
what.nGame();
break;
case 2:
who.wordGame();
break;
case 3:
where.phraseGame();
break;        }
}

void optionCheck(int &x){
        while(cin.fail())//Check that input in numerical and 1 or 2. Will loop till input is satisfactory.
        {
        cin.fail();
        cout<<"ERROR: Selection must be either [1],[2], OR [3].\n";//Alert user.
        cin.clear();//Clear stream.
        cin.ignore(9999,'\n');
        cout<<"User, please reenter your selection."<<endl;
        cin>>x;//Re-enter input.
        }
        while(x<1||x>3)
        {
        cin.fail();
        cout<<"ERROR: option must be either [1],[2], OR [3].\n";//Alert user.
        cin.clear();//Clear stream.
        cin.ignore(9999,'\n');
        cout<<"User, please reenter your selection."<<endl;
        cin>>x;//Re-enter input.
        }
        }
