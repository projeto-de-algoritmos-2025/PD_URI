#include <stdio.h>
#include <stdlib.h> 

// Função para calcular o número mínimo de trocas.
int calculate_min_swaps(int N, int L, int* available_lockers) {
    if (N == 0) {
        return 0;
    }

    if (L == 0) {
        return N;
    }

    int max_overlap = 0; 
    int left = 0;        


    for (int right = 0; right < L; ++right) {
        while (available_lockers[left] < available_lockers[right] - N + 1) {
            left++;
        }

        if (right - left + 1 > max_overlap) {
            max_overlap = right - left + 1;
        }
    }

    return N - max_overlap;
}

int main() {
    int N, L; 


    while (scanf("%d %d", &N, &L) == 2 && (N != 0 || L != 0)) {
        int *available_lockers = (int *)malloc(L * sizeof(int));
        if (available_lockers == NULL) {
            fprintf(stderr, "Erro na alocação de memória.\n");
            return 1;
        }

        // Lê as posições dos armários disponíveis.
        for (int i = 0; i < L; ++i) {
            scanf("%d", &available_lockers[i]);
        }

        // Chama a função para calcular o número mínimo de trocas.
        int min_swaps = calculate_min_swaps(N, L, available_lockers);

        printf("%d\n", min_swaps);
        free(available_lockers);
    }

    return 0;
}