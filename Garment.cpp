#include "Garment.h"

Garment::Garment(int number) {
  this->number = number;
  this->incompatibleClothes = new list<int>;
}

bool Garment::IsNumber(int number) {
  return this->number==number;
}

void Garment::addIncompatibilityWith(int germentNumber) {
  incompatibleClothes->push_back(germentNumber);
}

void Garment::addWahingTime(int washingTime) {
  this->washingTime = washingTime;
}

int Garment::getWashingTime() {
  return this->washingTime;
}

int Garment::getNumber() {
  return this->number;
}

bool Garment::isCompatibleWith(Garment *pGarment) {
  auto it = this->incompatibleClothes->begin();
  bool isCompatible = true;
  while(isCompatible && it != this->incompatibleClothes->end()){
    int incompatibleGarmentNumber = *it;
    isCompatible = !pGarment->IsNumber(incompatibleGarmentNumber);
    it++;
  }

  return isCompatible;
}

void Garment::printIncompatibilities() {
  for (auto it = incompatibleClothes->begin(); it != incompatibleClothes->end(); ++it){
    int incompatibleClotheNumber= *it ;
    cout<< incompatibleClotheNumber <<" , "  ;
  }
  cout<<endl ;
}
