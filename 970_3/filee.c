#include<stdio.h>
#include<stdbool.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

int main(){
  int wordcnt=0;
  int alphabets=0;
  int dig=0;
  int lines=0;
  char word[50];
char ch;
  FILE*file;
  file = fopen("./file.txt","r");
  if(file ==NULL){
    printf("Couldnt open....sed-lyf");
    return 1;
  }
  else{
    while((ch = fgetc(file)) != EOF){
        if(isalpha(ch)){
            alphabets++;
        }
        else if(isdigit(ch)){
            dig++;
        }
        else if(ch == '\n'){
            lines++;
        }
    }
    rewind(file);
    while(fscanf(file,"%s",word) != EOF){
        wordcnt++;
    }
  }
  fclose(file);

   printf("words : %d\n",wordcnt);
   printf("lines : %d\n", lines+1);
   printf("alphabets : %d\n", alphabets);
   printf("digits : %d\n", dig);

   return 0;
}
































// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdbool.h>

// // List of C keywords
// const char *keywords[] = {
//     "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern",
//     "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static",
//     "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
// const int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

// // Function to check if a string is a keyword
// bool isKeyword(const char *str)
// {
//     for (int i = 0; i < numKeywords; i++)
//     {
//         if (strcmp(str, keywords[i]) == 0)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// int main()
// {
//     FILE *file;
//     char word[50];
//     int keywordCount = 0, wordCount = 0, alphabetCount = 0, digitCount = 0, lineCount = 0;
//     char ch;

//     // Open the file in read mode
//     file = fopen("File.txt", "r");
//     if (file == NULL)
//     {
//         printf("Error: Could not open File.txt.\n");
//         return 1;
//     }

//     // Read the file character by character
//     while ((ch = fgetc(file)) != EOF)
//     {
//         // Count alphabets
//         if (isalpha(ch))
//         {
//             alphabetCount++;
//         }
//         // Count digits
//         else if (isdigit(ch))
//         {
//             digitCount++;
//         }
//         // Count lines
//         else if (ch == '\n')
//         {
//             lineCount++;
//         }
//     }

//     // Move file pointer back to the beginning to count words and keywords
//     rewind(file);

//     // Read each word from the file and check if it's a keyword
//     while (fscanf(file, "%s", word) != EOF)
//     {
//         wordCount++;
//         if (isKeyword(word))
//         {
//             keywordCount++;
//         }
//     }

//     // Count the last line if the file does not end with a newline character
//     if (ch != '\n' && lineCount > 0)
//     {
//         lineCount++;
//     }

//     // Close the file
//     fclose(file);

//     // Display the results
//     printf("Number of keywords in the file: %d\n", keywordCount);
//     printf("Number of words in the file: %d\n", wordCount);
//     printf("Number of alphabets in the file: %d\n", alphabetCount);
//     printf("Number of digits in the file: %d\n", digitCount);
//     printf("Number of lines in the file: %d\n", lineCount);

//     return 0;
// }
