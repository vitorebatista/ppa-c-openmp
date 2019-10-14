#include "toolsv3.h"
#include "matrizv3.h"
#include "matriz-operacoesv3.h"

int multiplicarOMP(mymatriz *mat_a, mymatriz *mat_b, mymatriz *mat_c, int tid, int ntasks);
int multiplicarOMPblocos (matriz_bloco_t *mat_suba, matriz_bloco_t *mat_subb, matriz_bloco_t *mat_subc);