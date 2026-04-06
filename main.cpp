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
        cout << "3. Baigti darba\n";
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

                cout << "Kiek pazymiu turi mokinys? ";
                cin >> pazymiuKiekis[mokiniuKiekis];

                if (pazymiuKiekis[mokiniuKiekis] > MAX_PAZYMIU) {
                    pazymiuKiekis[mokiniuKiekis] = MAX_PAZYMIU;
                }

                for (int j = 0; j < pazymiuKiekis[mokiniuKiekis]; j++) {
                    cout << "Iveskite " << j + 1 << " pazymi: ";
                    cin >> pazymiai[mokiniuKiekis][j];
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

            case 3:
                cout << "Programa baigta.\n";
                break;

            default:
                cout << "Neteisingas pasirinkimas.\n";
        }

    } while (pasirinkimas != 3);

    return 0;
}