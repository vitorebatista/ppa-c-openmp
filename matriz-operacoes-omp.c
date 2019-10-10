#include <omp.h>
#include "matrizv3.h"
#include "matriz-operacoesv3.h"

int multiplicarOMP(mymatriz *mat_a, mymatriz *mat_b, mymatriz *mat_c, int n_threads)
{

    // Inicia paralelismo

    //inicializa variáveis de controle dos for`s
    int i_max = mat_a->lin;
    int j_max = mat_b->col;
    int k_max = mat_a->col;

//#pragma omp parallel shared(mat_a, mat_b, mat_c) \
    //num_threads(n_threads)
/*
#pragma omp for schedule(static)
    for (int i = tid; i < i_max; i += n_threads)
    {
        //printf("\nfor tid\n");
        for (int k = 0; k < k_max; k++)
        {
            for (int j = 0; j < j_max; j++)
            {
                //printf("\nfor k\n");
                //mat_c->matriz[i][j] += mat_a->matriz[i][k] * mat_b->matriz[k][j];
                printf("mat_c->matriz[%d][%d] = %d, calculado por thread %d\n", i, j, mat_c->matriz[i][j], tid);
            }
        }
    }*/

    #pragma omp parallel for schedule(guided) private(i,j,k) shared(mat_a,mat_b,mat_c)
	for(int i = 0; i < i_max; i++){
		for(int j = 0; j < j_max; j++){
			mat_c->matriz[i][j] = 0;
			for(int k = 0; k < k_max; k++){
				mat_c->matriz[i][j] += mat_a->matriz[i][k] * mat_b->matriz[k][j];
                int tid = omp_get_thread_num();
                printf("mat_c->matriz[%d][%d] = %d, calculado por thread %d\n", i, j, mat_c->matriz[i][j], tid);
			}
        }
    }

    return 0;
}

int multiplicarOMPblocos(matriz_bloco_t *mat_suba, matriz_bloco_t *mat_subb, matriz_bloco_t *mat_subc)
{
    multiplicar_submatriz(mat_suba, mat_subb, mat_subc);
    return 0;
}