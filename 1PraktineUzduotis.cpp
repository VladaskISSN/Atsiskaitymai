#include <iostream>
#include <iomanip> // kad leistu setprecisi
using namespace std;

int main() {

    int Pasirinkimas = 0, Valiuta;
    double Kiekis, Rezultatas;

    cout << fixed << setprecision(2); //apvalinimas 2 skaiciai po kableliu

    while (Pasirinkimas != 4) {
        cout << "\n1 - Palyginti kursa\n2 - Pirkti\n3 - Parduoti\n4 - Iseiti\n";
        cin >> Pasirinkimas;

        if (Pasirinkimas == 4) {
            break;
        }

        cout << "Pasirink valiuta (1-GBP, 2-USD, 3-INR): ";
        cin >> Valiuta;

        if (Pasirinkimas == 1) {
            if (Valiuta == 1) cout << "1 EUR = " << 0.8729 << " GBP\n";
            if (Valiuta == 2) cout << "1 EUR = " << 1.1793 << " USD\n";
            if (Valiuta == 3) cout << "1 EUR = " << 104.6918 << " INR\n";
        }

        if (Pasirinkimas == 2) {
            cout << "Ivesk kieki: ";
            cin >> Kiekis;

            if (Valiuta == 1) {
                Rezultatas = Kiekis * 0.8600;
                cout << "Gausite: " << Rezultatas << " GBP\n";
            }

            if (Valiuta == 2) {
                Rezultatas = Kiekis * 1.1460;
                cout << "Gausite: " << Rezultatas << " USD\n";
            }

            if (Valiuta == 3) {
                Rezultatas = Kiekis * 101.3862;
                cout << "Gausite: " << Rezultatas << " INR\n";
            }
        }

        if (Pasirinkimas == 3) {
            cout << "Ivesk kieki: ";
            cin >> Kiekis;

            if (Valiuta == 1) Rezultatas = Kiekis / 0.9220;
            if (Valiuta == 2) Rezultatas = Kiekis / 1.2340;
            if (Valiuta == 3) Rezultatas = Kiekis / 107.8546;

            cout << "Gausite: " << Rezultatas << " EUR\n";
        }
    }

    return 0;
}