#include <iostream>
using namespace std;
#include <fstream>

void dividir(int a[], int inicial, int final);
void Fusionar(int a[],int pinicial, int pfinal, int medio);
void archivo(int a[]);


int main()
{
   int A[5];
   cout << "Ingrese 5 numero: " << endl;
   for(int i=0; i<5 ; i++){
     cin >> A[i];
   }
   archivo(A);
   cout << "Numeros ordenados: " << endl;
   for (int i = 0; i < 5; i++)
	{
	    cout<<"|"<<A[i]<<"|";
	}
    return 0;
}

void archivo(int a[]){
  ofstream archivo;
  archivo.open("mergesort",ios::app);
  if(archivo.fail()){
    cout << "El archivo no se pudo abrir" << endl;
  }else{
    archivo << "Numeros iniciales: " << endl;
    for(int i=0; i<5 ; i++){
     archivo <<" [" << a[i] << "]";
   }
   archivo << endl;
   archivo << "Numeros ordenados: " << endl;
   dividir(a,0,3);
   for(int i=0; i<5 ; i++){
     archivo <<" [" << a[i] << "]";
   }
  }
  archivo.close();
}

void dividir(int a[], int inicial, int final)
{

    if(inicial>=final)
    {
		return;
	}
	int m =inicial+ (final-inicial)/2;
	dividir(a,inicial,m);
	dividir(a,m+1,final);
	Fusionar(a,inicial,m,final);
}


void Fusionar(int a[], int pinicial, int medio, int pfinal)
{
    int n1 = medio - pinicial + 1;
    int n2 = pfinal - medio;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
      L[i] = a[pinicial + i];
    for (int j = 0; j < n2; j++)
      R[j] = a[medio + 1 + j];


    int i = 0;

    int j = 0;

    int k = pinicial;

    while (i < n1 && j < n2) {
      if (L[i] <= R[j]) {
        a[k] = L[i];
        i++;
      }
      else {
        a[k] = R[j];
        j++;
      }
      k++;
    }
    while (i < n1) {
      a[k] = L[i];
      i++;
      k++;
    }

    while (j < n2) {
      a[k] = R[j];
      j++;
      k++;
    }
}

