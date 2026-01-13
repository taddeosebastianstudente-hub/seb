#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;
int main(){
    srand(time(NULL));
    int giocatori=2;// numero giocatori
    int tabellone[91]; // indica i numeri nel tabellone
    int cartelle[2][3][9]; // array con tutte le cartelle
    int estratti[91]; // per estrarre numeri una volta
    int segnati[2][3][9];
    int tombola=0;
    for (int i=0;i<91;i++) {
        tabellone[i] = 0;
        estratti[i] = 0;
    }
    for (int g=0;g<giocatori;g++) {  // inizializzazione cartelle
        for (int r=0;r<3;r++) {      // g=giocatori, r=righe, c=colonne
            for (int c=0;c<9;c++) {
                cartelle[g][r][c]=0;
            }
        }
    }
     for (int g=0; g<giocatori;g++) {  // generazione cartelle
        for (int r = 0;r<3;r++) {     // generazione cartelle
            int inseriti=0;  // contatore
            for (int c=0; c<9&&inseriti<5;c++) {  // serve a scorrere le decine e non mettere più di 5 numeri a riga
                if (rand()%2==0) {
                    int num;  // numero da estrarre
                    int ok=0;    // variabile di controllo
                    while (ok==0) {   //estrae
                        if (c==8){
                            num=90;
                        }
                        else{
                            num=(rand()%10)+c*10+1;
                    }
                       ok=1;
                       for (int rr=0;rr<3;rr++) {               //controlla tutta la cartelle del giocatore
                            for (int cc=0;cc<9;cc++) {           
                                if (cartelle[g][rr][cc]==num)
                                    ok=0;
                            }
                        }
                    }
                    cartelle[g][r][c]=num;    //inserisce il numero del giocatore nella cartella
                    inseriti++;
                }
            }
        }
    }
     cout<<"CARTELLE"<<endl;
    for (int g=0;g<giocatori;g++) {         //cicli per generare cartelle
        cout<<"giocatore "<<g+1<<endl;
        for (int r=0;r<3;r++) {
            for (int c=0;c<9;c++) {
                if (cartelle[g][r][c]==0){
                    cout<<"    ";
                }
                else{
                    cout<<cartelle[g][r][c]<<"  ";
                }
            }
            cout<<endl;
        }
        cout << "---------------------------------"<<endl;
    }
    for (int e=1;e<=90&&tombola==0;e++) {    //cicli per estrarre i numeri
        int num;
        int trovato=0;
        while (trovato==0) {       //ciclo per evitare due numeri
            num=rand()%90+1;   
            if (estratti[num]==0) {
                estratti[num]=1;
                trovato=1;
            }
        }
        tabellone[num]=1;
        cout<<"estratto: "<<num<<endl;
        sleep(1);
         for (int g=0;g<giocatori;g++) {
            int contatore=0;
            for (int r=0;r<3;r++) {
                for (int c=0;c<9;c++) {
                   if (cartelle[g][r][c]!=0 && tabellone[cartelle[g][r][c]]==1){
                        contatore++;
                   }
                }
            }
            if (contatore==15) {
                cout<<"tombola, vince il giocatore "<<g+1<<endl;
                tombola=1;
            }
        }
    }
    return 0;
}
