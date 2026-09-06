#include <stdlib.h>

int* intersection(int* nums1, int nums1Size,
                  int* nums2, int nums2Size,
                  int* returnSize) {

    int* result = (int*)malloc(sizeof(int) * nums1Size);
    *returnSize = 0;

    for (int i = 0; i < nums1Size; i++) {

        // Check if nums1[i] is already added
        int alreadyPresent = 0;

        for (int k = 0; k < *returnSize; k++) {
            if (result[k] == nums1[i]) {
                alreadyPresent = 1;
                break;
            }
        }

        if (alreadyPresent)
            continue;

        // Check if nums1[i] exists in nums2
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                result[*returnSize] = nums1[i];
                (*returnSize)++;
                break;
            }
        }
    }

    return result;
}