// Cristhinny Sarah P. Araujo
// 11/11/2020
// Insertion Sort é um algoritmo de ordenação onde a ideia é percorrer o vetor e ir inserindo os elementos na ordem correta no momento que eles vão aparecendo
// Este arquivo contém uma implementação usando loops

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Intervalo de valores inteiros indo de 0 - 500 que irão compor o vetor
#define MAX 500

/* Funcao que gera valores pseudoaleatorios para um vetor V de n posicoes usando MAX 500
 * como intervalo de valores inteiros
 * @param int * V = ponteiro para um vetor de inteiros
 * @param int n = quantidade de posicoes que o vetor V possui
 * return void
 */
void GeraVetorAleatorio(int * V, int n);

/* Funcao que mostra na tela os elementos de um vetor V de n posicoes
 * @param int * V = ponteiro para um vetor de inteiros
 * @param int n = quantidade de posicoes que o vetor V possui
 * return void
 */
void PrintaVetor(int * V, int n);

/* Funcao ordena de maneira crescente um vetor V de n elementos usando o Insertion Sort
 * @param int * V = ponteiro para um vetor de inteiros
 * @param int n = quantidade de posicoes que o vetor V possui
 * return void
 */
void InsertionSortIterativo(int * V, int n);


int main(){
    // 'n' é o tamanho do vetor
    int n;

    printf("Escolha o tamanho do vetor que voce deseja ordenar: ");
    // vamos ler do usuario o tamanho do vetor e armazenar em 'n'
    scanf("%d", &n);
    printf("\nGerando valores aleatorios para um vetor de %d posicoes...\n", n);

    // declarando o ponteiro para o vetor V
    int * V = NULL;
    // alocando espaco para um vetor V que possui 'n' inteiros
    V = (int *)malloc(sizeof(int)*n);
    
    // verificacao para ver se a alocacao deu certo. Caso nao tenha dado o programa e
    // finalizado
    if(V == NULL){
        printf("Nao foi possivel alocar memoria para esse vetor. Finalizando o programa\n");
        return 0;
    }

    // gerando valores aleatorios
    GeraVetorAleatorio(V, n);
    printf("\n\nO vetor ficou da seguinte forma: ");
    // mostrando na tela o vetor
    PrintaVetor(V, n);

    // chamando a funcao para ordenar o vetor V
    InsertionSortIterativo(V, n);
    printf("\nO vetor ordenado ficou da seguinte forma: ");
    // mostrando na tela o vetor
    PrintaVetor(V, n);

    // vamos liberar a memoria alocada para o vetor V
    free(V);
    
    return 0;
}

void GeraVetorAleatorio(int * V, int n){
    // permite que os numeros nao se repitam (pseudoaleatoriedade)
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        // vamos usar a funcao rand() para gerar valores de 0 - 500. Veja que usamos o
        // operador de resto para pegar apenas o intervalo que queremos.
        V[i] = rand() % (MAX + 1);
    }
    
    return;
}

void PrintaVetor(int * V, int n){
    printf("[ %d", V[0]);
    
    for(int i = 1; i < n; i++){
        printf(", %d", V[i]);
    }
    
    printf(" ]\n\n");

    return;
}

void InsertionSortIterativo(int * V, int n){
    // variavel para guardar a posição anterior a qual estou analisando
    int anterior;
    // variavel suporte para fazer as trocas de valores no vetor
    int a;
    // variavel para analisar as posiçoes anteriores a 'i'
    int j;

    for(int i = 1; i < n; i++){
        // vamos usar 'j' pois nao podemos modificar 'i'
        j = i;
        anterior = j - 1;
        // se 'V[j]' for menor que 'V[anterior]' e 'anterior' for maior ou igual a zero
        // trocaremos os valores de 'j' e 'anterior' de lugar
        while(V[j] < V[anterior] && anterior >= 0 ){
            a = V[anterior];
            V[anterior] = V[j];
            V[j] = a;

            // vamos analisar as posiçoes anteriores até que, se necessário, 'anterior' seja igual a 0, condição de parada do loop
            j = j - 1;
            anterior = j -1;
        }
    }
    
    return;
}
