// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//funcion crea una matriz de chars de nxn
char** createMatriz(int);
//funcion para liberar memoria asignada  a una matriz
void freeMatriz(int, char**);

void printMatrix(int , char** );

//funcion para salir del laberinto
void salirLaberinto(char**, int, int, int);

int main (int argc, char* argv[]) {
  char letra;
  ifstream myfile (argv[1]);
  int size;
  char** matrix;
  if (myfile.is_open())
  {
    int cont=0;


    //TODO: Leer el tamaño de la matriz e iniciarlizarla

    myfile>>size;

     matrix= createMatriz(size);
    
    //lleer la mtriz que contiene el laberinto
    for(int i=0;i<size;i++){
     for (int j=0;j<size;j++){
      myfile>>matrix[i][j];
     }
    } 


    /*while ( !myfile.eof() )
    {
      myfile >> letra;
      cout<<" "<<letra;
      if(cont == 9){
         cout<<endl;
         cont=0;
      }else
          cont++;

	//TODO:Llenar la matriz
      
    }*/

    myfile.close();
  }

  else cout << "El archivo no existe"; 
  //imprimir laberinto
  //printMatrix(size,matrix);

  //TODO: llamar función SalirLaberinto
  salirLaberinto(matrix,size,1,0);
  

  //TODO: Liberar Memoria
  freeMatriz(size,matrix);

  return 0;
}//fin main

//salir del Laberinto
void salirLaberinto(char** matrix, int size, int x, int y){
 printMatrix(size,matrix);
 cin.get();

 if (y==size-1){
  cout<<"Ha encontrado la salida del Laberinto!"<<endl;
  return;
 }else{
  //moverse  hacia arriba
   if(x>0)
    if (matrix[x-1][y]== '.'){
      matrix[x][y]= '*';
      salirLaberinto(matrix, size, x-1, y);
    }
   //moverse hacia abajo 
   if (x<size-1)
    if( matrix [x+1][y]=='.'){
     matrix[x][y] = '*';
     salirLaberinto(matrix, size, x+1, y);
    }
  //moverse a la izquirda
  if (y>0)
   if (matrix[x][y-1]=='.'){
    matrix[x][y]= '*';
    salirLaberinto(matrix, size, x, y-1);
   }
  //moverse a la derecha
  if (y<size-1)
   if (matrix[x][y+1]=='.'){
    matrix[x][y]= '*';
    salirLaberinto(matrix, size, x, y+1);
   }//


 }//if paso recursivo
}//fin funcion salir del laberinro

//crear matriz
char** createMatriz(int n){
 char** retVal= new char*[n];

 for(int i=0;i<n;i++)
  retVal[i]=new char[n];

 return retVal;
}//fin

//liberar memoria
void freeMatriz(int n, char** matrix){
 for(int i=0;i<n;i++)
  delete[] matrix[i];

 delete[] matrix;
}

//imprimir matriz
void printMatrix(int size, char** matrix){
 for(int i=0;i<size;i++){
  for (int j=0;j<size;j++){
   cout<<" "<<matrix[i][j];
  }
  cout<<endl;
 }
}
