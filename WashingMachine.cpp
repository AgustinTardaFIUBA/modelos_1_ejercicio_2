#include "WashingMachine.h"

WashingMachine::WashingMachine(Garment *pGarment, int number) {
  this->clothes = new list<Garment*>;
  this->clothes->push_back(pGarment);
  this->number = number;
}

bool WashingMachine::add(Garment *pGarment){
  bool canBeAdded = isCompatibleWithTheClothes(pGarment);
  if(canBeAdded)
    this->clothes->push_back(pGarment);
  return canBeAdded;
}

bool WashingMachine::isCompatibleWithTheClothes(Garment *pGarment) {
  auto it = this->clothes->begin();
  bool isCompatible = true;

  while(isCompatible && it != this->clothes->end()){
    Garment* germentAlreadyAdded = *it;
    isCompatible = germentAlreadyAdded->isCompatibleWith(pGarment) && pGarment->isCompatibleWith(germentAlreadyAdded);
    it++;
  }

  return isCompatible;
}

int WashingMachine::getNumber() {
  return this->number;
}

list<Garment *> *WashingMachine::getClothes() {
  return this->clothes;
}
