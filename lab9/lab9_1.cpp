#include <cstdio>  
#include <cstdlib> 


int simulateGame(int n, int* a, int k) {
    int* players = (int*)malloc((n + 1) * sizeof(int));  
    if (!players) return -1;  

    
    for (int i = 1; i <= n; i++) players[i] = 1;

    
    bool removed = true;
    while (removed) {
        removed = false;
        for (int i = 0; i < k; i++) {
            if (a[i] <= n && players[a[i]] == 1) {
                players[a[i]] = 0;  
                removed = true;
            }
        }
    }

    
    int winners = 0;
    for (int i = 1; i <= n; i++) {
        if (players[i] == 1) winners++;
    }

    free(players);  
    return winners;
}

int main() {
    int t;
    printf("Enter the number of test cases: ");
    scanf("%d", &t);  

    while (t--) {
        int k, q;
        printf("\nEnter the number of elimination positions (k) and number of queries (q): ");
        scanf("%d %d", &k, &q);  

        
        int* a = (int*)malloc(k * sizeof(int));  
        int* n = (int*)malloc(q * sizeof(int));  

        if (!a || !n) {
            printf("Memory allocation failed!\n");
            return -1;
        }

        
        printf("Enter %d elimination positions: ", k);
        for (int i = 0; i < k; i++) scanf("%d", &a[i]);

        printf("Enter %d different values for the initial number of players: ", q);
        for (int i = 0; i < q; i++) scanf("%d", &n[i]);

       
        printf("Winners for each query: ");
        for (int i = 0; i < q; i++) {
            printf("%d ", simulateGame(n[i], a, k));
        }
        printf("\n");  

        
        free(a);
        free(n);   
    }
    
    return 0;
}



