// Cristhinny Sarah P. Araujo
// 12/11/2020
// Counting Sort é um algoritmo de ordenação onde a ideia é não realizar comparaçoes, serao contadas quantas vezes cada número em um determinado intervalo aparece
// e depois um outro vetor é preenchido com esses valores ordenados
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

/* Funcao ordena de maneira crescente um vetor V de n elementos usando o Counting Sort
 * @param int * V = ponteiro para um vetor de inteiros
 * @param int n = quantidade de posicoes que o vetor V possui
 * return void
 */
void CountingSortIterativo(int * V, int n);


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
    CountingSortIterativo(V, n);
    printf("\nO vetor ordenado usando o metodo Counting Sort ficou da seguinte forma: ");
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

void CountingSortIterativo(int * V, int n){
    int i;
    // variavel auxiliar para modificar os valores de 'Contagem[]' ao fazer a contagem dos numeros em (1) e
    // para andar no vetor V em (2) no momento da ordenaçao
    int posicao;
    // vamos criar o vetor para contar os numeros que aparecem
    int * Contagem = NULL;
    Contagem = (int *)malloc((MAX+1)*sizeof(int));
    // se o vetor for NULL significa que nao consigos alocar memoria para ele, em seguida o programa e finalizado
    if(Contagem == NULL){
        printf("Nao foi possivel alocar memoria para o vetor de contagem. Finalizando o programa\n");
        return;
    }
    // vamos zerar o vetor de contagem para que possamos começar a ordenaçao
    for(i = 0; i < MAX + 1; i++)Contagem[i] = 0;
    // cada posiçao em 'Contagem[]' representa um valor que existe em 'V[]', cada vez que um valor aparecer em 'V[]'
    // iremos incrementar 'Contagem[V[]]' em 1
    for(i = 0; i < n; i++){
        posicao = V[i];
        Contagem[posicao] = Contagem[posicao] + 1;
    }
    // 'posicao' e uma varivel para auxiliar na análise do vetor 'V[]'
    posicao = 0;
    // agora vamos analisar cada posicao de 'Contagem[]' e ir ordenando os valores em 'V[]'
    for(i = 0; i < MAX + 1; i++){
        // se a posicao tiver sido contada entao o valor da posicao será jogada em 'V[]'
        while(Contagem[i] > 0){
            V[posicao] = i;
            // retiramos uma instancia de 'Contagem[]' assim que o mesmo foi ordenado no vetor final
            Contagem[i] = Contagem[i] - 1;
            // incrementamos a variavel que está varrendo 'V[]'
            posicao = posicao + 1;
        }
    }
    // vamos liberar a memoria alocada para o vetor 'Contagem'
    free(Contagem);
    return;
}
