#include <iostream>
#include <string>
using namespace std;

const int MAX_MOKINIU = 100;
const int MAX_PAZYMIU = 10;

int main() {
    string vardai[MAX_MOKINIU];
    int pazymiai[MAX_MOKINIU][MAX_PAZYMIU];
    int pazymiuKiekis[MAX_MOKINIU];
    int mokiniuKiekis = 0;
    int pasirinkimas;

    do {
        cout << "\n--- MOKINIU PAZYMIU SISTEMA ---\n";
        cout << "1. Prideti mokini\n";
        cout << "2. Rodyti visus mokinius\n";
        cout << "3. Rodyti vieno mokinio pazymius\n";
        cout << "4. Atnaujinti pazymi\n";
        cout << "5. Pasalinti mokini\n";
        cout << "6. Baigti darba\n";
        cout << "Pasirinkite: ";
        cin >> pasirinkimas;

        switch (pasirinkimas) {
            case 1: {
                if (mokiniuKiekis >= MAX_MOKINIU) {
                    cout << "Negalima prideti daugiau mokiniu.\n";
                    break;
                }

                cout << "Iveskite mokinio varda: ";
                cin >> ws;
                getline(cin, vardai[mokiniuKiekis]);

                do {
                    cout << "Kiek pazymiu turi mokinys? (1-10): ";
                    cin >> pazymiuKiekis[mokiniuKiekis];
                } while (pazymiuKiekis[mokiniuKiekis] < 1 || pazymiuKiekis[mokiniuKiekis] > MAX_PAZYMIU);

                for (int j = 0; j < pazymiuKiekis[mokiniuKiekis]; j++) {
                    do {
                        cout << "Iveskite " << j + 1 << " pazymi (1-10): ";
                        cin >> pazymiai[mokiniuKiekis][j];
                    } while (pazymiai[mokiniuKiekis][j] < 1 || pazymiai[mokiniuKiekis][j] > 10);
                }

                mokiniuKiekis++;
                cout << "Mokinys pridetas.\n";
                break;
            }

            case 2: {
                if (mokiniuKiekis == 0) {
                    cout << "Mokiniu sarasas tuscias.\n";
                    break;
                }

                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << i + 1 << ". " << vardai[i] << " - ";
                    for (int j = 0; j < pazymiuKiekis[i]; j++) {
                        cout << pazymiai[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }

            case 3: {
                if (mokiniuKiekis == 0) {
                    cout << "Mokiniu sarasas tuscias.\n";
                    break;
                }

                int nr;
                cout << "Iveskite mokinio numeri: ";
                cin >> nr;

                if (nr < 1 || nr > mokiniuKiekis) {
                    cout << "Tokio mokinio nera.\n";
                    break;
                }

                int i = nr - 1;
                cout << "Mokinys: " << vardai[i] << endl;
                cout << "Pazymiai: ";
                for (int j = 0; j < pazymiuKiekis[i]; j++) {
                    cout << pazymiai[i][j] << " ";
                }
                cout << endl;
                break;
            }

            case 4: {
                if (mokiniuKiekis == 0) {
                    cout << "Mokiniu sarasas tuscias.\n";
                    break;
                }

                int nr;
                cout << "Iveskite mokinio numeri: ";
                cin >> nr;

                if (nr < 1 || nr > mokiniuKiekis) {
                    cout << "Tokio mokinio nera.\n";
                    break;
                }

                int i = nr - 1;

                cout << "Mokinys: " << vardai[i] << endl;
                for (int j = 0; j < pazymiuKiekis[i]; j++) {
                    cout << j + 1 << ". " << pazymiai[i][j] << endl;
                }

                int pazNr, naujas;
                cout << "Kuri pazymi norite keisti? ";
                cin >> pazNr;

                if (pazNr < 1 || pazNr > pazymiuKiekis[i]) {
                    cout << "Tokio pazymio nera.\n";
                    break;
                }

                do {
                    cout << "Iveskite nauja pazymi (1-10): ";
                    cin >> naujas;
                } while (naujas < 1 || naujas > 10);

                pazymiai[i][pazNr - 1] = naujas;
                cout << "Pazymys atnaujintas.\n";
                break;
            }

            case 5: {
                if (mokiniuKiekis == 0) {
                    cout << "Mokiniu sarasas tuscias.\n";
                    break;
                }

                int nr;
                cout << "Iveskite mokinio numeri, kuri norite pasalinti: ";
                cin >> nr;

                if (nr < 1 || nr > mokiniuKiekis) {
                    cout << "Tokio mokinio nera.\n";
                    break;
                }

                int i = nr - 1;

                for (int j = i; j < mokiniuKiekis - 1; j++) {
                    vardai[j] = vardai[j + 1];
                    pazymiuKiekis[j] = pazymiuKiekis[j + 1];

                    for (int k = 0; k < MAX_PAZYMIU; k++) {
                        pazymiai[j][k] = pazymiai[j + 1][k];
                    }
                }

                mokiniuKiekis--;
                cout << "Mokinys pasalintas.\n";
                break;
            }

            case 6:
                cout << "Programa baigta.\n";
                break;

            default:
                cout << "Neteisingas pasirinkimas.\n";
        }

    } while (pasirinkimas != 6);

    return 0;
}
