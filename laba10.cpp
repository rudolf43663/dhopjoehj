#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string file, surname, name, patronymic;
    int items, totalItems = 0, heaviestIndex = -1;
    double weight, totalWeight = 0, heaviestWeight = 0, threshold;

    cout << "VVedite imya faila: ";
    cin >> file;
    ifstream f(file);
    if (!f) {
        cout << "Nevozmojno otkrit fail! \n";
        return -1;
    }

    cout << "Vvedite predel vesa bagaja: ";
    cin >> threshold;

    cout << "Passajiri previshayushie " << threshold << " kg:\n";
    int index = 0;
    while (getline(f, surname) && getline(f, name) && getline(f, patronymic) && f >> items >> weight) {
        f.ignore();
        totalWeight += weight;
        if (weight > threshold) {
            cout << surname << " " << name << " " << patronymic << ", Veshi: " << items << ", Ves: " << weight << " kg\n";
            totalItems += items;
        }
        if (weight > heaviestWeight) {
            heaviestWeight = weight;
            heaviestIndex = index;
        }
        ++index;
    }

    cout << "\nKol-vo predmetov: " << totalItems << "\nVes predmetov: " << totalWeight << " kg\n";
    if (heaviestIndex != -1) {
        cout << "Tyajeleishiy bagaj: " << heaviestWeight << " kg\n";
    }
    return 0;
}
