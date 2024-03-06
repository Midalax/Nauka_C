#include <iostream>
#include <string>

using namespace std;

class Haslo {
public: 
    int suma_punktow;
    int miejsce;
    string haslo;
    int duze, male, cyfry, znaki_specjalne;
};

int tester(int minimum, int maximum, char g) {
    if ((int)g >= minimum && (int)g <= maximum) {
        return 1;
    }
    return 0;
}

int ilosc_duzych(string napis) {
    int licznik = 0;
    for (int i = 0; i <= napis.length() - 1; i++) {
        char duza = toupper(napis.at(i));
        if (duza == napis.at(i)) {
            licznik += tester(65, 90, duza); 
        }
    }
    return licznik;
}

int ilosc_malych(string napis) {
    int licznik = 0;
    for (int i = 0; i <= napis.length() - 1; i++) {
        char mala = tolower(napis.at(i));
        if (mala == napis.at(i)) {
            licznik += tester(97, 122, mala); 
        }
    }
    return licznik;
}

int ilosc_cyfer(string napis) {
    int punkty = 0;
    for (int i = 0; i <= napis.length() - 1; i++) {
        char k = napis.at(i);
        if ((int)k >= 48 && (int)k <= 57) {
            punkty++;
        }
    }
    return punkty;
}

int ilosc_znakow(string napis) {
    int punkty = 0;
    for (int i = 0; i <= napis.length() - 1; i++) {
        char k = napis.at(i);
        if ((int)k >= 33 && (int)k <= 47 || (int)k >= 58 && (int)k <= 64 || (int)k >= 91 && (int)k <= 96) {
            punkty++;
        }
    }
    return punkty;
}

int punktator(int duze, int male, int cyfry, int znaki_specjalne) {
    duze = duze * 2;
    cyfry = cyfry * 3;
    znaki_specjalne = znaki_specjalne * 4;
    return duze + male + cyfry + znaki_specjalne;
}
void bubbleSort(Haslo arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j].suma_punktow < arr[j+1].suma_punktow) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}
int main() {
    int ilosc_hasel;
    cout << "Podaj ilosc hasel do przeanalizowania: "; 
    cin >> ilosc_hasel;
    cin.ignore();
    
    Haslo* typ = new Haslo[ilosc_hasel];

    for (int i = 0; i < ilosc_hasel; i++) {
        cout << "\nPodaj haslo " << i + 1 << ": ";
        getline(cin, typ[i].haslo);
        typ[i].duze = ilosc_duzych(typ[i].haslo);
        typ[i].male = ilosc_malych(typ[i].haslo);
        typ[i].cyfry = ilosc_cyfer(typ[i].haslo);
        typ[i].znaki_specjalne = ilosc_znakow(typ[i].haslo);
        typ[i].suma_punktow = punktator(typ[i].duze, typ[i].male, typ[i].cyfry, typ[i].znaki_specjalne);

        cout << "Ilosc duzych liter w hasle " << i + 1 << ": " << typ[i].duze << endl;
        cout << "Ilosc malych liter w hasle " << i + 1 << ": " << typ[i].male << endl;
        cout << "Ilosc cyfr w hasle " << i + 1 << ": " << typ[i].cyfry << endl;
        cout << "Ilosc znakow specjalnych w hasle " << i + 1 << ": " << typ[i].znaki_specjalne << endl;
        cout << "Punktacja hasla " << i + 1 << ": " << typ[i].suma_punktow << endl;
    }


  
    bubbleSort(typ, ilosc_hasel);

    cout << "\nPosortowane hasla wzgledem punktacji: \n";
    for (int i = 0; i < ilosc_hasel; i++) {
        cout << "Haslo: " << typ[i].haslo << ", Punkty: " << typ[i].suma_punktow << endl;
    }

    delete[] typ;
    return 0;
}