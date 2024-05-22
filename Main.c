#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[100];
  int lin;
  int mat;
  int cnat;
  int chum;
  float red;
  float final;
} dados;

typedef struct {
  int n, cap;
  dados *te;
} vetor;

vetor inicia() {
  vetor v;
  v.cap = 1;
  v.n = 0;
  v.te = malloc(sizeof(dados));
  return v;
}

void add(vetor *v, dados te) {
  if (v->cap == v->n) {
    v->cap *= 2;
    v->te = realloc(v->te, v->cap * sizeof(dados));
  }
  v->te[v->n] = te;
  v->n++;
}

void imprime(vetor V) {
  for (int i = 0; i < V.n; i++) {
    dados a = V.te[i];
    printf("%d - %s: nota %.2f\n", i + 1, a.nome, a.final);
  }
  puts("\n");
}

// revisar a função ordena, preciso fazer o criterio de desempate
void ordena(vetor *v) {
  for (int i = 0; i < v->n; i++) {
    for (int j = 0; j < v->n - 1; j++) {
      if (v->te[j].final <= v->te[j + 1].final) {
        dados aux = v->te[j];
        v->te[j] = v->te[j + 1];
        v->te[j + 1] = aux;
      }
    }
  }
}

int main() {

  float pesol, pesom, pesoh, pesoc, pesor;
  dados te;
  vetor v = inicia();
  vetor co1 = inicia();
  vetor co2 = inicia();
  vetor co3 = inicia();
  vetor co4 = inicia();
  vetor co5 = inicia();
  vetor co6 = inicia();
  vetor co7 = inicia();
  vetor co8 = inicia();
  char continua[3] = "sim";
  char res[3] = "sim";
  int cota;

  printf("Bem vindo a programa que calcula a sua nota da prova");
  printf("\n\n");

  printf("Adicione o peso de cada area\n");
  printf("Linguagens: ");
  scanf("%g", &pesol);
  printf("Matematica: ");
  scanf("%g", &pesom);
  printf("Ciencias da Natureza: ");
  scanf("%g", &pesoc);
  printf("Ciencias humanas: ");
  scanf("%g", &pesoh);
  printf("Redação: ");
  scanf("%g", &pesor);

  while (strcmp(continua, "sim") == 0 || strcmp(continua, "Sim") == 0 || strcmp(continua, "SIM") == 0 || strcmp(continua, "s") == 0 || strcmp(continua, "S") == 0) {

    printf("Digite seu nome : ");
    fflush(stdin);
    scanf(" %[^\n]s", te.nome);

    printf("\n\nVocê concorre a algum tipo de vaga reservada a cotas? \n");
    scanf("%s", res);

    if (strcmp(res, "sim") == 0 || strcmp(res, "Sim") == 0 ||
        strcmp(res, "SIM") == 0 || strcmp(res, "s") == 0 ||
        strcmp(res, "S") == 0) {

printf("\n\nDas seguintes opções, qual você se enquadra: \n"
"1 -Estudante de escola pública\n"
"2 - Estudante de escola pública e baixa renda \n"
"3 - Estudante de escola pública e negro/indigena\n"
"4 - Estudante de escola pública e PCD \n"
"5 - Estudante de escola pública, negro/indigena e baixa renda \n"
"6 - Estudante de escola pública, PCD, negro/indigena e baixa renda \n"
"7 - Estudante de escola pública, PCD, baixa renda\n"
"8 - Estudante de escola pública, PCD, negro/indigena\n ");

      scanf("%d", &cota);
    }

    printf("\nDigite quantos pontos foi feito na parte de Linguagens: ");
    scanf(" %d", &te.lin);
    
    printf("Digite quantos pontos foi feito na parte de Matematica: ");
    scanf(" %d", &te.mat);
   
    printf("Digite quantos pontos foi feito na parte de Ciencias da Natureza: ");
    scanf(" %d", &te.cnat);
    
    printf("Digite quantos pontos foi feito na parte de Ciencias humanas: ");
    scanf(" %d", &te.chum);
    
    printf("Digite quantos pontos foi feito na parte de Redação: ");
    scanf(" %g", &te.red);

    te.final = (te.mat * pesom) + (te.lin * pesol) + (te.red * pesor) + (te.cnat * pesoc) + (te.chum * pesoh);

    printf("\n%s, sua nota final foi: %g\n\n", te.nome, te.final);
    add(&v, te);

    if (cota == 1) {
      add(&co1, te);
    }
    if (cota == 2) {
      add(&co2, te);
    }
    if (cota == 3) {
      add(&co3, te);
    }
    if (cota == 4) {
      add(&co4, te);
    }
    if (cota == 5) {
      add(&co5, te);
    }
    if (cota == 6) {
      add(&co6, te);
    }
    if (cota == 7) {
      add(&co7, te);
    }
    if (cota == 8) {
      add(&co8, te);
    }

    cota = 0;

    printf("\n\nDeseja continuar adicionando um participante? \n");
    scanf("%s", continua);
  }

  if (v.n > 0) {
    ordena(&v);
    puts("Candidatos na ampla concorrencia: ");
    imprime(v);
  }

  if (co1.n > 0) {
    ordena(&co1);
    puts("Candidatos na cota de Estudante de escola pública: ");
    imprime(co1);
  }
  if (co2.n > 0) {
    ordena(&co2);
    puts("Candidatos na cota Estudante de escola pública e baixa renda: ");
    imprime(co2);
  }
  if (co3.n > 0) {
    ordena(&co3);
    puts("Candidatos na cota de Estudante de escola pública e negro/indigena:");
    imprime(co3);
  }
  if (co4.n > 0) {
    ordena(&co4);
    puts("Candidatos na cota de Estudante de escola pública e PCD: ");
    imprime(co4);
  }
  if (co5.n > 0) {
    ordena(&co5);
    puts("Candidatos na cota de Estudante de escola pública, negro/indigena e "
         "baixa renda: ");
    imprime(co5);
  }
  if (co6.n > 0) {
    ordena(&co6);
    puts("Candidatos na cota de Estudante de escola pública, PCD, "
         "negro/indigena e baixa renda : ");
    imprime(co6);
  }
  if (co7.n > 0) {
    ordena(&co7);
    puts("Candidatos na cota de Estudante de escola pública, PCD, baixa "
         "renda: ");
    imprime(co7);
  }
  if (co8.n > 0) {
    ordena(&co8);
    puts("Candidatos na cota de Estudante de escola pública, PCD, "
         "negro/indigena: ");
    imprime(co8);
  }

  puts("\nFim do programa, obrigado por utiizar");
}
