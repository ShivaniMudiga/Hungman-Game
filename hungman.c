/* It is a code for hangman game where one player has to give the word and the other player as to guess it 
in 6 chances */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// the header file string.h is used to calucate the length of string
// the header file stdlib.h is used to use the predefined function system("cls") 
int main()
{
    printf("**************** WELCOME TO HANGMAN GAME ****************\n");
    printf("RULES OF THE GAME :\n");
    printf("->It is a two player game\n->Player 1 has to give the word and Player 2 has to guess the word\n");
    printf("->Player 2 will be given 6 chances to guess the letters in the word\n");
    printf("->If the guessed letter is correct the dashes will be \n    filled with that letter \n");
    printf("*********************   GAME STARTS  ********************\n");
    int size,i=1,j,is_guess,word_count=0,is_won=0,wrong_guess=0,chance=6,hint;
    char guess;
    char word[20],new_word[20];
    // the array word is for charcters of the word in lower case
    //the array new_word is to replace the '_' with the correct guessed letter
    printf("Player 1: Enter  your word \n");
    scanf("%s",word);
    printf("\nGive any letter as a hint to 2nd player: \n");
    scanf(" %c",&hint);
    size=strlen(word);
    //printf("%d",size);
    system("cls");
    // system("cls") is uesd to clear screen
    printf("GET READY PLAYER 2:\n");
    printf("HINT : '%c' is one of the letter \n",hint);
    for(j=0;j<size;j++)
    {
        printf("_ ");
        new_word[j]='_';
    }
    printf("\n\n");
    while(chance>0)
    {
        if(word_count==size)
        {
            printf("CONGRATULATION! PLAYER 2 WON \n ");
            is_won=1;
            break;
        }
        is_guess=0;
        printf("Guess any letter :\n");
        scanf(" %c",&guess);
        //printf("guess= %c\n",guess);
        for(j=0;j<size;j++)
        {
            if(guess==word[j])
            {
                printf("GREAT! you guessed it right\n\n");
                new_word[j]=word[j];
                is_guess=1;
                word_count++;
                
            }
        }
        if(is_guess==0 )
        {
            wrong_guess++;
            printf("OOPS! You guessed it wrong.Try again.Chances left = %d\n\n",--chance);
            switch(wrong_guess)
            {
                case 1: printf("_ _ _ _ _ _ _ \n");
                        printf("|        O     \n");
                        printf("|             \n");
                        printf("|             \n");
                        printf("|               \n");\
                        break;
                case 2: printf("_ _ _ _ _ _ _ \n");
                        printf("|        O     \n");
                        printf("|        |     \n");
                        printf("|              \n");
                        printf("|               \n");
                        break;
                case 3: printf("_ _ _ _ _ _ _ \n");
                        printf("|        O     \n");
                        printf("|       /|   \n");
                        printf("|             \n");
                        printf("|               \n");
                        break;
                case 4: printf("_ _ _ _ _ _ _ \n");
                        printf("|        O     \n");
                        printf("|       /|\\   \n");
                        printf("|              \n");
                        printf("|               \n");
                        break;
                case 5: printf("_ _ _ _ _ _ _ \n");
                        printf("|        O     \n");
                        printf("|       /|\\   \n");
                        printf("|       /      \n");
                        printf("|               \n");
                        break;
                default: printf(" ");
            }
            
        }
        printf("\n");
        for(j=0;j<size;j++)
        {
            printf(" %c ",new_word[j]);
        }
        printf("\n\n********************************************************\n\n");
        
    }
    int player1_won=0;
    if(is_won==0)
    {
        for(j=0;j<size;j++)
        {
            if(new_word[j]==word[j])
            {
                player1_won++;
            }
        }
        if(player1_won==size)
        {
            printf("CONGRATULATIONS! PLAYER 2 WON \n ");
        }
        else
        {
            printf("CONGRATULATIONS! PLAYER 1 WON \n ");
            printf("_ _ _ _ _ _ _ \n");
            printf("|        O     \n");
            printf("|       /|\\   \n");
            printf("|       / \\   \n");
            printf("|               \n");
            printf("******HUNGMAN*****\n");
        }
        printf("\nThe word is -> %s",word);
        printf("\n\n##### GAME ENDS #####\n");
    }
   
    
    

}
