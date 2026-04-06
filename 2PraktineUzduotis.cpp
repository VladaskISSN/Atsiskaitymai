#include <iostream>
#include <string>
using namespace std;

const int DidziausiasgGalimasMokiniuskaicius = 100;
const int DidziausiasGalimasPazymiuSkaicius = 10;
string Vardai[DidziausiasgGalimasMokiniuskaicius];
int Pazymiai[DidziausiasgGalimasMokiniuskaicius][DidziausiasGalimasPazymiuSkaicius];
int KiekPazymiu[DidziausiasgGalimasMokiniuskaicius];
int KiekMokiniu = 0;

int main() {
    int pasirinkimas;
do {
    cout << "Mokiniu pazymiu sistema\n";
    cout << "1 - Ivesti mokini\n";
    cout << "2 - Parodyti mokiniu sarasa\n";
    cout << "3 - Pakeisti mokinio pazymi\n";
    cout << "4 - Istrinti mokini is saraso\n";
    cout << "5 - Uzdaryti programa\n";
    cout << "pasirink";
    cin >> pasirinkimas;

    if (pasirinkimas == 1) {
        if (KiekMokiniu < DidziausiasgGalimasMokiniuskaicius) {
            cout << "Ivesk mokinio varda:";
            cin >> Vardai[KiekMokiniu];
            cout << "Kiek pazymiu nori ivesti?";
            cin >> KiekPazymiu[KiekMokiniu];
            if (KiekPazymiu[KiekMokiniu] > DidziausiasGalimasPazymiuSkaicius ) {
                cout <<"Ivedei per daug pazymiu, bus ivesta tik " <<DidziausiasGalimasPazymiuSkaicius << ".\n";
                KiekPazymiu[KiekMokiniu] = DidziausiasGalimasPazymiuSkaicius;
            } for (int i= 0; i <KiekPazymiu[KiekMokiniu]; i++) {
                cout << "Ivesk" << i + 1 << "pazymi: ";
                cin >> Pazymiai[KiekMokiniu][i];
            }
            KiekMokiniu++;
            cout << "Mokinys pridetas. \n";
        }else {
            cout << "Daugiau mokiniu prideti negalima\n";
        }
        if (pasirinkimas == 2) {
            if (KiekMokiniu == 0) {
                cout << "Mokiniu sarasas tuscias. \n";
            } else {
                cout << "Mokiniu sarasas: \n";
                for (int i= 0; i <KiekMokiniu; i++) {
                    cout << i + 1 << " " << Vardai[i] << " "; //tarpai kad butu numeracija tarp numerio ir ivesto vardo
                    for (int j= 0; j < KiekPazymiu[i]; j++) {
                        cout << Pazymiai[i][j] << " ";
                    }
                    cout << "\n";

                }
            }
        }

    }

} while (pasirinkimas != 0);
return 0;
}


