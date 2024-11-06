#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 37

void main() {
    int fframe[MAX_FRAMES], used[MAX_FRAMES];
    int nf, np = 0, page[MAX_PAGES], tmp;
    int pf = 0; // Page fault counter

    printf("Enter number of frames: ");
    scanf("%d", &nf);

    // Initialize frames
    for (int i = 0; i < nf; i++) {
        fframe[i] = -1; // -1 indicates an empty frame
    }

    printf("Enter pages (press -999 to exit):\n");

    // Input pages
    while (np < MAX_PAGES) {
        scanf("%d", &tmp);
        if (tmp == -999) break;
        page[np++] = tmp;
    }

    // Process each page
    for (int i = 0; i < np; i++) {
        int flag = 0;

        // Check for page hit
        for (int j = 0; j < nf; j++) {
            if (fframe[j] == page[i]) {
                flag = 1; // Page hit
                break;
            }
        }

        // Page fault if no hit
        if (!flag) {
            // Find the least recently used frame
            int lru_index = 0;
            for (int j = 0; j < nf; j++) {
                used[j] = -1;
                for (int k = i - 1; k >= 0; k--) {
                    if (fframe[j] == page[k]) {
                        used[j] = k;
                        break;
                    }
                }
                if (used[j] < used[lru_index]) lru_index = j;
            }

            // Replace the page
            fframe[lru_index] = page[i];
            pf++; // Increment page fault counter
            printf("\nPage Fault: %d", page[i]);
        }

        // Display current frames
        printf("\nCurrent Frames: ");
        for (int j = 0; j < nf; j++) {
            printf("%d\t", fframe[j]);
        }
    }

    printf("\nTotal number of page faults: %d\n", pf);
}
