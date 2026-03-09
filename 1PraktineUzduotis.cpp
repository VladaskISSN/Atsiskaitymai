#include <iostream>
#include <iomanip> // kad leistu setprecision
using namespace std;

int main() {

    int Pasirinkimas, Valiuta;
    double Kiekis, Rezultatas;

    cout << fixed << setprecision(2); //apvalinimas 2 skaiciai po kableliu

    cout << "1 - Palyginti kursa\n2 - Pirkti\n3 - Parduoti\n";
    cin >> Pasirinkimas;

    cout << "Pasirink valiuta (1-GBP, 2-USD, 3-INR): ";
    cin >> Valiuta;


    if (Pasirinkimas == 1) {
        if (Valiuta == 1) cout << "1 EUR = " << 0.8729 << " GBP";
        if (Valiuta == 2) cout << "1 EUR = " << 1.1793 << " USD";
        if (Valiuta == 3) cout << "1 EUR = " << 104.6918 << " INR";
        return 0; //kiekio nerodymas pirmam pasirinkime
    }

    cout << "Ivesk kieki: ";
    cin >> Kiekis;

    if (Pasirinkimas == 2) {
        if (Valiuta == 1) Rezultatas = Kiekis * 0.8600;
        if (Valiuta == 2) Rezultatas = Kiekis * 1.1460;
        if (Valiuta == 3) Rezultatas = Kiekis * 101.3862;

        cout << "Gausite: " << Rezultatas;
    }

    if (Pasirinkimas == 3) {
        if (Valiuta == 1) Rezultatas = Kiekis * 0.9220;
        if (Valiuta == 2) Rezultatas = Kiekis * 1.2340;
        if (Valiuta == 3) Rezultatas = Kiekis * 107.8546;

        cout << "Gausite: " << Rezultatas << " EUR";
    }

    return 0;
}