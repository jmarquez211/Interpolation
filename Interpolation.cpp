#include <iostream>
#include <string>
#include <fstream> //lectura de archivos de texto
#include <vector>
#include <cmath>   //para operar con potencias
#include <iomanip> //para definir la precision de los decimales

using namespace std;

int main(){


string fichero; //se solicita al usuario el nombre del fichero
cout<<"Nombre del fichero que desea abrir"<<endl;
cin >> fichero;


ifstream datos(fichero); //con esta sentencia podemos leer el fichero
if(!datos){// retorna un error si el fichero escrito en consola no existe
    cout<<"No existe el fichero o se ha escrito mal."<<endl;
    datos.close();
    return 0;
}


    double x,y;
    vector <double> vX,vY;
    while(datos>>x>>y){ //almacena las columnas en los vectores definidos vX y vY
        vX.push_back(x);
        vY.push_back(y);
    }
    cout <<"\nLa matriz de coefientes e inversa son:\n\n ";

//SISTEMA DE ECUACIONES

    //calculo de los sumatorios, con bucles for

    double sum_X=0; //variable para definir el sumario x_i
    for(int i=0;i<vX.size();i++){//calculo del sumatorio x_i
    sum_X+=vX[i];
    }

    double sum_X2=0; //variable para definir el sumario x_i^2
    for(int i=0;i<vX.size();i++){//calculo del sumatorio x_i^2
    sum_X2+=vX[i]*vX[i];
    }

    double sum_X3=0;
    for(int i=0;i<vX.size();i++){//calculo del sumatorio x_i^3
    sum_X3+=pow(vX[i],3); //usar pow(,) es mas lento computacionalmente pero ahorra tiempo escribiendo
    }

    double sum_X4=0;
    for(int i=0;i<vX.size();i++){//calculo del sumatorio x_i^4
    sum_X4+=pow(vX[i],4);
    }

    double sum_Y=0;
    for(int i=0;i<vY.size();i++){//calculo del sumatorio y_i
    sum_Y+=vY[i];
    }

    double sum_XY=0;
    for(int i=0;i<vX.size();i++){//calculo del sumatorio x_i*y_i
    sum_XY+=vX[i]*vY[i];
    }

    double sum_X2Y=0;
    for(int i=0;i<vX.size();i++){//calculo del sumatorio (x_i)^2*y_i
    sum_X2Y+=vX[i]*vX[i]*vY[i];
    }


    //pasos para obtener la matriz inversa


    //Matriz A de coeficientes
    double A[3][3]={{vX.size(),sum_X,sum_X2},{sum_X,sum_X2,sum_X3},{sum_X2,sum_X3,sum_X4}};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<A[i][j]<<" ";
        }
            cout<<"\n";
    }
    cout <<"\n";

    //Determinante por la regla de Sarrus
    double det_A=A[0][0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1])+A[0][1]*(A[1][2]*A[2][0]-A[1][0]*A[2][2])+A[0][2]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);
    if(det_A!=0){

    //Matriz adjunta
    double adj_A[3][3]; //matriz adjunta
    int f1,f2,c1,c2; //filas y columnas de A traspuesta
    for(int i=0;i<3;i++){
        for(int i=0;i<3;i++){
                if(i=0){
                    f1=1;
                    f2=2;
                }
                if(i=1){
                    f1=0;
                    f2=2;
                }
                if(i=2){
                    f1=0;
                    f2=1;
            }

        for(int j=0;j<3;j++){
            if(j=0){
                c1=1;
                c2=2;
            }
            if(j=1){
                c1=0;
                c2=2;
            }
            if(j=2){
                c1=0;
                c2=1;
            }
            adj_A[i][j]=pow(-1,i+j)*(A[f1][c1]*A[f2][c2]-A[f1][c2]*A[f2][c1]);
        }
    }
    }
    //Matriz adjunta traspuesta
    double adjt_A[3][3]; //declaracion de la adjunta traspuesta
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            adjt_A[i][j]=adj_A[j][i];
        }
    }
    //Matriz inversa
    double inv_A[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            inv_A[i][j]=adjt_A[i][j]/det_A;
            cout<<inv_A[i][j]<<" ";
        }
        cout<<"\n";
    }

    //los coeficientes del polinomio se obtienen multiplicando A inversa por el vector de sumatorios x*y_i
    double b0,b1,b2=0;
    b0 = inv_A[0][0]*sum_Y + inv_A[0][1]*sum_XY + inv_A[0][2]*sum_X2Y;
    b1 = inv_A[1][0]*sum_Y + inv_A[1][1]*sum_XY + inv_A[1][2]*sum_X2Y;
    b2 = inv_A[2][0]*sum_Y + inv_A[2][1]*sum_XY + inv_A[2][2]*sum_X2Y;

    // el polonomio por ajuste de minimos cuadrados es el siguiente

cout <<"\nEl polinomio es: "<<scientific<<setprecision(4)<< "y = "<<b0<<"+"<<b1<<"*x"<<"+"<<b2<<"*x^2"<<endl;
return 0;
    }

else{
        cout<<"La matriz es singular. Terminar"<<endl;
        return 0;
    }

}
