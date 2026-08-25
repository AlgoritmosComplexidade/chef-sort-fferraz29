#include <stdio.h>
#include <string.h>

// ====================================================================
// ANÁLISE DE ALGORITMO - Desafio Chef Sort
// ====================================================================
// Este programa demonstra três algoritmos de ordenação em diferentes níveis:
// - Nível Novato: Bubble Sort (strings)
// - Nível Aventureiro: Selection Sort (structs)
// - Nível Mestre: Recursive Insertion Sort (structs)
// ====================================================================

// ====================================================================
// ESTRUTURAS DE DADOS
// ====================================================================

/**
 * Estrutura para o Nível Aventureiro
 * Representa um prato com seu nome e quantidade de ingredientes
 */
typedef struct {
    char nome[50];
    int qtd_ingredientes;
} Prato;

/**
 * Estrutura para o Nível Mestre
 * Representa uma comanda com o nome do prato e número da comanda
 */
typedef struct {
    char nome_prato[50];
    int numero_comanda;
} Comanda;

// ====================================================================
// NÍVEL NOVATO: BUBBLE SORT PARA STRINGS
// ====================================================================

/**
 * bubbleSortStrings - Ordena um array de strings usando Bubble Sort
 * 
 * @param arr: Array de strings a ser ordenado
 * @param n: Número de elementos no array
 * @param comparacoes: Ponteiro para contador de comparações
 * @param trocas: Ponteiro para contador de trocas
 * 
 * Complexidade: O(n²) no pior caso, O(n) no melhor caso
 */
void bubbleSortStrings(char arr[][50], int n, int *comparacoes, int *trocas) {
    int i, j;
    char temp[50];
    *comparacoes = 0;
    *trocas = 0;
    
    for (i = 0; i < n - 1; i++) {
        int trocou = 0;
        for (j = 0; j < n - i - 1; j++) {
            (*comparacoes)++;
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                // Troca as strings
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
                (*trocas)++;
                trocou = 1;
            }
        }
        // Se não houve troca, o array já está ordenado
        if (!trocou) break;
    }
}

// ====================================================================
// NÍVEL AVENTUREIRO: SELECTION SORT PARA STRUCTS PRATO
// ====================================================================

/**
 * selectionSortPratos - Ordena um array de Pratos usando Selection Sort
 * 
 * @param arr: Array de Pratos a ser ordenado
 * @param n: Número de elementos no array
 * 
 * Funcionamento: Encontra o menor elemento e o coloca na posição correta
 * Complexidade: O(n²) em todos os casos
 */
