#include <iostream>
#include <vector>
#include <string>

const int P = 31;
const int M = 1e9 + 9;

// Compute hash of a string
long long computeHash(const std::string &s) {
    long long hash = 0;
    long long power = 1;
    for (char c : s) {
        hash = (hash + (c - 'a' + 1) * power) % M;
        power = (power * P) % M;
    }
    return hash;
}

// Rabin-Karp: Find all occurrences of pattern in text
std::vector<int> rabinKarpSearch(const std::string &text, const std::string &pattern) {
    int n = text.size(), m = pattern.size();
    long long patternHash = computeHash(pattern);
    long long textHash = computeHash(text.substr(0, m));
    std::vector<int> positions;

    long long power = 1;  // Compute P^(m-1) % M
    for (int i = 0; i < m - 1; i++) 
        power = (power * P) % M;

    for (int i = 0; i <= n - m; i++) {
        if (textHash == patternHash) {
            if (text.substr(i, m) == pattern)
                positions.push_back(i);
        }

        if (i < n - m) {
            textHash = (textHash - (text[i] - 'a' + 1) * power) % M;
            textHash = (textHash * P + (text[i + m] - 'a' + 1)) % M;
            if (textHash < 0) textHash += M; // Ensure positive value
        }
    }

    return positions;
}

#if 0
int main() {
    std::string text = "ababcabcabababd";
    std::string pattern = "abab";

    std::vector<int> occurrences = rabinKarpSearch(text, pattern);
    
    std::cout << "Pattern found at indices: ";
    for (int pos : occurrences) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;

    return 0;
}
#endif
