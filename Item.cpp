
#include <iostream>
#include <cstring>
#include <vector>

#include "Item.h"

using namespace std;
//Description
Item::Item(char* newDescription){
strcpy(description, newDescription);

}
//Getting the Item's name
char* Item::getDescription(){
    return description;
}

Item::~Item(){

} //Destructor
