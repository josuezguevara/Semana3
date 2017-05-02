#include <iostream>

using namespace std;

int main(){

 int arregloEstatico[5];

 cout<<arregloEstatico<<endl;
 //apuntador de enteros
 int* apuntador;//apunta a enteros
 apuntador= arregloEstatico;
 cout<<"Dir ptr: " <<apuntador<<endl;

//inicializador
 for (int i=0;i<5;i++)
  arregloEstatico[i]=i+1;

  cout<<" Contenido de ptr: "<<endl;
 //imprimir contenido 
 for (int i=0;i<5;i++)
  cout<<apuntador[i]<<endl;

  cout<<"____________"<<endl;
  cout<<*(apuntador+4)<<endl;

 //reservar un arrreglo tamaño 19
  apuntador= new int[10];
  cout<<"Dir arreglo en heap: "<<apuntador<<endl;

  //liberar memoria
  delete[] apuntador;

   apuntador= NULL;

   delete[] apuntador;

   //Matrices
   int** matriz;

   matriz = new int*[5];
   for (int i=0;i<5;i++)
    matriz[i]=new int [5];
   
   //llenar matriz
   for (int i=0;i<5;i++)
    for (int j=0; i<5; i++)
     matriz[i][j]=i*j;

  //usar la matriz



  //liberar la memoria
  for (int i=0;i<5;i++)
   delete[] matriz[i];

  delete[] matriz;
return 0;
}//fin main
