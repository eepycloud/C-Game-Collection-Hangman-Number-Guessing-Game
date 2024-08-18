	//the libraries that will be used
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "foc_fa22.h"
	//functions define
void startHangmanGame();
void startGuessTheNumberGame();
int main(){
char name[10];
int choice;
	//users name input and display welcome
printf("Enter your name: ");
scanf("%s",name);
printf("Welcome %s! \n\n",name);

//taking the users choice
	 //to choose the game
         	//using switch case to direct the user using their input
printf("Please enter the number of the game you wish to play, or choose Exit. \n1) Guess the Number.\n2) Hangman.\n3) Exit.\n >>> ");
while(choice != 4){
scanf("%d", &choice);
   switch(choice){
	case 1:
	printf("Guess the Number has started.\n");
	startGuessTheNumberGame(); 
	break;
	case 2:
	printf("Hangman has started.\n");
	startHangmanGame();
	break;
  	case 3:
  	printf("Exit\n");
  	break;
  default:
  printf("Invalid choice.\n");
  }
  choice++;
}
  return 0;
  }
  //Guess the number game function
void startGuessTheNumberGame()
{
  int highest=10000, lowest=1;
  int input;
  int mid = (lowest + highest) / 2;
  int num;
  int numberofguess = 0;
  int bar;
  int guess;

  printf( "Enter a secret number between 1 and 10000: ");
  scanf("%d",&num);
  
  guess= mid;

  // Using a do-while loop that will work until user guesses the correct number
  do
  {
        // Input by user
    printf( "Is the number %d?\n",guess );
    printf("\nPlease choose one of the following 3 options: \n1. My guess is correct \n2. The secret number is larger than %d. \n3. The secret number is smaller than %d.\n >>>  ", guess,guess);
    scanf( "%d", &input );
    switch( input ) 
    {
      case 1:
      //when the guess is right
         printf( "\nSecret number found!\n Total number of guesses you attempted is: %d\n ---- bye now ----\n",numberofguess);
            numberofguess++;

            
   case 2:
      //when the guess is larger
       lowest = mid + 1;
       mid = (lowest + highest) / 2;
       guess = mid;
           numberofguess++;
        break;
      case 3:
      //when the guess is smaller
        highest = mid - 1;
       mid = (lowest + highest) / 2;
       guess = mid;
          numberofguess++;
        break;
    }
    
  }
  while(input != 1);


// draw a graph with number of tries
 #define build 150
 int arry[build][build];  
  
bar= numberofguess*10;  

  for(int a = 0 ; a<build ;++a)    
{
  for(int b = 0 ;b<build ;++b)
    {
     arry[a][b]=255;
 
     if(a > build - bar)
     {
     
      if(b>65 && b< build - 65)    
     {   
        arry[a][b]=0;
    
     }
     }
     }
     }
	showArray(build,build,arry);
	
	printf("Please enter the number of the game you wish to play, or choose Exit. \n1) Guess the Number.\n2) Hangman.\n3) Exit.\n >>> ");
	return ;
	}
//Hangman game function
 void startHangmanGame(){
        int choice;
    int numb;
    char name[30];
    int lg[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char *co_[20]={"_","_","_","_","_","_","_","_","_","_","_","_","_","_","_","_","_","_","_","_"};
    int n_ch;
    int tries = 5; 
    char letter;
    int first=1;
    int two;
    int third;
    int fin=0;
srand(time(NULL)); 
FILE *rFile;
//looping if the user inputs a wrong choice
while(choice<1 || choice>4){
    //makes the user choose what category to use
printf("Choose a category: \n");
printf("\n1. Food.\n2. Objects.\n3. Names.\n4. Colors.\n\n");
printf("Enter the number: ");
scanf("%d",&choice);
// 16 cause we need 15 words ,so when we use %16 it means words 15
numb=rand()%16;
if (choice==1){
    rFile = fopen("food.txt","r");
for (int i=0;i<numb;i++) {
 fscanf(rFile,"%s",name);   
}
}
else if(choice==2){
    rFile = fopen("objects.txt","r");
    for (int i=0;i<numb;i++) {
 fscanf(rFile,"%s",name);   
}
}
else if(choice==3){
    rFile = fopen("names.txt","r");
for (int i=0;i<numb;i++) {
 fscanf(rFile,"%s",name);   
}
}
else if(choice==4){
    rFile = fopen("colors.txt","r");
for (int i=0;i<numb;i++) {
 fscanf(rFile,"%s",name);   
}
}
}
//to make the word appear as underscores
    n_ch = strlen(name);
while(tries != 0)
{ //to show what is the word now
printf("The word so far is: ");
for(int j = 0; j < n_ch; j++)
{
if(lg[j]==1)
{
printf(" %c", name[j]);
}
else
{
printf(" %s", co_[j]);
}
}//to show how many attempts are left after the user makes an input
printf("\nYou have %d remaining attempts.\n", tries);
printf("\nEnter a letter: ");
scanf(" %c",&letter);
first = 0;
two = 1;
third = 0;
for(int i = 0; i < n_ch; i++)
{
if(letter == name[i] && lg[i] != 1)
{
lg[i]=1;
if(two == 1)
{ //to print correct if the user inputs a correct letter
printf("\nCorrect! Keep going!\n");
two++;
}
fin++;
first = i;
third = 1;
}
}
if(lg[first] == 0 || third == 0)
{//to print not quite if the user inputs a wrong letter
printf("\nNot quite! Try again!\n");
tries--;

}
if(fin == n_ch)
{
break;
}
}
if(tries > 0)
{//to print Congratulations if the user inputs all letters correct
printf("\n Congratulations! You found the word!\n\n");
}
else
{//to print Hard luck if the user inputs all letters wrong or finished all the attempts
printf("\nHard luck! you were not able to find the word. :(\n\n");
}
printf("Please enter the number of the game you wish to play, or choose Exit. \n1) Guess the Number.\n2) Hangman.\n3) Exit.\n >>> ");
}
