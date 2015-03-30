//File:GuessNumber.cpp 
//Guess the number

#include<cstdlib> 
#include<ctime>
#include<iostream>
using namespace std;

int main()
{	int num1, num2, num3, i, j, guess1, guess2, guess3, numA, numB, win=0,lose=0;	   //num1,num2,num3:random numbers       i,j:cyclic variables 
    char answer;                                                                       //guess1,guess2,guess3:three numbers that you predict 
																	                   //win:the times you win        lose:the times you lose     
																	                   //numA:right place and right number  numB:right number but wrong place
																	                   //answer:if the user want play the name or not 
	
	srand(time(NULL));												                   //initialization of random
	
    for(i = 1; ++ i;)
        {
		cout << "Do you want to play the game?(Y/N)" ;                               //ask user if he wants to play or not
		cin >> answer;
        
		if (answer == 'Y')
		{
			num1 = rand() * 10 / (RAND_MAX + 1); 							              //get random num1
	
	    		do{																
	       			num2 = rand() * 10 / (RAND_MAX + 1); 
        		}while (num1 == num2);                                        	              //get random num2,which differs from num1
    
	    		do{
				 num3 = rand() * 10 / (RAND_MAX + 1); 
			 }while (num2 == num3 || num1 == num3) ;                                       //get random num3,which differs from num1 and num2
			 
			 for (j = 1; j <= 7; ++j)                                                 //set a circulation of 7 times
			 {
	  		 cout << "Pleae input your guess:" ;                                      //get the numbers users guess
        		 cin >> guess1 >> guess2 >> guess3; 
        
         	 	numA = ( (num1 == guess1) + (num2 == guess2) + (num3 == guess3) );      
        	 	numB = ( (num1 == guess2) ||  (num1 == guess3) + 
		        	 (num2 == guess1) || (num2 == guess3) +
				 (num3 == guess1) || (num3 == guess2) );
	    
	    		 if (numA == 3)	{cout << "Congratulations,you win!" << endl; ++ win; break;}        //if win,break the circulation.win plus 1.
			 	else cout << numA << "A" << numB << "B" << endl;                                   //if fail the match,display the hint.
	                  }
	     	if (numA != 3) {cout << "Sorry.You fail to get the numbers in 7 times.The answer is" << num1 << num2 << num3 << endl; ++ lose; }
			                                                                                    //if the user can't get the answer in 7 times,display the answer
        }
		else {cout << "You have already played" << i-2 << "times.WIN for" << win << "times and LOSE for" << lose << "times."; break;} 
		                                                                                        //if the user wants to quit the game,display the information.
        
	
    }
    return 0; 
	
}
