/*
З клавіатури ввести речення і слово.
Вставити введене слово в речення, зробивши його п'ятим за порядком. 
Якщо в речення менше, ніж чотири слова, то додаткове слово має стати останнім у реченні
*/

#include <stdio.h> 
#include <stdlib.h> 
 
int main() 
{ 
    char sentence[256]; 
    char word[10]; 
    gets(sentence); 
    gets(word); 
    int i=0; 
    int j=0; 
    int counter=0; 
    while(sentence[i]!='\0') 
    { 
        printf("%c", sentence[i]); 
        if(sentence[i]==' ') 
            counter++; 
        if(counter==4) 
        { 
            while(word[j]!='\0') 
            { 
                printf("%c", word[j]); 
                j++; 
            }   
            printf(" "); 
            counter++; 
        } 
        i++; 
    } 
    printf(" "); 
    j=0; 
    if(counter<4) 
        while(word[j]!='\0') 
            { 
                printf("%c", word[j]); 
                j++; 
            } 
    return 0; 
}