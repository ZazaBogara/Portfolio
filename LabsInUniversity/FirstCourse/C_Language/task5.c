/*
1. Задано довге цілу число. Написати вираз, який повертає суму двох середніх байт цього числа.
2. Скласти програму підрахунку кількості різних чисел в масиві, елементами якого є додатні двобайтні значення
3. Послідовно згенерувати 10 випадкових трицифрових чисел. Надрукувати ті, в яких перша і останні цифра співпадають. Визначити відсоток таких чисел
*/
#include <stdio.h> 
#include  <time.h>

#define n 10

void task1()
{
    int num=0xaabbcc55;
    printf("\n");
    printf("%i", ((int)(num&0x00ff0000)>>16)+(int)((num&0x0000ff00)>>8));
}

void task2()
{
    unsigned short int arr[n];
    int checked[n];
    int state;
    int counter = n;
    for(int i=0; i<n; i++)
        scanf("%hi", &arr[i]);
        
        
    unsigned short int tmp;
    int noSwap;
    for (int i = n - 1; i >= 0; i--)//Сортування Бульбашкою
    {
        noSwap = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                noSwap = 0;
            }
        }
    if (noSwap == 1)
        break;
    }
    
    for(int i=0; i<n-1;i++)
        {
            state=1;
            for(int k=0; k<n; k++)
                if(arr[i]==checked[k])
                    state=0;
            if(state==1){
                checked[i]=arr[i];
                for(int j=i+1; j<n;j++)
                {
                    if(checked[i]==arr[j])
                        counter--;
                }
            }
        }
        printf("%i", counter);
}

void task3()
{
    int arr[10];
    int arr1[10];
    srand(time(NULL));
    for(int i=0;i<10;i++)
    {
        arr[i]=rand()%900+100;
        arr1[i]=arr[i];
    }   
    for(int i=0;i<10;i++)
        printf("%i\n", arr[i]);
    int counter=0;
    printf("\nLast==First\n");
    for(int i=0; i<10; i++)
    {
        int state=0;
        int first=arr1[i]%10;
        int last=arr1[i]/=100;
        if(first==last)
            state=1;
        
        if(state==1)
        {
            printf("%i\n", arr[i]);
            counter++;
        }
    }
    printf("Percent: %i", counter*10);
}

int main()
{
    return 0;
}
