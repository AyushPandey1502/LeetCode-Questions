void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int index1 = m - 1;  // Initialize pointers for nums1 and nums2
    int index2 = n - 1;
    int mergedIndex = m + n - 1;  // Initialize pointer for the merged array
    
    while (index1 >= 0 && index2 >= 0) {
        // Compare the elements from the end of both arrays
        if (nums1[index1] > nums2[index2]) {
            nums1[mergedIndex] = nums1[index1];
            index1--;
        } else {
            nums1[mergedIndex] = nums2[index2];
            index2--;
        }
        mergedIndex--;
    }
    
    // If there are remaining elements in nums2, copy them to nums1
    while (index2 >= 0) {
        nums1[mergedIndex] = nums2[index2];
        index2--;
        mergedIndex--;
    }
}
