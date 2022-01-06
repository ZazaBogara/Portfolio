/******************************************************************************
З клавіатури ввести послідовність дійсних чисел (закінчити введення довільною літерою).
Визначити номер максимального числа та середнє значення всіх введених чисел
*******************************************************************************/
#include <stdio.h>
int main() 
{
    int Array[256];
    int size = 0;
    char input;
    scanf("%c", &input);
    while(input>=48 && input<=57) 
    {
        Array[size] = (int)input-48; size++;
        scanf("%c", &input);
    }
    for(int i=0; i<size; i++)
        printf("%i ", Array[i]);
    printf("\nSize - %i\n", size); int sum=0;
    int position=0;
    int maximum=0;
    for(int i=0; i<size; i++)
    {
        if(maximum<Array[i])
        {
            maximum=Array[i];
            position=i; 
        }
        sum+=Array[i]; 
    }
    float average=sum/size;
    printf("In Position %i, is max element %i. \n Average= %f", position+1, maximum, average);
    return 0;
}