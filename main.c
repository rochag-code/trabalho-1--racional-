/* main.c */
/* teste do tipo de dados meudouble */
#include <stdio.h>
#include "meuracional.h"

int main ()
{

/** ------ PARTE ORIGINAL DO PROGRAMA: MEU_COMPLEXO ------*/
	MeuRacional_pt ptR1=NULL, ptR2=NULL, ptR3=NULL, ptR4=NULL;

	/*veja que aqui neste ponto faço chamadas de algumas funções
	 * através dos ponteiros que estão na tabela vtbl (ponteiro "metodo")
	 * da superclasse "Numero". Como as funções desta tabela esperam
	 * receber "ponteiro para Numero_t", preciso converter o ptX1 para
	 * Numero_pt e depois converter o resultado "de volta" para
	 * MeuDouble_pt */


	ptR1 = Racional_constroi (ptR1, 10.0, 20.0);

	ptR2 = ptR1->Metodo->copia (ptR1);

	printf ("Os dois numeros sao %s %s \n",
				ptR1->Metodo->imprime (ptR1),
				ptR2->Metodo->imprime (ptR2));

    ptR3 = Racional_constroi (ptR3, 0.0, 0.0);
    ptR4 = Racional_constroi (ptR4, 0.0, 0.0);

    ptR3 = ptR2->Metodo->atribui (ptR2, ptR3);
    printf ("ptR3 recebeu o valor de Y2 = %s \n",
				ptR3->Metodo->imprime (ptR3));


    ptR3 = ptR1->Metodo->soma(ptR1, ptR2, ptR3);
    printf ("ptR3 recebeu a soma de Y1 com Y2 = %s \n",
				ptR3->Metodo->imprime (ptR3));

    ptR3 = ptR3->Metodo->subt(ptR3, ptR2, ptR3);
    printf ("ptR3 recebeu a subtracao de Y3 com Y2 = %s \n",
				ptR3->Metodo->imprime (ptR3));

    ptR3 = ptR1->Metodo->mult(ptR1, ptR2, ptR3);
    printf ("ptR3 recebeu a multiplicacao de Y1 com Y2 = %s \n",
                 ptR3->Metodo->imprime (ptR3));

    ptR3 = ptR1->Metodo->divd(ptR1, ptR2, ptR3);
    printf ("ptR3 recebeu a divisão de Y1 com Y2 = %s \n",
                 ptR3->Metodo->imprime (ptR3));

    ptR3 = ptR1->Metodo->ac_soma(ptR3, ptR2);
    printf ("ptR3 foi somado com Y2 = %s \n",
				ptR3->Metodo->imprime (ptR3));

    ptR3 = ptR1->Metodo->ac_subt(ptR3, ptR2);
    printf ("ptR3 foi subtraido de Y2 = %s \n",
				ptR3->Metodo->imprime (ptR3));

    ptR3 = ptR1->Metodo->ac_mult(ptR3, ptR2);
    printf ("ptR3 foi multiplicado por Y2 = %s \n",
                 ptR3->Metodo->imprime (ptR3));

    ptR3 = ptR1->Metodo->ac_divd(ptR3, ptR2);
    printf ("ptR3 foi dividido por Y2 = %s \n",
                 ptR3->Metodo->imprime (ptR3));

    if (ptR1->Metodo->compara(ptR1,ptR2)== 0)
        printf("O racional ptR1 é igual ao racional ptR2 = %s \n", ptR1->Metodo->imprime(ptR1));

    if (ptR1->Metodo->compara(ptR1, ptR2 > 0))
        printf("O racional ptR1 é maior que o racional ptR2 \n");

    if (ptR1->Metodo->compara(ptR1, ptR2 < 0))
        printf("O racional ptR1 é menor que o racional ptR2 \n");

    long double R4 = Potencia_(ptR1, 4);
    _mingw_printf ("A potencia do racional ptR1 com o expoente escolhido é: %Lf \n", R4);

    long double R6 = Raizqqr_(ptR1, 3.0);
    _mingw_printf (" A raiz do racional ptR1 com o indice escolhido é %Lf \n", R6);

    int R5 = Int_proximo_(ptR1);
    printf ("O numero inteiro mais proximo do racional ptR1 é %d \n", R5);

    ptR4 = Inverso_(ptR1, ptR4);
    printf ("O numero racional ptR1 invertido é: %s \n",
                                 ptR4->Metodo->imprime (ptR4));

	ptR1->Metodo->destroi (ptR1);
	ptR2->Metodo->destroi (ptR2);
    ptR3->Metodo->destroi (ptR3);
    ptR4->Metodo->destroi (ptR4);

	return (0);
}
