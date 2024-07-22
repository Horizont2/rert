#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cctype>

using namespace std;

// Порахуйте кількість входжень слова, заданого користувачем
int countWordOccurrences(const string &text, const string &word) {
    int count = 0;
    size_t pos = text.find(word);
    while (pos != string::npos) {
        count++;
        pos = text.find(word, pos + word.length());
    }
    return count;
}

// Порахуйте кількість речень у тексті
int countSentences(const string &text) {
    int count = 0;
    for (char ch : text) {
        if (ch == '.' || ch == '!' || ch == '?') {
            count++;
        }
    }
    return count;
}

// Порахуйте кількість крапок і ком
int countDotsAndCommas(const string &text) {
    int count = 0;
    for (char ch : text) {
        if (ch == '.' || ch == ',') {
            count++;
        }
    }
    return count;
}

// Переверніть повністю весь текст
string reverseText(const string &text) {
    string reversed = text;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

// Переверніть кожне речення в тексті
string reverseSentences(const string &text) {
    stringstream ss(text);
    string sentence, result;
    vector<string> sentences;

    while (getline(ss, sentence, '.')) {
        if (!sentence.empty() && sentence.back() == '\n') {
            sentence.pop_back();
        }
        if (!sentence.empty()) {
            sentences.push_back(sentence + ".");
        }
    }

    for (auto &s : sentences) {
        reverse(s.begin(), s.end());
    }

    for (const auto &s : sentences) {
        result += s + " ";
    }

    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;
}

int main() {
    string text;
    string word;

    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter word to count: ";
    getline(cin, word);

    // Порахуйте кількість входжень слова, заданого користувачем
    int wordCount = countWordOccurrences(text, word);
    cout << "Occurrences of word '" << word << "': " << wordCount << endl;

    // Порахуйте кількість речень у тексті
    int sentenceCount = countSentences(text);
    cout << "Number of sentences: " << sentenceCount << endl;

    // Порахуйте кількість крапок і ком
    int dotCommaCount = countDotsAndCommas(text);
    cout << "Number of dots and commas: " << dotCommaCount << endl;

    // Переверніть повністю весь текст
    string reversedText = reverseText(text);
    cout << "Reversed text: " << reversedText << endl;

    // Переверніть кожне речення в тексті
    string reversedSentencesText = reverseSentences(text);
    cout << "Reversed sentences: " << reversedSentencesText << endl;

    return 0;
}
