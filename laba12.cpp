#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    ifstream file("text.txt");
    if (!file) {
        cout << "Ошибка при открытии файла!" << endl;
        return 1;
    }

    int letterFrequency[26] = {0};
    int pairFrequency[26][26] = {0};
    char prevChar = '\0';
    char currentChar;

    while (file.get(currentChar)) {
        if (isalpha(currentChar)) {
            currentChar = tolower(currentChar);
            letterFrequency[currentChar - 'a']++;

            if (prevChar != '\0') {
                pairFrequency[prevChar - 'a'][currentChar - 'a']++;
            }

            prevChar = currentChar;
        }
    }

    cout << "Частота букв:" << endl;
    for (int i = 0; i < 26; i++) {
        if (letterFrequency[i] > 0) {
            cout << (char)(i + 'a') << ": " << letterFrequency[i] << endl;
        }
    }

    cout << "Частота двухбуквенных сочетаний:" << endl;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (pairFrequency[i][j] > 0) {
                cout << (char)(i + 'a') << (char)(j + 'a') << ": " << pairFrequency[i][j] << endl;
            }
        }
    }

    file.close();
    return 0;
}
