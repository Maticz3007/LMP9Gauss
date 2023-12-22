#include "backsubst.h"
#include <math.h>
#define ZERO 0.000001
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
				int i,j;
				if (mat->c != b->r) return 2;
				for (i = mat->r-1; i >= 0; i--) {
					if (fabs(mat->data[i][i]) < ZERO) return 1;
					b->data[i][0] *= (1/mat->data[i][i]);
					mat->data[i][i] = 1.0;
					for (j = i-1; j >= 0; j--) {
						b->data[j][0] -= mat->data[j][i]*b->data[i][0];
						mat->data[j][i] = 0.0;
					}
				}
				for (i = 0; i < x->r; i++) {
					x->data[i][0] = b->data[i][0];
				}

				return 0;
}


