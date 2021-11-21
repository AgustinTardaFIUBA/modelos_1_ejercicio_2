#ifndef MODELOS_EJERCICIO_2_GARMENT_H
#define MODELOS_EJERCICIO_2_GARMENT_H
#include <list>
#include <iostream>
using namespace std;

class Garment {
private:
    int number;
    list <int> *incompatibleClothes;
    int washingTime;

public:
    Garment(int number);


    bool IsNumber(int number);

    void addIncompatibilityWith(int germentNumber);

    void addWahingTime(int washingTime);


    int getWashingTime();

    int getNumber();

    bool isCompatibleWith(Garment *pGarment);

    void printIncompatibilities();
};


#endif //MODELOS_EJERCICIO_2_GARMENT_H
