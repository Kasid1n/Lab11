#include<iostream>
#include<string>
#include<ctime>
using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
	//Write the function to random the number from 1 to 13 and return that random number.
	int d = rand()%13+1;
	if(d==1) return 1;
	if(d==2) return 2;
	if(d==3) return 3;
	if(d==4) return 4;
	if(d==5) return 5;
	if(d==6) return 6;
	if(d==7) return 7;
	if(d==8) return 8;
	if(d==9) return 9;
	if(d==10) return 10;
	if(d==11) return 11;
	if(d==12) return 12;
	if(d==13) return 13;
	return 0;
	//srand() is used in main(). Do not use srand() here.
}

int calScore(int x,int y,int z){
	//Write the function to calculate the score with is the rightmost digit of summation of the scores from three cards.
	if(x==11 || x ==12 || x==13){
	    x=10;
	}
	if(y==11 || y==12 || y==13){
	    y=10;
	}
	
	if(z==11 || z==12 || z==13){
	    z=10;
	}
	int sum = x+y+z;
	int score = sum%10;
	return score;
	//Return the score. 
}

int findYugiAction(int s){	
	if(s == 9) return 2; // Yugi will definitely stay (2) when current score (s) is equal to 9
	else if(s < 6) return 1; // Yugi will definitely draw (1) when current score (s) is less than 6
	else{
		// If current score is 6,7,8, Yugi will draw with probability 69% and will stay with probability 31% 
		int draw = rand()%100+1;
		if(draw <=31) return 2;
		else return 1;

		// Write conditions here using random number 
	}
}

void checkWinner(int p, int y){
	// Write condition for cout in this function
	cout << "\n---------------------------------\n";
	if (p==y)
	cout <<   "|             Draw!!!           |"; // when p is equal to y
	if(p>y)
	cout <<   "|         Player wins!!!        |"; // when p is greater than y
	if(p<y)
	cout <<   "|          Yugi wins!!!         |"; // when p is less than y
	cout << "\n---------------------------------\n";
}

int main(){	
    srand(time(0)); //This line of code is not completed. Fill the correct input of srand(); 

	int playerScore, yugiScore, playerAction, yugiAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3] = {drawCard(), drawCard(), 0}; //This line of code is not completed. You need to initialize value of yugiCards[].
	
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(playerAction !=1 && playerAction !=2); //This line of code is not completed. You need to set the condition to do loop if user's input is not 1 or 2. 
	if(playerAction == 1){
		//The following lines of code are not completed. Please correct it.
		
		playerCards[2] = drawCard();
  		playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
		cout << "Player draws the 3rd card!!!" << "\n";
		cout << "Your 3rd card: " <<cardNames[playerCards[2]]<<"\n";
		cout << "Your new score: " <<playerScore<< "\n";
		
	}
	cout << "------------ Turn end -------------------\n\n";
	
	
	//The following lines of code for Yugi's turn are not completed. Please correct it.
	
	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]] <<  "\n";
	yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
	cout << "Yugi's score: " << yugiScore << "\n";
	yugiAction = findYugiAction(yugiScore);
	if(yugiAction == 1){
		yugiCards[2] = drawCard();
		cout << "Yugi draws the 3rd card!!!\n";
		cout << "Yugi's 3rd card: " <<cardNames[yugiCards[2]]<<"\n";
		yugiScore= calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
		cout << "Yugi's new score: " <<yugiScore<< "\n";
	}
	cout << "------------ Turn end -------------------\n";
	
	
	checkWinner(playerScore,yugiScore);
}