void selectionSortPratos(Prato arr[], int n) {
    int i, j, min_idx;
    Prato temp;
    
    // Percorre todo o array
    for (i = 0; i < n - 1; i++) {
        // Assume que o elemento atual é o menor
        min_idx = i;
        
        // Procura o menor elemento no restante do array
        for (j = i + 1; j < n; j++) {
            // Compara pela quantidade de ingredientes
            if (arr[j].qtd_ingredientes < arr[min_idx].qtd_ingredientes) {
                min_idx = j;
            }
        }
        
        // Se encontrou um elemento menor, troca com o elemento atual
        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

// ====================================================================
// NÍVEL MESTRE: RECURSIVE INSERTION SORT PARA STRUCTS COMANDA
// ====================================================================

/**
 * recursiveInsertionSort - Ordena um array de Comandas usando Insertion Sort Recursivo
 * 
 * @param arr: Array de Comandas a ser ordenado
 * @param n: Número de elementos no array
 * 
 * Funcionamento: 
 * 1. Ordena recursivamente os primeiros n-1 elementos
 * 2. Insere o último elemento na posição correta
 * 
 * Complexidade: O(n²) no pior caso, O(n) no melhor caso
 */
void recursiveInsertionSort(Comanda arr[], int n) {
    // Caso base: se n <= 1, já está ordenado
    if (n <= 1) {
        return;
    }
    
    // Ordena os primeiros n-1 elementos recursivamente
    recursiveInsertionSort(arr, n - 1);
    
    // Insere o último elemento na posição correta
    Comanda ultimo = arr[n - 1];
    int j = n - 2;
    
    // Move os elementos maiores que o último para a direita
    while (j >= 0 && arr[j].numero_comanda > ultimo.numero_comanda) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = ultimo;
}

// ====================================================================
// FUNÇÃO AUXILIAR: EXIBIR CARDÁPIO (VERSÃO CORRIGIDA)
// ====================================================================

/**
 * exibirCardapio - Exibe o cardápio com formatação alinhada
 * 
 * @param pratos: Array de Pratos
 * @param n: Número de elementos
 * @param titulo: Título a ser exibido
 * 
 * A formatação usa %-30s para alinhar à esquerda com 30 caracteres
 * Isso garante que todos os nomes fiquem alinhados independente do tamanho
 */
void exibirCardapio(Prato pratos[], int n, char titulo[]) {
    printf("\n%s\n", titulo);
    printf("%-30s %s\n", "Nome do Prato", "Qtd. Ingredientes");
    printf("%-30s %s\n", "---", "---");
    for (int i = 0; i < n; i++) {
        // %-30s alinha o nome à esquerda com 30 caracteres
        // %2d alinha o número à direita com 2 caracteres
        printf("%-30s %2d\n", pratos[i].nome, pratos[i].qtd_ingredientes);
    }
}

// ====================================================================
// FUNÇÃO PRINCIPAL
// ====================================================================

int main() {
    printf("=== BEM-VINDO AO CHEF SORT ===\n");
    printf("Sistema de Organização de Cozinha\n\n");

    // ---------------------------------------------------------
    // NÍVEL NOVATO - Despensa / Bubble Sort
    // ---------------------------------------------------------
    printf("╔══════════════════════════════════════════════════════╗\n");
    printf("║           NÍVEL NOVATO - Organizando a Despensa    ║\n");
    printf("╚══════════════════════════════════════════════════════╝\n");
    
    char ingredientes[5][50] = {"Tomate", "Cebola", "Alho", "Cenoura", "Batata"};
    int num_ingredientes = 5;
    int comparacoes = 0;
    int trocas = 0;

    printf("Lista ANTES da ordenacao:\n");
    for (int i = 0; i < num_ingredientes; i++) {
        printf("[ ] %s\n", ingredientes[i]);
    }

    // Aplica Bubble Sort
    printf("\nSISTEMA: Aplicando Bubble Sort...\n");
    bubbleSortStrings(ingredientes, num_ingredientes, &comparacoes, &trocas);

    printf("\nLista DEPOIS da ordenacao (ordem alfabetica):\n");
    for (int i = 0; i < num_ingredientes; i++) {
        printf("[ ] %s\n", ingredientes[i]);
    }
    printf("Total de comparacoes: %d\n", comparacoes);
    printf("Total de trocas: %d\n\n", trocas);

    // ---------------------------------------------------------
    // NÍVEL AVENTUREIRO - Cardápio / Selection Sort
    // ---------------------------------------------------------
    printf("╔══════════════════════════════════════════════════════╗\n");
    printf("║        NÍVEL AVENTUREIRO - Organizando o Cardápio   ║\n");
    printf("╚══════════════════════════════════════════════════════╝\n");

    // Cardápio completo com 5 pratos
    Prato cardapio[5] = {
        {"Lasanha a Bolonhesa", 12},
        {"Omelete Simples", 3},
        {"Pizza Margherita", 8},
        {"Salada Caesar", 5},
        {"Sopa de Legumes", 7}
    };
    int num_pratos = 5;
    
    printf("MISSÃO: Organizar as receitas pela quantidade de ingredientes.\n");
    
    // Exibe cardápio original
    exibirCardapio(cardapio, num_pratos, "CARDÁPIO ORIGINAL (DESORDENADO):");
    
    // Aplica Selection Sort
    printf("\nSISTEMA: Aplicando Selection Sort para otimizar a cozinha...\n");
    selectionSortPratos(cardapio, num_pratos);
    
    // Exibe cardápio organizado
    exibirCardapio(cardapio, num_pratos, "CARDÁPIO ORGANIZADO (DO MAIS SIMPLES AO MAIS COMPLEXO):");
    
    printf("\nRESULTADO: O Chef agora pode começar pelos pratos mais rápidos!\n\n");

    // ---------------------------------------------------------
    // NÍVEL MESTRE - Comandas / Recursive Insertion Sort
    // ---------------------------------------------------------
    printf("╔══════════════════════════════════════════════════════╗\n");
    printf("║         NÍVEL MESTRE - Organizando as Comandas      ║\n");
    printf("╚══════════════════════════════════════════════════════╝\n");
    
    Comanda comandas[5] = {
        {"Macarrao", 103},
        {"Salada", 101},
        {"Pizza", 105},
        {"Sopa", 102},
        {"Bife", 104}
    };
    int num_comandas = 5;
    
    printf("MISSÃO: Organizar as comandas por número de ordem.\n\n");
    printf("Comandas ANTES da ordenacao:\n");
    printf("%-20s %s\n", "Nome do Prato", "Nº Comanda");
    printf("%-20s %s\n", "---", "---");
    for (int i = 0; i < num_comandas; i++) {
        printf("%-20s #%d\n", comandas[i].nome_prato, comandas[i].numero_comanda);
    }
    
    printf("\nSISTEMA: Aplicando Recursive Insertion Sort...\n");
    recursiveInsertionSort(comandas, num_comandas);
    
    printf("\nComandas DEPOIS da ordenacao (por numero):\n");
    printf("%-20s %s\n", "Nome do Prato", "Nº Comanda");
    printf("%-20s %s\n", "---", "---");
    for (int i = 0; i < num_comandas; i++) {
        printf("%-20s #%d\n", comandas[i].nome_prato, comandas[i].numero_comanda);
    }
    
    printf("\n╔══════════════════════════════════════════════════════╗\n");
    printf("║              SISTEMA FINALIZADO COM SUCESSO         ║\n");
    printf("╚══════════════════════════════════════════════════════╝\n");

    return 0;
}