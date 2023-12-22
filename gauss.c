#include "gauss.h"
#include <math.h>
#define ZERO 0.000001
void zamiana(Matrix *mat, Matrix *b, int x)
{
    int max = x;
    double maxvalue = fabs(mat->data[x][x]);
    for(int i = x+1; i < mat->r; i++)
    {
        if(fabs(mat->data[i][x]) > maxvalue) {
            max = i;
            maxvalue = fabs(mat->data[i][x]);
        }
    }
    double* temp = mat->data[x];
    mat->data[x] = mat->data[max];
    mat->data[max] = temp;
    temp = b->data[x];
    b->data[x] = b->data[max];
    b->data[max] = temp;
}
/**
 * Zwraca 0 - eliminacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    int i, j, k;
    double mnoznik;
    for(i=0; i+1<mat->r; i++)
    {
        zamiana(mat, b, i);
        if (fabs(mat->data[i][i])<ZERO) return 1;
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

