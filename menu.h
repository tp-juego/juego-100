#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "funciones.h"
int JuegoJ1 (int punTotal, string &nombreJ1, int &maximosPuntos);
int JuegoJ2 (int punTotalJ1, string &nombreJ1, int punTotalJ2, string &nombreJ2, int &maximosPuntos);
int ModoSimulado (string &nombreJ1);
void mostrarPuntuacionMax(int &maximosPuntos);

/// OPCION 1
int JuegoJ1 (int punTotal, string &nombreJ1, int &maximosPuntos){
    int v[6], rondas=0, lanzamiento, vPuntos[3]{}, x, m;
    const int TAM = 6;

    while (punTotal<100){
    system("cls");
    rondas++;
    lanzamiento = 1;
    ponerCero (vPuntos, TAM);
    for (x=0; x<3; x++){
    system("cls");
    cout << "TURNO DE " << nombreJ1 << " | RONDA N " << rondas << " | PUNTAJE TOTAL: " << punTotal << " PUNTOS" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "MAXIMO PUNTAJE DE LA RONDA: " << vPuntos[m] << " PUNTOS" << endl;
    cout << "LANZAMIENTO N " << lanzamiento++ << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "PRESIONE UNA TECLA PARA LANZAR" << endl;
    system("pause");
    cout<<endl;

    cargarAleatorio (v,TAM,6);
    mostrarVector (v, TAM);
    vPuntos[x] = resultadoCombinaciones (v, TAM);
    if (vPuntos[x]==0){
        punTotal = 0;
    }
    if (vPuntos[x]==100){
        punTotal = vPuntos[x];
        system("pause");
        system("cls");
        entreTurnos (rondas, punTotal, nombreJ1);
        system("pause");
        return punTotal;
    }
    m = maximoVector (vPuntos, 3);
    cout << endl << "------------ |  SUMAS: " << vPuntos[x] << " PUNTOS  | -------------" << endl;
    system("pause");
    }
    punTotal += vPuntos[m];

    if (punTotal>maximosPuntos){
        maximosPuntos = punTotal;
    }
    system("cls");
    entreTurnos (rondas, punTotal, nombreJ1);
    system("pause");
    }
    return punTotal;
}


