# GNU Makefile
# Revisão: ago/2019

CC = gcc
CCFLAGS = -Wall -O3 -fopenmp
LDFLAGS = -fopenmp
TARGET = main_omp gmat help

all: $(TARGET)

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

%: %.o
	$(CC) $(LDFLAGS) $^ -o $@

main_omp: main_omp.c matrizv3.o toolsv3.o matriz-operacoesv3.o matriz-operacoes-omp.o
			$(CC) $(CCFLAGS) matriz-operacoesv3.o matrizv3.o toolsv3.o matriz-operacoes-omp.o main_omp.c -o $@ $(LDFLAGS)

gmat: matrizv3.o toolsv3.o gera_matrizv3.c
		$(CC) $(CCFLAGS) matrizv3.o toolsv3.o gera_matrizv3.c -o $@ $(LDFLAGS)

help:
	@echo
	@echo
	@echo "####### Exemplo de Execução #######"
	@echo "./gmat 10 5"
	@echo "./gmat 5 10"
	@echo "./main_omp 10x5-mat.map 5x10-mat.map"

clean:
	rm -f *.o *~ $(TARGET) *.map *.result
