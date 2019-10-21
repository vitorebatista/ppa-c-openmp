# Matriz OMP

Este programa em sua execução realiza operações básicas de multiplição de estruturas matriciais de quatro diferentes maneiras: sequencial, em blocos, omp e omp em blocos. 

Estão presentes nos códigos funções para alocação de memória, geração e preenchimento de todas as posições das matrizes, liberação da memória, etc.

## Compilação

Estando dentro do diretório correto basta executar o *Makefile*.

> $ make

Após execução deste comando os códigos serão compilados e gerados os executáveis e binarios.

## Excecução

Deve-se gerar os arquivos com as matrizes para realizar os testes:

> ./gmat 1000 1000

Em seguida chamar o programa principal que realizará os devidos testes e apresentará os resultados obtidos. Haverá três parâmetros, o primeiro e segundo serão do arquivo de matriz, o terceiro (opcional) será o número de threads a serem considerados.

> ./main_omp 1000x1000-mat.map 1000x1000-mat.map 4

Será apresentado no terminal um retorno semelhante a este:

```
        
        COMPARAR MATRIZ_SeqC c/ MATRIZ_SeqBlC
        Matrizes são idênticas!! :) 

        COMPARAR MATRIZ_SeqC c/ MATRIZ_OMPC
        Matrizes são idênticas!! :) 

        COMPARAR MATRIZ_SeqC c/ MATRIZ_OMPBlC
        Matrizes são idênticas!! :) 

        Tempo Médio MATRIZ_SeqC:        0.544214 sec 
        Tempo Médio MATRIZ_SeqBlC:      2.725504 sec
        Tempo Médio MATRIZ_OMPC:        0.478042 sec 
        Tempo Médio MATRIZ_OMPBlC:      1.711702 sec 

        SPEEDUP (MATRIZ_C):     1.138 (113.84 %)
        SPEEDUP (MATRIZ_BLC):   1.592 (159.23 %)
```