#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
// Nuskaito skaicius is failo i masyva
vector<int> nuskaitytiFaila(string failoPavadinimas) {
    vector<int> masyvas;
    ifstream failas(failoPavadinimas);

    if (!failas) {
        cout << "Nepavyko atidaryti failo: " << failoPavadinimas << endl;
        return masyvas;
    }
    int skaicius;

    while (failas >> skaicius) {
        masyvas.push_back(skaicius);
    }

    failas.close();

    return masyvas;
}
// Patikrina, ar masyvas surikiuotas didejimo tvarka
bool arSurikiuotas(vector<int> masyvas) {
    for (int i = 1; i < masyvas.size(); i++) {
        if (masyvas[i - 1] > masyvas[i]) {
            return false;
        }
    }

    return true;
}
// Iterpimo rikiavimas
void insertionSort(vector<int>& masyvas, long long& palyginimai, long long& sukeitimai) {
    for (int i = 1; i < masyvas.size(); i++) {
        int laikinas = masyvas[i];
        int j = i - 1;

        while (j >= 0) {
            palyginimai++;

            if (masyvas[j] > laikinas) {
                masyvas[j + 1] = masyvas[j];
                sukeitimai++;
                j--;
            } else {
                break;
            }
        }

        masyvas[j + 1] = laikinas;
    }
}
// Merge sort sujungimo dalis
void sujungti(vector<int>& masyvas, int kaire, int vidurys, int desine,
              long long& palyginimai, long long& sukeitimai) {

    vector<int> kairesDalis;
    vector<int> desinesDalis;

    for (int i = kaire; i <= vidurys; i++) {
        kairesDalis.push_back(masyvas[i]);
    }

    for (int i = vidurys + 1; i <= desine; i++) {
        desinesDalis.push_back(masyvas[i]);
    }
    int i = 0;
    int j = 0;
    int k = kaire;
    while (i < kairesDalis.size() && j < desinesDalis.size()) {
        palyginimai++;

        if (kairesDalis[i] <= desinesDalis[j]) {
            masyvas[k] = kairesDalis[i];
            i++;
        } else {
            masyvas[k] = desinesDalis[j];
            j++;
        }

        sukeitimai++;
        k++;
    }

    while (i < kairesDalis.size()) {
        masyvas[k] = kairesDalis[i];
        i++;
        k++;
        sukeitimai++;
    }

    while (j < desinesDalis.size()) {
        masyvas[k] = desinesDalis[j];
        j++;
        k++;
        sukeitimai++;
    }
}

