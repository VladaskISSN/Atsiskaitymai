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

} while (pasirinkimas != 0);
return 0;
}



