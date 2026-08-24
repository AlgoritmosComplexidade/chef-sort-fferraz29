#include <stdio.h>
#include <string.h>

// ANÁLISE DE ALGORITMO - Desafio Chef Sort

// ====================================================================
// ESTRUTURAS DE DADOS (Para Níveis Aventureiro e Mestre)
// ====================================================================

// Struct para o Nível Aventureiro
typedef struct {
    char nome[50];
    int qtd_ingredientes;
} Prato;

// Struct para o Nível Mestre
typedef struct {
    char nome_prato[50];
    int numero_comanda;
} Comanda;

// ====================================================================
// PROTÓTIPOS DAS FUNÇÕES DE ORDENAÇÃO
// ====================================================================

// Nível Novato: Bubble Sort para strings
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
        if (!trocou) break;
    }
}

// Nível Aventureiro: Selection Sort para array de structs (Prato)
void selectionSortPratos(Prato arr[], int n) {
    int i, j, min_idx;
    Prato temp;
    
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].qtd_ingredientes < arr[min_idx].qtd_ingredientes) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            // Troca os pratos
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

// Nível Mestre: Recursive Insertion Sort para array de structs (Comanda)
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
// FUNÇÃO PRINCIPAL
// ====================================================================

int main() {
    printf("=== BEM-VINDO AO CHEF SORT ===\n\n");

    // ---------------------------------------------------------
    // ÁREA DO NÍVEL NOVATO (Despensa / Bubble Sort)
    // ---------------------------------------------------------
    char ingredientes[5][50] = {"Tomate", "Cebola", "Alho", "Cenoura", "Batata"};
    int num_ingredientes = 5;
    int comparacoes = 0;
    int trocas = 0;

    printf("--- Nivel Novato: Organizando a Despensa ---\n");
    printf("Lista ANTES da ordenacao:\n");
    for (int i = 0; i < num_ingredientes; i++) {
        printf("[ ] %s\n", ingredientes[i]);
    }

    // Chamada da função bubbleSortStrings
    bubbleSortStrings(ingredientes, num_ingredientes, &comparacoes, &trocas);

    printf("\nLista DEPOIS da ordenacao:\n");
    for (int i = 0; i < num_ingredientes; i++) {
        printf("[ ] %s\n", ingredientes[i]);
    }
    printf("Total de comparacoes: %d\n", comparacoes);
    printf("Total de trocas: %d\n", trocas);

    // ---------------------------------------------------------
    // ÁREA DO NÍVEL AVENTUREIRO (Pratos / Selection Sort)
    // ---------------------------------------------------------
    Prato pratos[4] = {
        {"Macarrao", 5},
        {"Salada", 3},
        {"Pizza", 8},
        {"Sopa", 2}
    };
    int num_pratos = 4;
    
    printf("\n--- Nivel Aventureiro: Organizando os Pratos ---\n");
    printf("Pratos ANTES da ordenacao (por quantidade de ingredientes):\n");
    for (int i = 0; i < num_pratos; i++) {
        printf("[ ] %s (%d ingredientes)\n", pratos[i].nome, pratos[i].qtd_ingredientes);
    }
    
    selectionSortPratos(pratos, num_pratos);
    
    printf("\nPratos DEPOIS da ordenacao (por quantidade de ingredientes):\n");
    for (int i = 0; i < num_pratos; i++) {
        printf("[ ] %s (%d ingredientes)\n", pratos[i].nome, pratos[i].qtd_ingredientes);
    }

    // ---------------------------------------------------------
    // ÁREA DO NÍVEL MESTRE (Comandas / Recursive Insertion Sort)
    // ---------------------------------------------------------
    Comanda comandas[5] = {
        {"Macarrao", 103},
        {"Salada", 101},
        {"Pizza", 105},
        {"Sopa", 102},
        {"Bife", 104}
    };
    int num_comandas = 5;
    
    printf("\n--- Nivel Mestre: Organizando as Comandas ---\n");
    printf("Comandas ANTES da ordenacao (por numero):\n");
    for (int i = 0; i < num_comandas; i++) {
        printf("[ ] %s (Comanda #%d)\n", comandas[i].nome_prato, comandas[i].numero_comanda);
    }
    
    recursiveInsertionSort(comandas, num_comandas);
    
    printf("\nComandas DEPOIS da ordenacao (por numero):\n");
    for (int i = 0; i < num_comandas; i++) {
        printf("[ ] %s (Comanda #%d)\n", comandas[i].nome_prato, comandas[i].numero_comanda);
    }

    return 0;
}
