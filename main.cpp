#include <iostream>
#include "ctime"
using namespace std;

int resultado (int ** matriz, int tam, int coincidencias)
{
    int puntos=0;


    for (int j=0; j<tam; j++)
    {
        int sum =0;

        for (int i=0; i<tam; i++)
        {
             sum = sum + *(*(matriz+i)+j);
        }

        if (sum >= coincidencias)
          {cout << +1 << "\t";
           puntos = puntos+1;
          }
        else
            {
            cout << -1 << "\t";
            puntos = puntos-1;
            }

    }

    return puntos;

}

int main() {

    srand((unsigned int)time(NULL));

    int tam;
    cout << "Ingrese el tamano de la matriz" << endl;
    cin >> tam;

    int c;
    cout << "Ingrese la cantidad minima de \"1\"s por columna "<< endl;
    cin >> c;

    int ** matriz = new int * [tam];
    for ( int i=0; i<tam; i++)
    {
        matriz [i] = new int [tam];
    }

    for (int i=0; i<tam; i++)
    {
        for (int j=0; j<tam; j++)
        {
            int val = rand()%2;
            *(*(matriz+i)+j) = val;
        }
    }




    for (int i=0; i<tam; i++)
    {
        for (int j=0; j<tam; j++)
        {

            int val = *(*(matriz+i)+j);
            cout << val << "\t";
        }
        cout << endl;
    }

    for (int i=0; i<tam; i++)
    {
        cout << "__\t";
    }
    cout << endl;

    int res = resultado (matriz, tam, c);
    cout <<  endl << "Resultado :" << res << endl;

}
