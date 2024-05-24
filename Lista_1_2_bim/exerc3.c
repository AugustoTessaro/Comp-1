#include <stdio.h>



int main(){
    int input_number, numbers[15], soma;
    soma = 0;

    for (int i = 0; i < 15; i++)
    {
        printf("Digite um numero\n");
        scanf("%d", &input_number);


        while(input_number % 3 != 0)
        {
            printf("Digite um numero\n");
            scanf("%d", &input_number);
        }
        numbers[i] = input_number;
    }

    for (int i = 0; i < 15; i++)
    {
        soma += numbers[i];
    }
    
    printf("%d", soma);




    return 0;
}