#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Знайти і замінити входження певного слова на задане користувачем слово
void replaceWord(char *text, const char *oldWord, const char *newWord) {
    char buffer[1000];
    char *pos, *temp = text;
    int oldLen = strlen(oldWord);
    int newLen = strlen(newWord);

    while ((pos = strstr(temp, oldWord)) != NULL) {
        strncpy(buffer, text, pos - text);
        buffer[pos - text] = '\0';
        strcat(buffer, newWord);
        strcat(buffer, pos + oldLen);
        strcpy(text, buffer);
        temp = pos + newLen;
    }
}

// Змінити текст таким чином, щоб кожне речення починалося з великої літери
void capitalizeSentences(char *text) {
    int capitalize = 1;
    while (*text) {
        if (capitalize && isalpha(*text)) {
            *text = toupper(*text);
            capitalize = 0;
        }
        if (*text == '.' || *text == '!' || *text == '?') {
            capitalize = 1;
        }
        text++;
    }
}

// Порахуйте скільки разів кожна буква зустрічається в тексті
void countLetters(const char *text) {
    int counts[26] = {0};
    while (*text) {
        if (isalpha(*text)) {
            counts[tolower(*text) - 'a']++;
        }
        text++;
    }
    for (int i = 0; i < 26; i++) {
        if (counts[i] > 0) {
            printf("%c: %d\n", 'a' + i, counts[i]);
        }
    }
}

// Порахуйте скільки разів цифри зустрічаються в тексті
void countDigits(const char *text) {
    int counts[10] = {0};
    while (*text) {
        if (isdigit(*text)) {
            counts[*text - '0']++;
        }
        text++;
    }
    for (int i = 0; i < 10; i++) {
        if (counts[i] > 0) {
            printf("%d: %d\n", i, counts[i]);
        }
    }
}

int main() {
    char text[1000] = "Hello world! This is a test. 1234. Hello again, world!";
    char wordToReplace[100] = "world";
    char newWord[100] = "universe";

    //завдання 1
    replaceWord(text, wordToReplace, newWord);
    printf("Modified text: %s\n", text);

    //завдання 2
    capitalizeSentences(text);
    printf("Capitalized text: %s\n", text);

    //завдання 3
    printf("Letter counts:\n");
    countLetters(text);

    //завдання 4
    printf("Digit counts:\n");
    countDigits(text);

    return 0;
}
