#include <iostream>
#include <vector>
#include<iostream>
// Function to build the LPS (Longest Prefix Suffix) array
std::vector<int> computeLPS(const std::string &pattern) {
    int m = pattern.size();
    std::vector<int> lps(m, 0);
    int len = 0; // Length of previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // Go back in the LPS array
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Function to perform KMP pattern matching
void KMPsearch(const std::string &text, const std::string &pattern) {
    int n = text.size();
    int m = pattern.size();

    // Step 1: Compute LPS array
    std::vector<int> lps = computeLPS(pattern);

    int i = 0; // Pointer for text
    int j = 0; // Pointer for pattern

    while (i < n) {

        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        if (j == m) {
            std::cout << "Pattern found at index " << (i - j) << " (Character: '" << text[i - j] << "')" << std::endl;
            // Move j based on LPS
            
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1]; // Use LPS array to skip comparisons
            } else {
                i++;
            }
        }
    }
}














#if 0
// Main function
int main() {
    std::string text = "ababcabcabababd";
    std::string pattern = "ababd";
    std::cout << "Searching for pattern: " << pattern << " \nin text: " << text << std::endl;
    KMPsearch(text, pattern);
    return 0;
}
#endif
