#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(time(NULL));
    int numero=1;
    cout<<"tabella:"<<endl;
    for (int i=1;i<=9;i++) {          
        for(int j=1;j<=10;j++) {     
            if (numero<10){
                cout<<"  "<<numero;
                }
            else {
                cout<<" "<< numero;
                }
            numero++;
        }
        cout<<endl;  
        } 
            int cartella[3][5];

    // Creiamo le decine come array 9x10 (9 decine, max 10 numeri per decina)
    int decine[9][10];
    int decineRimaste[9]; // quanti numeri rimangono disponibili in ciascuna decina

    for (int i = 0; i < 9; i++) {
        int start = i * 10 + 1;
        int end = (i == 8) ? 90 : start + 9; // ultima decina include 90
        decineRimaste[i] = end - start + 1;
        for (int j = 0; j < decineRimaste[i]; j++) {
            decine[i][j] = start + j;
        }
    }

    // Generiamo la cartella
    for (int r = 0; r < 3; r++) {
        int decineDisponibili[9] = {0,1,2,3,4,5,6,7,8};
        int nDecine = 9;

        for (int c = 0; c < 5; c++) {
            // scegli una decina casuale tra quelle rimaste
            int idxDecina = rand() % nDecine;
            int decina = decineDisponibili[idxDecina];

            // togliamo la decina scelta dall'elenco
            for (int k = idxDecina; k < nDecine-1; k++) {
                decineDisponibili[k] = decineDisponibili[k+1];
            }
            nDecine--;

            // scegli un numero casuale nella decina
            int idxNumero = rand() % decineRimaste[decina];
            cartella[r][c] = decine[decina][idxNumero];

            // rimuoviamo il numero scelto dalla decina
            for (int k = idxNumero; k < decineRimaste[decina]-1; k++) {
                decine[decina][k] = decine[decina][k+1];
            }
            decineRimaste[decina]--;
        }
    }

    // Stampiamo la cartella allineata per decine
    cout << "Cartella generata:\n";
    for (int r = 0; r < 3; r++) {
        int colonna[9] = {0}; // 9 colonne per le decine
        for (int c = 0; c < 5; c++) {
            int num = cartella[r][c];
            int decina = (num == 90) ? 8 : (num-1)/10;
            colonna[decina] = num;
        }

        for (int i = 0; i < 9; i++) {
            if (colonna[i] != 0) cout << colonna[i] << "\t";
            else cout << "\t";
        }
        cout << endl;
    }
    return 0;
}

