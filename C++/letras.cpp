#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>

bool isVowel(char c) {
    c = std::tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool followsAnaRules(const std::string& word) {
    int len = word.length();
    if (len == 1) {
        return true;
    } else if (len <= 5) {
        return !isVowel(word[0]) && isVowel(word[len - 1]);
    } else {
        return isVowel(word[0]) && isVowel(word[len - 1]);
    }
}

bool checkParagraph(const std::string& paragraph) {
    std::istringstream stream(paragraph);
    std::string word;
    while (stream >> word) {
        if (!followsAnaRules(word)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(); // Ignorar o \n após o número de casos de teste

    std::vector<std::string> results;

    for (int i = 0; i < n; ++i) {
        std::string paragraph;
        std::getline(std::cin, paragraph);
        if (checkParagraph(paragraph)) {
            results.push_back("SIM");
        } else {
            results.push_back("NAO");
        }
    }

    for (const auto& result : results) {
        std::cout << result << std::endl;
    }

    return 0;
}
