#include "gauss.h"
#include <stdio.h>

/**
 * Zwraca 0 - eliminacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    /**
  	 * Tutaj należy umieścić właściwą implemntację.
		 */
    printf("\n");
    printf("%d", mat->r);
    printf("\n");
    printf("%d", mat->c);
    printf("\n");
    int i, j, k;
    double mnoznik;
    for(i=0; i+1<mat->r; i++)
    {
        for(j=i+1; j<mat->r; j++)
        {
            mnoznik = mat->data[j][i] / mat->data[i][i];
            for(k=0; k<mat->c; k++)
            {
                mat->data[j][k] -= mnoznik * mat->data[i][k];
            }
            b->data[j][0] -= mnoznik * b->data[i][0];
        }
    }
    return 0;
}

