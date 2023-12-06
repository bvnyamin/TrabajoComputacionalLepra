/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <bitset>
#include <random>
#include <memory>
#include <cstdlib>
#include "clase.h"
//#include <unistd.h>
using namespace std;
void multiplicacion_rusa(int multiplicador, int multiplicando){
    int suma=0, reserva=0;
    while(multiplicador>0){
          if(multiplicador%2!=0){
            suma+=multiplicando;
        }
        multiplicando=multiplicando*2;
        multiplicador=multiplicador/2;
        cout<<multiplicador<<"//"<<multiplicando+reserva<<endl;
       

    }
    cout<<"el resultado es "<<suma;
}


float producto_wallis(int n){
    float wallis=0;
    if (n==0)
    return 1;
    else if (n%2==0){
      wallis=static_cast <float>(n)/(n+1);
      cout<<n<<"/"<<n+1<<endl;
    return wallis *producto_wallis(n-1);
   
    }
    else{
    wallis= static_cast <float>((n)+1)/n;
     cout<<n+1<<"/"<<n<<endl;
       return wallis*producto_wallis(n-1) ;
      
    }
}
float recursividad_colas_wallis(int n, float b=1){
    if(n==0){
        return b;
    }
    else if(n%2==0){
        cout<<n<<"/"<<n+1<<endl;
        return recursividad_colas_wallis(n-1,(static_cast <float>(n)/(n+1))*b);
    }
    else{
         cout<<n+1<<"/"<<n<<endl;
        return recursividad_colas_wallis(n-1, (static_cast <float>((n)+1)/n)*b);
    }
}
bitset<26> generarConjuntoAleatorio(mt19937& rng) {
    bitset<26> conjunto;

    for (int i = 0; i < 26; i++) {
        char elemento = uniform_int_distribution<char>('A', 'Z')(rng);
        conjunto.set(elemento - 'A');
    }

    return conjunto;
}
void imprimir_conjuntos(bitset<26> conjunto){
    int i;
  for(i=0;i<26;i++){
      if(conjunto[i]){
          cout<< static_cast<char>('A'+i)<<" ";
      }
  }
  cout<<endl;
}
bitset<26> Union(bitset <26> conjuntoA, bitset<26> conjuntoB){
    return conjuntoA|conjuntoB;
}
bitset<26> interseccion(bitset <26> conjuntoA, bitset<26> conjuntoB){
    return conjuntoA & conjuntoB;
}
bitset<26> diferencia(bitset <26> conjuntoA, bitset<26> conjuntoB){
    return conjuntoA & ~conjuntoB;
}

bitset<26> diferencia2(bitset <26> conjuntoA, bitset<26> conjuntoB){
    return ~conjuntoA & conjuntoB;
}
void limpiar(){
    system("clear");
}
int main()
{int multiplicador=0, multiplicando=0,  n, opcion=6, i,repetir=1;
float resultado=0,b;
char elemento;
Contador_registros* objeto = new Contador_registros;
mt19937 rng(random_device{}());
bitset<26> conjuntoA=generarConjuntoAleatorio(rng);
bitset<26> conjuntoB=generarConjuntoAleatorio(rng);
    while(repetir==1){
cout<<"bienvenido al menu, para empezar seleccione una opcion:"<<endl;
cout<<"1. multiplicacion rusa"<<endl;
cout<<"2. producto wallis recursividad"<<endl;
cout<<"3. conjuntos"<<endl;
cout<<"4. eliminacion de datos"<<endl;
cin>>opcion;
limpiar();
if( opcion==1){
    cout<<"ingrese el valor de multiplicador ";
    cin >> multiplicador;
    cout<<"ingrese el valor de multiplicando";
    cin >> multiplicando;
    multiplicacion_rusa(multiplicador,multiplicando);
    
}

if(opcion==2){
    cout<<"1. recursividad"<<endl;
    cout<<"2. recursividad de colas"<<endl;
    cin>>opcion;
    if(opcion==1){
    cout<<"ingrese el valor de n"<<endl;
    cin>>n;
    resultado=producto_wallis(n);
    cout<<"recursividad normal "<<resultado<<endl;
    cout<<"su maximo registro de activacion es: "<<n<<endl;
    cout<<"su cantidad total de registros de activacion generados para cada ejecución es: 1"<<endl;
    cout<<"su memoria en bytes es: "<< 12*n<<endl;
}
if(opcion==2){
    cout<<"ingrese el valor de n"<<endl;
    cin>>n;
     b=recursividad_colas_wallis(n);
    cout<<"recursividad por colas "<<b<<endl;
  cout<<"su maximo registro de activacion es: "<<n<<endl;
    cout<<"su cantidad total de registros de activacion generados para cada ejecución es: 1"<<endl;
    cout<<"su memoria en bytes es: "<< 12*n<<endl;
}
}

if (opcion==3){
   cout<<"conjunto A: ";
   imprimir_conjuntos(conjuntoA);
   cout<<"conjunto B: ";
   imprimir_conjuntos(conjuntoB);
   cout<<"unionAB: ";
imprimir_conjuntos(Union(conjuntoA,conjuntoB));
cout<<"interseccion AB: ";
imprimir_conjuntos(interseccion(conjuntoA, conjuntoB));
cout<<"diferencia AB: ";
imprimir_conjuntos(diferencia(conjuntoA,conjuntoB));
cout<<"diferencia BA: ";
imprimir_conjuntos(diferencia2(conjuntoA,conjuntoB));
}
if(opcion==4){
    Contador_registros referencia1(*objeto);
    Contador_registros referencia2(*objeto);
    delete objeto;
}
cout<<"desea realizar otra operacion?"<<endl;
cout<<"1. si"<<endl;
cout<<"2. no"<<endl;
cin>>repetir;
limpiar();
}

    return 0;
}









/*
1)b
4)
*/















