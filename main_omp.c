#include "matriz-operacoes-omp.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int main(int argc, char *argv[]) {



// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%

	// DECLARAÇÃO de VARIÁVEIS

  (....)

// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	if (argc != 3){

		printf ("ERRO: Numero de parametros %s <matriz_a> <matriz_b>\n", argv[0]);

		exit (1);

	}

 // %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%

        LER MATRIZ_A

	LER MATRIZ_B

       CRIAR MATRIZ_C

// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%



// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%

// Multiplicação Sequencial

 LOOP (10x)

	MARCAR_TEMPO INICIO

	MATRIZ_SeqC = MULTIPLICAR MATRIZ_A x MATRIZ_B

	MARCAR_TEMPO FIM

	GRAVAR_DISCO MATRIZ_SeqC

// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%



// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%

// Multiplicação Sequencial em Bloco

	DEFINIR N (numero de pedacos entre 2 e 20)

 LOOP (10x)

	MARCAR_TEMPO INICIO

	PARTICIONAR_MATRIZ em N pedacos

	MATRIZ_SeqBlC = MULTIPLICARBLOCOS MATRIZ_A x MATRIZ_B

	MARCAR_TEMPO FIM

	GRAVAR_DISCO MATRIZ_SeqBlC

// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%



// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%

// Multiplicação OMP

 LOOP (10x)

        MARCAR_TEMPO INICIO

	MATRIZ_OMPC = MULTIPLICAROMP MATRIZ_A x MATRIZ_B

	MARCAR_TEMPO FIM

	GRAVAR_DISCO MATRIZ_OMPC

// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%



// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%

// Multiplicação OMP em Bloco

	N = mesmo nro de blocos da Sequencial

 LOOP (10x)

	MARCAR_TEMPO INICIO

	PARTICIONAR_MATRIZ em N pedacos

	MATRIZ_OMPBlC = MULTIPLICARBLOCOSOMP MATRIZ_A x MATRIZ_B

	MARCAR_TEMPO FIM

	GRAVAR_DISCO MATRIZ_OMPBlC

// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

// Comparar resultados e tempos

        (print) COMPARAR MATRIZ_SeqC c/ MATRIZ_SeqBlC

        (print) COMPARAR MATRIZ_SeqC c/ MATRIZ_OMPC

	(print) COMPARAR MATRIZ_SeqC c/ MATRIZ_OMPBlC

	(print) TEMPO_MEDIO MATRIZ_SeqC 

	(print) TEMPO_MEDIO MATRIZ_SeqBlC

	(print) TEMPO_MEDIO MATRIZ_OMPC

	(print) TEMPO_MEDIO MATRIZ_OMPBlC

        (print) SPEEDUP (MATRIZ_C)

        (print) SPEEDUP (MATRIZ_BLC)

  // %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%

// LIBERAR MEMÓRIA

	LIBERAR MATRIZES

	FECHAR ARQUIVOS

// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	return 0;


}