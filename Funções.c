#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nome [100];
    int lin;
    int mat;
    int cnat;
    int chum;
    float red;
    float final;
}dados;


typedef struct{
    int n, cap;
    dados* te;
}vetor;

vetor inicia(){
    vetor v;
    v.cap=1;
    v.n=0;
    v.te= malloc(sizeof(dados));
    return v;
}

void add(vetor* v, dados te){
    if(v->cap==v->n){
        v->cap*=2;
        v->te= realloc(v->te, v->cap*sizeof(dados));
    }
    v->te[v->n]=te;
    v->n++;
}

void imprime(vetor V){
    for(int i = 0; i < V.n; i++){
        dados a = V.te[i];
        printf("%d - %s: nota %.2f\n", i+1, a.nome, a.final);
    }
  puts("\n");
}

//revisar a função ordena, preciso fazer o criterio de desempate
void ordena(vetor* v){  
  for(int i = 0; i < v->n; i++){
      for(int j = 0; j < v->n-1; j++){
          if(v->te[j].final <= v->te[j+1].final){
              dados aux = v->te[j];
              v->te[j] = v->te[j+1];
              v->te[j+1] = aux;
          }
      }}}
