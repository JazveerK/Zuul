
#include <iostream>
#include <cstring>
#include <vector>

#include "Item.h"
#include "Room.h"

using namespace std;

//Exit methods keep nuking themself
//Item methods are all good 

//descritpion
Room::Room(char* newDescription){
strcpy(description, newDescription);

}

//Item functions
Item Room::getItem(char* itemTitle){
vector <Item> :: iterator ptr;
for(ptr = Items.begin(); ptr != Items.end(); ptr++){
if(strcmp(ptr->getDescription(), itemTitle) == 0){
return (*ptr);
    }
}
return 0; // why does it need this
    //keep getting error here
}

void Room::setItem(Item newItem){
Items.push_back(newItem);
}


void Room::removeItem(char* itemTitle){
vector <Item> :: iterator ptr2;
for(ptr2 = Items.begin(); ptr2 != Items.end(); ptr2++){
if(strcmp(ptr2->getDescription(), itemTitle) == 0){
Items.erase(ptr2);
break;
    }
}
} // NEED HELP

void Room :: printItems(){
    vector <Item> :: iterator ptr3;
    for(ptr3= Items.begin(); ptr3 != Items.end(); ptr3++){
    cout << ptr3->getDescription() << ",";
  }
  cout << endl;
}


void Room::ExitsAndItems(){ //Fixed
    cout << "Exits: " << endl;
  for(map<char*, Room*>::iterator ptr = exits.begin(); ptr != exits.end(); ptr++){
    cout << " " << ptr->first;
  }
  cout << endl;
  cout << "Items in this room: " << endl;
  printItems();
}

void Room::setExit(char* newDirection,Room* neighbor){
  exits[newDirection] = neighbor;
  } // NEED HELP


Room* Room::getExit(char* newDirection){
map<char*, Room*>:: iterator ptr;
for(ptr = (exits).begin(); ptr != exits.end(); ptr++){
if(strcmp(ptr->first, newDirection) == 0){
return ptr->second;
    }
}
    
return 0;
}

//descritpion
char* Room :: getRoomDescription(){
    return description;
}

//WIN CONDITION NOT WORKING
//Win condition
void Room::setWinID(int number){
  WinID = number;
}
//
int Room :: getWinID(){
  return WinID;
}

//Might need to come up with a enw way to do win condition
//maybe pass in a new a variable 
