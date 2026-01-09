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
    return 0;
}
