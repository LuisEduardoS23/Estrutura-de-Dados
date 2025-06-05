#include <stdio.h>

int main(){

    int notas[4] = {5000, 2000, 500, 200};
    int numNotas[4] = {0, 0, 0, 0};

    
        double valorCobrado, valorPago;
        printf("\nDigite o valor cobrado: ");
        scanf("%lf", &valorCobrado);

        printf("\nDigite o valor pago: ");
        scanf("%lf", &valorPago);

        double troco = valorPago - valorCobrado;
        printf("troco : %.2lf\n", troco);

        int trocoCentavos = troco * 100;

        if(troco < 0){
            printf("\nValor pago insuficiente, ainda restam R$ %lf\n", troco * (-1));
        }
    
        else if (troco == 0){
            printf("\nObrigado pela preferencia!\n");
        }

        else{


            for (int i = 0; i < 4; i++)
            {
                if(notas[i] <= trocoCentavos){
                    numNotas[i] = trocoCentavos / notas[i];
                    trocoCentavos = trocoCentavos - numNotas[i] * notas[i];
            }
        }
    }
        for (int j = 0; j < 4; j++)
        {
            printf("%d notas de R$ %d,00.\n", numNotas[j], notas[j]/100);
        }

        printf("E mais R$ 0,%d centavos", trocoCentavos);

        



    return 0;

}