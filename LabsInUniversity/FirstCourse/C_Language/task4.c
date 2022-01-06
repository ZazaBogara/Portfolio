/*
Ввести 7 цілих беззнакових чисел, менших за 1000.
Сформувати з цих чисел матрицю розмірністю 7х10, кожен рядок якої заповнити 0 та 1 відповідно до двійкового коду введеного числа.
Надрукувати сформовану матрицю та визначити число, двійковий код якого має найменше 1
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
 
int main() 
{ 
    unsigned int arr[7]; 
    unsigned int tempArr[7]; 
    int binArray[7][10]; 
    for(int i=0; i<7; i++) 
        { 
            unsigned int input; 
            do{ 
            scanf("%ui", &input); 
            if(input>=1000) 
                printf("Bad input, try again"); 
            else 
                arr[i]=input; 
            }while(input>=1000); 
        tempArr[i]=arr[i]; 
        } 
         
    for(int i=0; i<7;i++) 
    { 
        int bin = 0, k = 1; 
        while (arr[i])//записуємо в двійковому вигляді число 
        { 
            bin += (arr[i] % 2) * k; 
            k *= 10; 
            arr[i] /= 2; 
        } 
        for(int j=9;j>=0;j--)//розкладаємо його на цифри 
        { 
            binArray[i][j]=bin%10; 
            bin/=10; 
        } 
    }         
    for(int i=0; i<7;i++) 
    { 
        for(int j=0; j<10; j++) 
        { 
            printf("%i", binArray[i][j]); 
               int position=0; 
 int counter=0; 
    for(int i=0; i<7;i++) 
    { 
        counter=0; 
        for(int j=0; j<10; j++) 
        { 
     if (binArray[i][j]==1) 
         counter++; 
        } 
        if (min>counter) 
        { 
            min=counter; 
         position=i; 
        } 
    } 
    printf("There is the number with the smallest number of 1: %u", tempArr[position]); 
    return 0; 
}