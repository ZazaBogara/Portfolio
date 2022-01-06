/******************************************************************************
Ввести вектор дійсних чисел. 
У новий масив занести номери тих елементів введеного вектора, які перевищують середнє значення додатних елементів вектора, 
але в два або більше раз менші за його максимальний елемент.
Надрукувати сформований масив або вивести повідомлення про відсутність таких елементів
*******************************************************************************/
#include <stdio.h> 
#define sizeOfArray 8 
int main() 
{ 
    float array[sizeOfArray]; 
    for(int i=0; i<sizeOfArray; i++)//вводимо масив 
    { 
        printf("Element %i, is ", i+1); 
        scanf("%f", &array[i]); 
    } 
    float sum=0; 
    float maximum=0; 
    for(int i=0; i<sizeOfArray; i++)//рахуємо макс значення і серед. значення всіх елем 
        { 
            if(maximum<array[i]) 
                    maximum=array[i]; 
            sum+=array[i]; 
        } 
    float average=sum/sizeOfArray; 
    printf("max element %f. \nAverage= %f\n", maximum, average); 
     
    int outputArr[sizeOfArray]; 
    for(int i=0; i<sizeOfArray; i++)//перевіряємо чи є нам потрібні елементи і запам'ятовуємо їх порядковий номер 
        if(array[i]>average && array[i]<(maximum/2)) 
            outputArr[i] = i+1; 
        else 
            outputArr[i]=0; 
             
    int empty=0; //перевірка чи є елементи що нам підходять 
    for(int i=0; i<sizeOfArray; i++) 
        if(outputArr[i]!=0) 
            empty=1; 
     
    if(empty==0) 
    { 
        printf("No this elements"); 
    } 
    else 
    { 
        printf("array = { "); 
        for(int i=0; i<sizeOfArray; i++)//вивід якщо є 
            outputArr[i]!=0 ? printf("%i ", i+1) : printf(""); 
        printf("}"); 
    } 
    return 0; 
}