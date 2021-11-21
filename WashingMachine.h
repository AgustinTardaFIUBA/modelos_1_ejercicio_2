#ifndef MODELOS_EJERCICIO_2_WASHINGMACHINE_H
#define MODELOS_EJERCICIO_2_WASHINGMACHINE_H


#include "Garment.h"
#include <list>

class WashingMachine {
private:

    int number;

    list<Garment *> *clothes;
public:
    WashingMachine(Garment *pGarment, int i);

    bool add(Garment *pGarment);

    bool isCompatibleWithTheClothes(Garment *pGarment);

    int getNumber();

    list<Garment *> *getClothes();
};


#endif //MODELOS_EJERCICIO_2_WASHINGMACHINE_H
