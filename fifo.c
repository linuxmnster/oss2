#include<stdio.h>

int main() {
    int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n;

    printf("\n Enter the length of reference string -- ");
    scanf("%d", &n);
    printf("\n Enter the reference string -- ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }
    printf("\n Enter no. of frames -- ");
    scanf("%d", &f);
    for (i = 0; i < f; i++) {
        m[i] = -1;
    }
    printf("\n The Page Replacement Process is -- \n");
    for (i = 0; i < n; i++) {
        for (k = 0; k < f; k++) {
            if (m[k] == rs[i]) {
                break;
            }
        }
        if (k == f) {
            m[count++] = rs[i];
            pf++;
            if (count == f) {
                count = 0;
            }
        }
        for (j = 0; j < f; j++) {
            printf("%d\t", m[j]);
        }
        printf("\n");
    }
    printf("\n The number of page faults is %d", pf);

}