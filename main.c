#include <stdio.h>
#include <stdlib.h>

int isEmpty(int *v, int first, int lenght){
  return v[first] == v[lenght];
}

void add(int *v, int value, int len){

  for(int i = 0; i < len; i++){
    if(v[i] == NULL) {
      v[i] = value;
      break;
    }
  }
}

void pop(int *v, int last){
  int temp = v[last-1];
  v[last-1] = NULL;
  printf("%d removido\n\n", temp);
}

void get(int *v, int len){
  
  for(int i = 0; i <= len; i++){
    if(v[i] == NULL){
      break;
    }
    printf("%d", v[i]);
    if(v[i+1] != NULL) 
      {
        printf(" -> ");
      }
  }
  printf("\n\n");
}


int main(){

  int size, opt, var;
  int begin = 0;
  int last = begin;

  printf("Informe a quantidade de itens: ");
  scanf("%d", &size);

  int v[size];
  //Inicializa um vetor com valores nulos
  for(int i = 0; i < size; i++){
    v[i] = NULL;
  }

  while(1){

    printf("Informe a opção desejada:\n");
    printf("1 - Incluir (add)\n");
    printf("2 - Remover (pop)\n");
    printf("3 - Exibir fila (get)\n");
    printf("4 - Sair (exit)\n");
    printf("\n\nOpção selecionada: ");
    fflush(stdin);
    scanf("%d", &opt);

    switch(opt){
      case 1:
          if(last == size){
            printf("Fila Cheia! Remova um item para adicionar um novo\n\n");
          } else{
            printf("Qual o valor a ser inserido?\n");
            printf("Valor: "); scanf("%d", &var);
            add(v, var, size);
            last++;
            printf("\n\n");
          }
          get(v, size);
        break;
      case 2:
        if(isEmpty(v, begin, size)){
          printf("A fila está vazia, não há itens a serem removidos\n\n");
        } else {
          pop(v, last);
          get(v, size);
          last--;
        }
        break;
      case 3:
        if(isEmpty(v, begin, size)){
          printf("A fila está vazia, não há itens a serem removidos\n\n");
        } else {
          printf("Valores do array: ");
          get(v, size);
        }
        break;
      case 4:
        printf("Saindo...");
        exit(0);
      default:
        printf("Opção não aceita, informe novamente\n\n");
        break;
    }
  }

}