#include <iostream>
#include <memory>
#ifndef registros_H
#define registros_H
using namespace std;
class Contador_registros{
    private:
    int* contador_;
    public:
    Contador_registros(): contador_(new int(1)){
        cout << "Constructor: Contador = " << *contador_ <<endl;
    }
    Contador_registros(Contador_registros& otro): contador_(otro.contador_){
        (*contador_)++;
    cout<<"constructor copia: contador = "<<contador_<<endl;
    }
    ~Contador_registros(){
        (*contador_)--;
        cout<<"destructor contador = "<<*contador_<<endl;
        if(*contador_==0){
            delete contador_;
            cout<<"memoria liberada"<<endl;
        }
    }
};

#endif