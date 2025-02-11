#include <stdio.h>
#include<stdlib.h>

void outro(int numberOfWords){
printf("\n %d number of words has been genenerated !", numberOfWords);
exit(0);
}
int main(int argc, char *argv[]){   

    int Number_of_words; 

    if(argc > 1){
            Number_of_words = atoi(argv[1]); // If the user passed a number from the command line itself,
                                             // it uses that value for the number of words & skips the part
                                             // where the program ask the user to enter the number Of Words.
        } else {
            printf("Enter number of words you want to generate:");
            scanf("%d" , &Number_of_words);
        }
    FILE *OgFile;
    
    OgFile =fopen("loremIpsum.txt" , "r");

    if(OgFile == NULL){ // in cases if the file didnt open.
        printf("Didnt work, make sure that the file \"loremIpsum.txt\" is present. \n");
    } else {
        printf("Generating... \n");
    }

    

    int nullSpaces=0; // to count spaces
    char ch;

    printf("\nHere`s Your %d of LoremIpsum Text:\n\n", Number_of_words);
    
    // This do..while loop prints the characters from the loremIpsum.txt file one by one 
    // also Keeps track of the number of words 
    do{
        ch = fgetc(OgFile);
        putchar(ch);

        if(ch == ' ' || ch == "."){
            nullSpaces++;  //Each words are seperated by either white spaces or fullstops 
                            // therefore it can be used to keep track of number of words
        }
        
        if(nullSpaces == Number_of_words){ // This is where This program actually stops ends

            printf("\n\n ______________________________________________________________________");
            outro(Number_of_words);
        }
    } while(ch != EOF);

    fclose(OgFile);

    
    return 0;
}
