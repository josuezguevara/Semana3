 reading a text file
#include iostream
#include fstream
#include string
using namespace std;

int main (int argc, char argv[]) {
  char letra;
  ifstream myfile (argv[1]);
  if (myfile.is_open())
  {
    int cont=0;


    TODO Leer el tamaño de la matriz e iniciarlizarla
    
    while ( !myfile.eof() )
    {
      myfile  letra;
      cout letra;
      if(cont == 8){
         coutendl;
         cont=0;
      }else
          cont++;

	TODOLlenar la matriz
      
    }

    myfile.close();
  }

  else cout  El archivo no existe; 

  TODO llamar función SalirLaberinto
  TODO Liberar Memoria

  return 0;
}
