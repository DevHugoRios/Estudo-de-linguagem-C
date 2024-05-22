// Criar um programa que declara uma matriz 10x10 de int, uma função para
// inicializar a matriz com zeros usando ponteiros e outra função para preencher
// a matriz com numeros de 99 a 0, usando um ponteiro para a matriz como
// parametro e imprimir a matriz

#include <stdio.h>
#include <stdlib.h>

void inicializarMatriz(int (*matriz)[10][10], int *x, int *y) {

  int linha = *x;
  int coluna = *y;

  for (linha = 0; linha < 10; linha++) {
    for (coluna = 0; coluna < 10; coluna++) {
      (*matriz)[linha][coluna] = 0;
    }
  }
}

void preencherMatriz(int (*matriz)[10][10], int *x, int *y) {
  int linha = *x, coluna = *y;
  int cont = 99;

  for (linha = 0; linha < 10; linha++) {
    for (coluna = 0; coluna < 10; coluna++) {
      (*matriz)[linha][coluna] = cont;
      cont -= 1;
    }
  }
}

int main(void) {

  int matriz[10][10];
  int x = 10, y = 10;

  inicializarMatriz(&matriz, &x, &y);
  printf("Inicializada:\n");
  for (x = 0; x < 10; x++) {
    for (y = 0; y < 10; y++) {
      printf(" %d", matriz[x][y]);
    }
    printf("\n");
  }

  printf("\n");

  preencherMatriz(&matriz, &x, &y);
  printf("Preenchida:\n");
  for (x = 0; x < 10; x++) {
    for (y = 0; y < 10; y++) {
      printf(" %d", matriz[x][y]);
    }
    printf("\n");
  }

  return 0;
}