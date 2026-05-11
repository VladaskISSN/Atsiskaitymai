#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX = 20;
const double PVM = 0.21;

struct menuItemType {
    string menuItem;   // patiekalo pavadinimas
    double menuPrice;  // patiekalo kaina
};

void getData(menuItemType menuList[], int& size) {
    ifstream file("menu.txt");

    size = 0;

    while (getline(file, menuList[size].menuItem, ';')) {
        file >> menuList[size].menuPrice;
        file.ignore();

        size++;
    }

    file.close();
}

void showMenu(menuItemType menuList[], int size) {
    cout << fixed << setprecision(2);

    cout << "Pusryciu meniu:\n\n";

    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". "
             << menuList[i].menuItem << " - "
             << menuList[i].menuPrice << " EUR" << endl;
    }

    cout << "\nPasirinkite patiekalo numeri. Jei norite baigti, iveskite 0.\n";
}

void printCheck(menuItemType menuList[], int kiekiai[], int size) {
    ofstream receipt("receipt.txt");

    double suma = 0;

    cout << fixed << setprecision(2);
    receipt << fixed << setprecision(2);

    cout << "\nSveiki atvyke i restorana \"Pavadinimas\"\n\n";
    receipt << "Sveiki atvyke i restorana \"Pavadinimas\"\n\n";

    for (int i = 0; i < size; i++) {
        if (kiekiai[i] > 0) {
            double eilutesSuma = kiekiai[i] * menuList[i].menuPrice;
            suma += eilutesSuma;

            cout << kiekiai[i] << " "
                 << menuList[i].menuItem << " "
                 << eilutesSuma << " EUR" << endl;

            receipt << kiekiai[i] << " "
                    << menuList[i].menuItem << " "
                    << eilutesSuma << " EUR" << endl;
        }
    }

    double mokestis = suma * PVM;
    double galutineSuma = suma + mokestis;

    cout << "\nMokesciai (21%) " << mokestis << " EUR" << endl;
    cout << "Galutine suma " << galutineSuma << " EUR" << endl;

    receipt << "\nMokesciai (21%) " << mokestis << " EUR" << endl;
    receipt << "Galutine suma " << galutineSuma << " EUR" << endl;

    receipt.close();
}

int main() {
    menuItemType menuList[MAX];
    int kiekiai[MAX] = {0};
    int size;

    getData(menuList, size);
    showMenu(menuList, size);

    int pasirinkimas;
    int kiekis;

    while (true) {
        cout << "\nPatiekalo numeris: ";
        cin >> pasirinkimas;

        if (pasirinkimas == 0) {
            break;
        }

        cout << "Kiek porciju: ";
        cin >> kiekis;

        kiekiai[pasirinkimas - 1] += kiekis;
    }

    printCheck(menuList, kiekiai, size);

    return 0;
}