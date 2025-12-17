#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);  
    
    while (t--) {
        int n;
        scanf("%d", &n);  

        int s[n], max1 = -1, max2 = -1, countMax1 = 0;

        
        for (int i = 0; i < n; i++) {
            scanf("%d", &s[i]);
            if (s[i] > max1) {
                max2 = max1;  
                max1 = s[i];   
                countMax1 = 1; 
            } else if (s[i] == max1) {
                countMax1++; 
            } else if (s[i] > max2) {
                max2 = s[i];
            }
        }

       
        for (int i = 0; i < n; i++) {
            if (s[i] == max1 && countMax1 == 1) {
                printf("%d ", s[i] - max2);  
            } else {
                printf("%d ", s[i] - max1);  
            }
        }
        printf("\n");
    }
    return 0;
}
