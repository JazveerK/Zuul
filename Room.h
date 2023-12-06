//Room Header
#ifndef ROOM_H
#define ROOM_H

#include <cstring>
#include <vector>
#include <map>

#include "Item.h"

using namespace std;
// Class for Rooms
class Room {
private:
char description[100];

map<char*, Room*> exits;
    

vector <Item> Items;
    int WinID; //default member initializer for non-static data member is a C++11 extension [-Wc++11-extensions]
    
    
public:
    
//Constructor
Room(char* newDescription);
~Room();
    
//Exit functions
Room* getExit(char* newDirection);
void setExit(char* newDirection, Room* neighbor);
void ExitsAndItems();
    
//  Item fucntions
Item getItem(char* itemTitle);
    
    void removeItem(char* itemTitle);
        
    void printItems();
    
void setWinID(int number); //not working 
    
void setItem(Item newItem);
    

    
//Win ID method
int getWinID(); // use an iterator in the wincondition function instead
    
//Getting the Room name
char* getRoomDescription();
};

#endif
