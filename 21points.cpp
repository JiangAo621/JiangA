//File:21points.cpp 
//A card game played by User and Computer:the sum of your cards can't be larger than 21

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
	
void InitialCards(int Cards[52], int hand[26], float stage[1], int a[1]);
void DealCards(int Cards[52], int hand[26], float stage[1], int size, int a[1]);
void ShowCards(int hand[26], int amount);
char InputCheck();

int main(){
	char inp;
	int Cards[52], hand_user[26], hand_computer[26], a_u[1], a_c[1], size = 0, a = 0;
	float user[2], computer[2];
	
	srand(time(NULL));
	
	InitialCards(Cards, hand_user, user, a_u);
	InitialCards(Cards, hand_computer, computer, a_c);
	
	cout << "Do you want to play the game 21 points?(y/n)";
	if(InputCheck() == 'n') exit(0);
	
	cout << "\nStage of User...";
	cout << "\nYou get the cards:";
	DealCards(Cards, hand_user, user, 2, a_u);

	while (user[0] <= 21){
		cout << "\nDo you want another card?(y/n)";
		if (InputCheck() == 'n') break;
		
		cout << "You get another card:";
		DealCards(Cards, hand_user, user, 1, a_u);	
	}
	if (user[0] > 21) {cout << "\nComputer win!"; exit(0);}
	

    cout << "\nStage of Computer...";
    
    cout << "\nComputer gets the cards:";
    DealCards(Cards, hand_computer, computer, 2, a_c);
    
    while(a_c[0] < a_u[0] || (a_c[0] == a_u[0] && computer[0] < user[0])){
    	cout << "\nComputer gets another card:";
    	DealCards(Cards, hand_computer, computer, 1, a_c);
	}
	if (computer[0] > 21) {cout << "\nYou win!"; exit(0);}
	if (user[0] == computer[0]) {
		if (a_u[0] == a_c[0]) cout << "\nYou and Computer both win!";
		else{
				if (a_u[0] > a_c[0]) cout << "\nComputer win!"; 
				else cout << "\nYou win!"; 
		   	}
		}
	else {
	    if (user[0] > computer[0]) cout << "\nYou win!"; 
		else cout << "\nComputer win!"; 	
	}


return 0;
	
}


void InitialCards(int Cards[52], int hand[52], float stage[1], int a[1]){
	int j;
	for (j = 0; j < 52; ++j) Cards[j] = 0;
	for (j = 0; j < 52; ++j) hand[j] = 0 ;
	for (j = 0; j < 1 ; ++j) stage[j] = 0;
	for (j = 0; j < 1 ; ++j) a[j] = 0;
}

void DealCards(int Cards[52], int hand[26], float stage[1], int size, int a[1]){
	int current,i;
	float point_n[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0.5, 0.5, 0.5};
	
	for (i=0; i < size; ++i){
		do{
		current = rand() % 52;
	    }while (Cards[current] == -1);
	    Cards[current] == -1;
	    hand[a[0]] = current;
	    stage[0] += point_n[ current % 13 ];
	    ++ a[0];
	}
	ShowCards(hand, a[0]);
}

void ShowCards(int hand[26], int amount){
	int k;
	for(k=0; k < amount; ++k){
		switch (hand[k] / 13 ){
		    case 0 : cout << " Spade "; break;
		    case 1 : cout << " Heart "; break;
		    case 2 : cout << " Diamond "; break;                                  
		    default : cout << " Club "; break;
	    }
	    
	    switch (hand[k] % 13){
	    	case 0 : cout << 'A'; break;
	    	case 10: cout << 'J'; break;
	    	case 11: cout << 'Q'; break;
	    	case 12: cout << 'K'; break;
			default: cout <<  hand[k] % 13 + 1; break;
	    }
	}     
}


char InputCheck(){
	   char inp;
	   
	   while(true){
	   	cin >> inp;
		try{
			if (inp != 'y' && inp != 'n') throw 1;
			else throw 'a';
		}
		catch (int){
			cout << "Your input is illegal! Please try again:";
	    }
	    catch (char){
	    	break;
		}
       }
return inp;

}


