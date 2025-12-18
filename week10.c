#include <stdio.h>

#define MAX 100

int ht[MAX];
int m;


void init() {
    int i;
    for (i = 0; i < m; i++)
        ht[i] = -1;
}


void insert(int key) {
    int index = key % m;

    if (ht[index] == -1) {
        ht[index] = key;
    } else {
        int i = (index + 1) % m;
        while (i != index) {
            if (ht[i] == -1) {
                ht[i] = key;
                return;
            }
            i = (i + 1) % m;
        }
        printf("Hash table is full. Cannot insert %d\n", key);
    }
}

void display() {
    int i;
    printf("\nHash Table Contents:\n");
    for (i = 0; i < m; i++) {
        if (ht[i] != -1)
            printf("Address %02d : %d\n", i, ht[i]);
        else
            printf("Address %02d : ---\n", i);
    }
}

int main() {
    int n, key, i;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    init();

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    printf("Enter %d employee keys (4-digit):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}
