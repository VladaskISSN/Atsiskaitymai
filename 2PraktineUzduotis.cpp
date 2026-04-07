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
    }
        if (pasirinkimas == 2) {
            if (KiekMokiniu == 0) {
                cout << "Mokiniu sarasas tuscias. \n";
            } else {
                cout << "Mokiniu sarasas: \n";
                for (int i= 0; i < KiekMokiniu; i++) {
                    cout << i + 1 << " " << Vardai[i] << " "; //tarpai kad butu numeracija tarp numerio ir ivesto vardo
                    for (int j= 0; j < KiekPazymiu[i]; j++) {
                        cout << Pazymiai[i][j] << " ";
                    }
                    cout << "\n";

                }
            }
        }

    if (pasirinkimas == 3) {
        int MokinioNumeris, PazymioNumeris, NaujasPazymis;
        cout << "Kelinto mokinio pazymi nori pakeisti? " ;
        cin >> MokinioNumeris;
        MokinioNumeris--;  // nr-1
        if (MokinioNumeris >= 0 && MokinioNumeris < KiekMokiniu) {
            cout << "Kelinta pazymi nori pakeisti? ";
            cin >> PazymioNumeris;
            PazymioNumeris--;
            if (PazymioNumeris >= 0 && PazymioNumeris <KiekPazymiu[MokinioNumeris]) {
                cout << "Ivesk nauja pazymi: ";
                cin >> NaujasPazymis;
                Pazymiai[MokinioNumeris][PazymioNumeris] = NaujasPazymis;
                cout << "Pazymys pakeistas.\n";
            }else {
                cout << "Tokio pazymio nera.\n";
            }
            }else {
                cout << "Tokio mokinio nera.\n";
        }
    }
    if (pasirinkimas == 4) {
        int MokinioNumeris, PazymioNumeris;
        cout << "Kelinta mokini nori istrinti?" ;
        cin >> MokinioNumeris;
        MokinioNumeris--; //sumazinti vienetu
        if (MokinioNumeris >= 0 && MokinioNumeris < KiekMokiniu) {
            for (int i = MokinioNumeris; i < KiekMokiniu - 1; i++) {
                Vardai[i] = Vardai[i + 1];
                KiekPazymiu[i] = KiekPazymiu[i + 1];
                for (int j= 0; j < DidziausiasGalimasPazymiuSkaicius; j++) {
                    Pazymiai[i][j] = Pazymiai[i + 1][j];
                }
            }
            KiekMokiniu--;
            cout << "Mokinys istrintas. \n";
        } else {
            cout << "Tokio mokinio nera.\n";
        }
    }
        if (pasirinkimas == 5) {
            cout << "Programa baigta.\n";
        }

} while (pasirinkimas != 5);
return 0;
}

