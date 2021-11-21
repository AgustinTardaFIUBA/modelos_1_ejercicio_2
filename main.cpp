#include <iostream>
#include <fstream>
#include <list>
#include "WashingMachine.h"
#include "Garment.h"
using namespace std;
#define CANT_MAX 50

void intializeClothesOrderedByTime(list<Garment*> *clothes);


void addIncompatibility(int n1, int n2, list<Garment*> *pList);

void addTimeTo(int n1, int n2, list<Garment*> *pList);

bool isInClothes(list<Garment*> *pList, int n1);

Garment* findGarmentNumber(list<Garment *> *pList, int n1);

void copyOrderedByTime(list<Garment *> *clothes, list<Garment *> *clothesOrdered);

void printClothes(list<Garment *> *pList);

void sortClothesOnWashingMachines(list<Garment *> *clothes, list<WashingMachine *> *washingMachines);

void addGermentOnWashingMachines(Garment *garment, list<WashingMachine *> *washingMachines);

void printClothesInEachMachine(list<WashingMachine *> *washingMachines);

int main() {
  list<Garment*>* clothes = new list<Garment*>;
  list<WashingMachine*>* washingMachines = new list<WashingMachine*>;

  intializeClothesOrderedByTime(clothes);
  printClothes(clothes);

  sortClothesOnWashingMachines(clothes, washingMachines);

  printClothesInEachMachine(washingMachines);

  return 0;
}

void printClothesInEachMachine(list<WashingMachine *> *washingMachines) {
  printf("amount WM: %d\n",washingMachines->size());

  ofstream resultsFile("results.txt");

  for (auto itWM = washingMachines->begin(); itWM != washingMachines->end(); ++itWM){
    WashingMachine* washingMachine= *itWM ;
    cout << "WM number: " << washingMachine->getNumber() <<endl;

    list<Garment*>* clothes = washingMachine->getClothes();
    for(auto itClothes = clothes->begin(); itClothes != clothes->end(); ++itClothes){
      Garment* garment = *itClothes;

      char resultLine[10];
      sprintf(resultLine, "%d %d", garment->getNumber(), washingMachine->getNumber());

      resultsFile<<resultLine<< endl;
      cout<< resultLine <<endl;
    }

  }

  resultsFile.close();
}

void sortClothesOnWashingMachines(list<Garment *> *clothes, list<WashingMachine *> *washingMachines) {

  for (auto it = clothes->begin(); it != clothes->end(); ++it){
    Garment* germent= *it ;
    addGermentOnWashingMachines(germent,washingMachines);
  }

}

void addGermentOnWashingMachines(Garment *garment, list<WashingMachine *> *washingMachines) {
  auto it = washingMachines->begin();
  bool wasAdded = false;
  while(!wasAdded && it != washingMachines->end()) {
    WashingMachine* washingMachine= *it ;
    wasAdded = washingMachine->add(garment);
    it++;
  }

  if(!wasAdded)
    washingMachines->push_back(new WashingMachine(garment, washingMachines->size() + 1));

}

void printClothes(list<Garment *> *clothes) {
  cout<< "SIZE: " << clothes->size() << endl;
  for (auto it = clothes->begin(); it != clothes->end(); ++it){
    Garment* germent= *it ;
    cout<<"Number: " << germent->getNumber() << " Time: " << germent->getWashingTime() << endl;
    germent->printIncompatibilities();
  }
}

void intializeClothesOrderedByTime(list<Garment*> *clothesOrdered) {
  char line[CANT_MAX];
  list<Garment*>* clothes = new list<Garment*>;
  FILE *file = fopen("ej_2_data.txt", "r");

  while (fgets(line, sizeof(line), file)) {
    char type;
    int n1 = 0, n2 = 0;
    sscanf(line, "%c %d %d", &type, &n1, &n2);
    if(type == 'e')
      addIncompatibility(n1, n2, clothes);
    else
      addTimeTo(n1, n2, clothes);
  }
  fclose(file);

  copyOrderedByTime(clothes,clothesOrdered);
}

void copyOrderedByTime(list<Garment *> *clothes, list<Garment *> *clothesOrdered) {
  for (auto it = clothes->begin(); it != clothes->end(); ++it){
    Garment* germent= *it ;

    auto itOrdered = clothesOrdered->begin();
    bool shouldInsert = false;
    while(!shouldInsert && itOrdered != clothesOrdered->end()){
      Garment* orderedGerment = *itOrdered;
      shouldInsert = germent->getWashingTime() > orderedGerment->getWashingTime();
      itOrdered++;
    }
    if(itOrdered != clothesOrdered->end())
      clothesOrdered->insert(--itOrdered, germent);
    else
      clothesOrdered->push_back(germent);

  }

}

void addTimeTo(int n1, int n2, list<Garment*> *clothes) {
  Garment* germent = findGarmentNumber(clothes,n1);

  if(germent ==NULL) {
    //cout<< "CREATED " << n1 << endl;
    germent = new Garment(n1);
    clothes->push_back(germent);
  }
  //cout<< "ADDED TIME " << n2 << " TO "<< germent->getNumber()<<endl;
  germent->addWahingTime(n2);
}

void addIncompatibility(int n1, int n2, list<Garment*> *clothes) {
  Garment* germent = findGarmentNumber(clothes,n1);

  if(germent ==NULL) {
    //cout<< "CREATED " << n1 << endl;
    germent = new Garment(n1);
    clothes->push_back(germent);
  }
  germent->addIncompatibilityWith(n2);
}

bool isInClothes(list<Garment*> *clothes, int n1) {
  return findGarmentNumber(clothes,n1) != NULL;
}

Garment* findGarmentNumber(list<Garment*> *clothes, int n1) {
  for (auto it = clothes->begin(); it != clothes->end(); ++it){
    Garment* germent= *it ;
    if (germent->IsNumber(n1))
      return germent;
  }
  return NULL;
}
