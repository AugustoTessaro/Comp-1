#include <stdio.h>

float rigidez(float forca, float deflexao)
{
    float k;
    k = forca / deflexao;
    return k;

}


float rigidez_eq(float f1, float f2, float f3, float d1, float d2, float d3, int type)
{
    float k[3];
    float k_eqp = 0;
    float k_eqs = 0;
    k[0] = rigidez(f1, d1);
    k[1] = rigidez(f2, d2);
    k[2] = rigidez(f3, d3);

    //Se o tipo for 1 então a função calcula a rigidez em paralelo se o tipo fo = 0 entao calcula a rigidez em serie 
    if(type == 1)
    {
        for(int i = 0; i < 3; i++)
        {
            k_eqp = k_eqp + k[i];
        }
       
        return k_eqp;

    }else
    {
        for(int i = 0; i < 3; i++)
        {
            k_eqs =+ (1/k[i]);
        }

        return 1/k_eqs;
    }


}


int main(){
    float f1, f2, f3, d1, d2, d3, k_eqp, k_eqs;

    // Entrada de dados
    printf("Digite 3 forcas e 3 deflexoes:\n");
    scanf("%f %f %f %f %f %f", &f1, &f2, &f3, &d1, &d2, &d3);

    k_eqp = rigidez_eq(f1, f2, f3, d1, d2, d3, 1);
    k_eqs = rigidez_eq(f1, f2, f3, d1, d2, d3, 0);

    printf("Rigidez equivalente da mola em paralelo é %.4f \n Rigidez equivalente da mola em serie é %.4f", k_eqp, k_eqs);


    return 0;
}