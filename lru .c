#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 37

void main() {
    int fframe[MAX_FRAMES], used[MAX_FRAMES], index;
    int count, n1, nf, np = 0, page[MAX_PAGES], tmp;
    int flag, pf = 0;

    printf("Enter number of frames: ");
    scanf("%d", &nf);

    // Initialize frame array
    for (count = 0; count < nf; count++) {
        fframe[count] = -1; // -1 indicates an empty frame
    }

    printf("LRU Page Replacement Algorithm in C\n");
    printf("Enter pages (press -999 to exit):\n");

    // Input pages
    for (count = 0; count < MAX_PAGES; count++) {
        scanf("%d", &tmp);
        if (tmp == -999) break;
        page[count] = tmp;
        np++;
    }

    // Process each page
    for (count = 0; count < np; count++) {
        flag = 0;

        // Check if the page is already in one of the frames
        for (n1 = 0; n1 < nf; n1++) {
            if (fframe[n1] == page[count]) {
                flag = 1; // Page hit
                break;
            }
        }

        // If the page is not found in the frames, we need to replace a page
        if (!flag) {
            // Initialize used array to track which frames are still in use
            for (n1 = 0; n1 < nf; n1++) {
                used[n1] = 0;
            }

            // Mark pages that are still in use
            for (n1 = count - 1; n1 >= 0 && n1 >= count - nf; n1--) {
                for (int k = 0; k < nf; k++) {
                    if (fframe[k] == page[n1]) {
                        used[k] = 1; // Mark as used
                    }
                }
            }

            // Find an empty frame or a victim to replace
            index = -1;
            for (n1 = 0; n1 < nf; n1++) {
                if (!used[n1]) { // If the frame is empty
                    index = n1;
                    break;
                }
            }

            // If all frames are used, replace the least recently used one
            if (index == -1) {
                for (n1 = 0; n1 < nf; n1++) {
                    if (!used[n1]) { // Find the first unused frame
                        index = n1;
                        break;
                    }
                }
            }

            fframe[index] = page[count]; // Replace the page
            printf("\nPage Fault: %d", page[count]);
            pf++; // Increment page fault counter
        }

        // Display current frames
        printf("\nCurrent Frames: ");
        for (int k = 0; k < nf; k++) {
            printf("%d\t", fframe[k]);
        }
    }

    printf("\nTotal number of page faults: %d\n", pf);
    
}