///OPCION 2
int JuegoJ2 (int punTotalJ1, string &nombreJ1, int punTotalJ2, string &nombreJ2, int &maximosPuntos){
    int puntuacionMaxima;

    int v[6], rondas=0, lanzamiento, vPuntos[3]{}, x, m,vPuntosJ2[3]{};
    const int TAM = 6;

    while (punTotalJ1<100 && punTotalJ2<100){
    system("cls");
    rondas++;
    lanzamiento = 1;
    ponerCero (vPuntos, TAM);
///JUGADOR 1
    for (x=0; x<3; x++){
    system("cls");
    cout << "TURNO DE " << nombreJ1 << " | RONDA N " << rondas << " | PUNTAJE TOTAL: " << punTotalJ1 << " PUNTOS" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "MAXIMO PUNTAJE DE LA RONDA: " << vPuntos[m] << " PUNTOS" << endl;
    cout << "LANZAMIENTO N " << lanzamiento++ << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "PRESIONE UNA TECLA PARA LANZAR" << endl;
    system("pause");
    cout<<endl;

    cargarAleatorio (v,TAM,6);
    mostrarVector (v, TAM);
    vPuntos[x] = resultadoCombinaciones (v, TAM);
    if (vPuntos[x]==0){
        punTotalJ1 = 0;
    }
    if (vPuntos[x]==100){
        punTotalJ1 = vPuntos[x];
        system("pause");
        system("cls");
        entreTurnosJ2 (rondas, punTotalJ1, nombreJ1, punTotalJ2, nombreJ2);
        system("pause");

        return punTotalJ1;
    }
    m = maximoVector (vPuntos, 3);
    cout << endl << "------------ |  SUMAS: " << vPuntos[x] << " PUNTOS  | -------------" << endl;
    system("pause");
    }

    punTotalJ1 += vPuntos[m];
    system("cls");




///JUGADOR 2
    lanzamiento=1;
     ponerCero (vPuntosJ2, TAM);
    for (x=0; x<3; x++){
    system("cls");
    cout << "TURNO DE " << nombreJ2<< " | RONDA N " << rondas << " | PUNTAJE TOTAL: " << punTotalJ2 << " PUNTOS" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "MAXIMO PUNTAJE DE LA RONDA: " << vPuntosJ2[m] << " PUNTOS" << endl;
    cout << "LANZAMIENTO N " << lanzamiento++ << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "PRESIONE UNA TECLA PARA LANZAR" << endl;
    system("pause");
    cout<<endl;

    cargarAleatorio (v,TAM,6);
    mostrarVector (v, TAM);
    vPuntosJ2[x] = resultadoCombinaciones (v, TAM);
    if (vPuntosJ2[x]==0){
        punTotalJ2 = 0;
    }
    if (vPuntosJ2[x]==100){
        punTotalJ2 = vPuntosJ2[x];
        system("pause");
        system("cls");
        entreTurnosJ2 (rondas, punTotalJ1, nombreJ1, punTotalJ2, nombreJ2);
        system("pause");
        return punTotalJ2;
    }
    m = maximoVector (vPuntosJ2, 3);
    cout << endl << "------------ |  SUMAS: " << vPuntosJ2[x] << " PUNTOS  | -------------" << endl;
    system("pause");
    }

    punTotalJ2 += vPuntosJ2[m];
    system("cls");
    entreTurnosJ2 (rondas, punTotalJ1, nombreJ1, punTotalJ2, nombreJ2);
    system("pause");
    }
    if (punTotalJ2>punTotalJ1){
        puntuacionMaxima= punTotalJ2;
    }else puntuacionMaxima= punTotalJ1;

    if (maximosPuntos>puntuacionMaxima){
        maximosPuntos = puntuacionMaxima;
    }
    return puntuacionMaxima;
}

/// OPCION 3

int ModoSimulado (string &nombreJ1){
    int v[6], rondas=0, lanzamiento, vPuntos[3]{}, x, m, punTotal=0;
    const int TAM = 6;

    while (punTotal<100){
    system("cls");
    rondas++;
    lanzamiento = 1;
    ponerCero (vPuntos, TAM);
    for (x=0; x<3; x++){
    system("cls");
    cout << "TURNO DE " << nombreJ1 << " | RONDA N " << rondas << " | PUNTAJE TOTAL: " << punTotal << " PUNTOS" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "MAXIMO PUNTAJE DE LA RONDA: " << vPuntos[m] << " PUNTOS" << endl;
    cout << "LANZAMIENTO N " << lanzamiento++ << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "PRESIONE UNA TECLA PARA LANZAR" << endl;
    system("pause");
    cout<<endl;

    cargarVector(v,TAM);
    mostrarVector (v, TAM);
    vPuntos[x] = resultadoCombinaciones (v, TAM);
    if (vPuntos[x]==0){
        punTotal = 0;
    }
    if (vPuntos[x]==100){
        punTotal = vPuntos[x];
        system("pause");
        system("cls");
        entreTurnos (rondas, punTotal, nombreJ1);
        system("pause");
        return punTotal;
    }
    m = maximoVector (vPuntos, 3);
    cout << endl << "------------ |  SUMAS: " << vPuntos[x] << " PUNTOS  | -------------" << endl;
    system("pause");
    }
    punTotal += vPuntos[m];
    system("cls");
    entreTurnos (rondas, punTotal, nombreJ1);
    system("pause");
    }
    return punTotal;
}


/// OPCION 4
void mostrarPuntuacionMax(int &maximosPuntos){
    system("cls");

    cout << "####  PUNTUACION MAS ALTA  #### " << endl << endl <<"\t \t"<< maximosPuntos << endl;
    system("pause");
}
#endif // MENU_H_INCLUDED