// Suliejimo rikiavimas
void mergeSort(vector<int>& masyvas, int kaire, int desine,
               long long& palyginimai, long long& sukeitimai) {

    if (kaire >= desine) {
        return;
    }

    int vidurys = (kaire + desine) / 2;
    mergeSort(masyvas, kaire, vidurys, palyginimai, sukeitimai);
    mergeSort(masyvas, vidurys + 1, desine, palyginimai, sukeitimai);

    sujungti(masyvas, kaire, vidurys, desine, palyginimai, sukeitimai);
}
int main() {
    string failai[9] = {
        "atvirkstiniai_5000.txt",
        "atvirkstiniai_10000.txt",
        "atvirkstiniai_50000.txt",

        "ismaisyti_5000.txt",
        "ismaisyti_10000.txt",
        "ismaisyti_50000.txt",

        "isrikiuoti_5000.txt",
        "isrikiuoti_10000.txt",
        "isrikiuoti_50000.txt"
    };

    ofstream rezultatai("rezultatai.csv");

    rezultatai << "Failas;Algoritmas;Laikas_us;Palyginimai;Sukeitimai\n";

    for (int f = 0; f < 9; f++) {
        vector<int> pradinis = nuskaitytiFaila(failai[f]);

        if (pradinis.size() == 0) {
            cout << "Failas nerastas arba tuscias: " << failai[f] << endl;
            continue;
        }

        cout << endl;
        cout << "Testuojamas failas: " << failai[f] << endl;
        cout << "Elementu kiekis: " << pradinis.size() << endl;

        long long insertionLaikasSuma = 0;
        long long insertionPalyginimaiSuma = 0;
        long long insertionSukeitimaiSuma = 0;

        long long mergeLaikasSuma = 0;
        long long mergePalyginimaiSuma = 0;
        long long mergeSukeitimaiSuma = 0;

        for (int bandymas = 1; bandymas <= 5; bandymas++) {
            cout << "Bandymas " << bandymas << endl;

            // Insertion sort testavimas
            vector<int> masyvas1 = pradinis;

            long long palyginimai1 = 0;
            long long sukeitimai1 = 0;

            auto pradzia1 = chrono::high_resolution_clock::now();

            insertionSort(masyvas1, palyginimai1, sukeitimai1);

            auto pabaiga1 = chrono::high_resolution_clock::now();

            long long laikas1 = chrono::duration_cast<chrono::microseconds>(pabaiga1 - pradzia1).count();

            insertionLaikasSuma += laikas1;
            insertionPalyginimaiSuma += palyginimai1;
            insertionSukeitimaiSuma += sukeitimai1;

            if (!arSurikiuotas(masyvas1)) {
                cout << "Insertion sort klaida!" << endl;
            }

            // Merge sort testavimas
            vector<int> masyvas2 = pradinis;

            long long palyginimai2 = 0;
            long long sukeitimai2 = 0;

            auto pradzia2 = chrono::high_resolution_clock::now();

            mergeSort(masyvas2, 0, masyvas2.size() - 1, palyginimai2, sukeitimai2);

            auto pabaiga2 = chrono::high_resolution_clock::now();

            long long laikas2 = chrono::duration_cast<chrono::microseconds>(pabaiga2 - pradzia2).count();

            mergeLaikasSuma += laikas2;
            mergePalyginimaiSuma += palyginimai2;
            mergeSukeitimaiSuma += sukeitimai2;

            if (!arSurikiuotas(masyvas2)) {
                cout << "Merge sort klaida!" << endl;
            }
        }

        long long insertionLaikasVid = insertionLaikasSuma / 5;
        long long insertionPalyginimaiVid = insertionPalyginimaiSuma / 5;
        long long insertionSukeitimaiVid = insertionSukeitimaiSuma / 5;

        long long mergeLaikasVid = mergeLaikasSuma / 5;
        long long mergePalyginimaiVid = mergePalyginimaiSuma / 5;
        long long mergeSukeitimaiVid = mergeSukeitimaiSuma / 5;

        cout << endl;
        cout << "Insertion sort:" << endl;
        cout << "Laikas: " << insertionLaikasVid << " us" << endl;
        cout << "Palyginimai: " << insertionPalyginimaiVid << endl;
        cout << "Sukeitimai/perkelimai: " << insertionSukeitimaiVid << endl;

        cout << endl;
        cout << "Merge sort:" << endl;
        cout << "Laikas: " << mergeLaikasVid << " us" << endl;
        cout << "Palyginimai: " << mergePalyginimaiVid << endl;
        cout << "Sukeitimai/perkelimai: " << mergeSukeitimaiVid << endl;

        cout << "--------------------------------------" << endl;

        rezultatai << failai[f] << ";Insertion sort;"
                   << insertionLaikasVid << ";"
                   << insertionPalyginimaiVid << ";"
                   << insertionSukeitimaiVid << endl;

        rezultatai << failai[f] << ";Merge sort;"
                   << mergeLaikasVid << ";"
                   << mergePalyginimaiVid << ";"
                   << mergeSukeitimaiVid << endl;
    }

    rezultatai.close();

    cout << endl;
    cout << "Programa baige darba." << endl;
    cout << "Rezultatai issaugoti faile rezultatai.csv" << endl;

    return 0;
}