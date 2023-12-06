/*
 Jazveer Kaler
 Zuul: A text-based adventure game
 11/28/23
 
 Note: The actual game comes from my Java project
 Credit to Tejas, Levi for help with header files 

 Win Condition: Get the key from the Warden's Office and get to the exit.

 Items: 
Key (Warden's Office)
Bar of Soap (Showers
Spoon (Kitchen) 
Book (Start of Game) 
Basketball (Basketball Courts)

Have to type in command and then item/direction
Examples:
MOVE South
GET Key
DROP Book
 
 */

#include <iostream>
#include <cstring>
#include <vector>
#include "Item.h"
#include "Room.h"

using namespace std;

// Initializing functions
void help();
void get(Room* &currentRoom, vector<Item> &inventory);
void drop(Room* &currentRoom, vector<Item> &inventory);
void move(Room* &currentRoom);
bool winCon(Room* &currentRoom, vector<Item> &inventory);
void printInventory(vector<Item> &inventory);

int main() {
    // Initializing variables
    vector<Room*> Rooms;
    vector<Room*>::iterator ptr;
    vector<Item> inventory;
    bool running= true;
    char userInput[100];

    //Adventure
    cout << "Welcome to Adventure!" << endl;
    cout << "Adventure is a new, incredibly boring adventure game." << endl;
    cout << "In this adventure game, you are a prisoner trying to escape" << endl;

    // Directions
    char* North = (char*)("North");
    char* East = (char*)("East");
    char* South = (char*)("South");
    char* West = (char*)("West");

    // Rooms & Exits
    // Need to code exits after rooms - FIXED
    map<char*, Room*> initialMap;

    //Prisons
    char prisonA[100] = "Another day in the same old cell...";
    Room* PrisonA = new Room(prisonA);
    char prisonB[100] = "In another cell. Can't even really tell them apart.";
    Room* PrisonB = new Room(prisonB);


    //Hallway
    char hallway[100] = "A hallway...";
    Room* Hallway = new Room(hallway);
  


    char infirmary[100] = "in the infirmary. Nothing but bad memories here.";
    Room* Infirmary = new Room(infirmary);
    

    
    char showers[100] = "Showers. Let's get of here";
    Room* Showers = new Room(showers);
    
 

    char laundry[100] = "The laundry room. I should probably pick up some clean clothes.";
    Room* Laundry = new Room(laundry);
    


    char cafeteria[100] = "The cafeteria. Hate the food here.";
    Room* Cafeteria = new Room(cafeteria);
    


    char kitchen[100] = "In the kitchen. There must be something I can use here";
    Room* Kitchen = new Room(kitchen);

    char courtyard[100] = "In the courtyard. Some fresh air";
    Room* Courtyard = new Room(courtyard);

    char basketballCourts[100] = "on the basketball courts.";
    Room* BasketballCourts = new Room(basketballCourts);
    

    char charExit[100] = "The exit. Just need a key to get out.";
    Room* Exit = new Room(charExit);


    char security[100] = "In security. Never thought I'd be here";
    Room* Security = new Room(security);


    char wardenOffice[100] = "In the Warden's office. Must be some keys here.";
    Room* WardenOffice = new Room(wardenOffice);


    char supplyCloset[100] = "In a tiny little closet";
    Room* SupplyCloset = new Room(supplyCloset);


    char visitingRoom[100] = "in the visiting room. No visitors today";
    Room* VisitingRoom = new Room(visitingRoom);
    
    //Exits
    //Double check to make sure I'm not missing anythign
    PrisonA->setExit(West, PrisonB);
    
    PrisonB->setExit(West, Hallway);
    PrisonB->setExit(East, PrisonA);
    
    Hallway->setExit(West, Showers);
    Hallway->setExit(East, PrisonB);
    Hallway->setExit(North, Infirmary);
    Hallway->setExit(South, Cafeteria);
    
    Infirmary->setExit(South, Hallway);
    
    Showers->setExit(East, Hallway);
    Showers->setExit(West, Laundry);
    
    Laundry->setExit(East, Showers);
    
    Cafeteria->setExit(North, Hallway);
    Cafeteria->setExit(East, Kitchen);
    Cafeteria->setExit(South, Security);
    Cafeteria->setExit(West, Courtyard);
    
    Kitchen->setExit(West, Cafeteria);
    
    Courtyard->setExit(East, Cafeteria);
    Courtyard->setExit(West, BasketballCourts);
    Courtyard->setExit(South, VisitingRoom);
    
    BasketballCourts->setExit(East, Courtyard);
    
    BasketballCourts->setExit(West, Exit);
    
    Security->setExit(North, Cafeteria);
    Security->setExit(East, WardenOffice);
    Security->setExit(West, SupplyCloset);
    
    Exit->setExit(East, BasketballCourts);
    
    WardenOffice->setExit(West, Security);
    
    SupplyCloset->setExit(East, Security);
    SupplyCloset->setExit(East, Security);
    
    
    
    //Items
    char book[100] = "Book";
    Item* Book = new Item(book);
    PrisonA->setItem(*Book);
    
    char spoon[100] = "Spoon";
    Item* Spoon = new Item(spoon);
    Kitchen->setItem(*Spoon);
    
    char key[100] = "Key";
    Item* Key = new Item(key);
    WardenOffice->setItem(*Key);
    
    char basketball[100] = "Basketball";
    Item* Basketball = new Item(basketball);
    BasketballCourts->setItem(*Basketball);
    
    char barOfSoap[100] = "Bar of Soap";
    Item* BarOfSoap = new Item(barOfSoap);
    Showers->setItem(*BarOfSoap);
    
    //Win Conditions
    //For some reason header file keeps getting an error
    //default member initializer for non-static data member is a C++11 extension [-Wc++11-extensions]
    //Try setting everything else to 0 manually - WORKED
    PrisonA->setWinID(0);
    PrisonB->setWinID(0);
    Hallway->setWinID(0);
    Infirmary->setWinID(0);
    Showers->setWinID(0);
    Laundry->setWinID(0);
    Cafeteria->setWinID(0);
    Kitchen->setWinID(0);
    Courtyard->setWinID(0);
    BasketballCourts->setWinID(0);
    Security->setWinID(0);
    WardenOffice->setWinID(0);
    SupplyCloset->setWinID(0);
    Exit->setWinID(1);
    
    //PrisonA is the start room
    Room* currentRoom = PrisonA;

    //Prints out some info
    cout << currentRoom->getRoomDescription() << endl;
    currentRoom->ExitsAndItems();
    cout << endl;
    cout << "Let's get out. Your commands are HELP, MOVE, GET, DROP, QUIT, and INVENTORY. " << endl;
    cout << "Enter a command: " << endl;

    // The actual game
    while (running == true) {
        //takes in command
        cin >> userInput;

        //Runs command
        
        if (strcmp(userInput, "HELP") == 0) {
            help();
        }

        else if (strcmp(userInput, "MOVE") == 0) {
            move(currentRoom);
            if (checkComplete(currentRoom, inventory) == true) {
                cout << "Finally out." << endl;
                running = false;
                exit(0);
            }
        }

        else if (strcmp(userInput, "GET") == 0) {
            get(currentRoom, inventory);
        }

        else if (strcmp(userInput, "DROP") == 0) {
            drop(currentRoom, inventory);
        }

        else if (strcmp(userInput, "QUIT") == 0) {
            cout << "Thanks for playing." << endl;
            running= false;
            exit(0);
        }

        else if (strcmp(userInput, "INVENTORY") == 0) {
            printInventory(inventory);
        }
    }
    
    
    return 0;
}

//help function
void help() {
    cout << "Your commands are HELP, MOVE, GET, DROP, and INVENTORY." << endl;
    cout << "Your goal is to escape the prison. You need to find the exit and a key." << endl;
}

//move function
void move(Room* &currentRoom) {
    char direction[100];
    
    //info for current location
    cout << currentRoom->getRoomDescription() << endl;
    currentRoom->ExitsAndItems();
    
    cout << "Which direction do you want to go in?" << endl;
    cout << "Type in MOVE... North, South, East, or West" << endl;
    cin >> direction;
    
    //moves room
    Room* nextRoom = currentRoom->getExit(direction);
    currentRoom = nextRoom;
    cout << currentRoom->getRoomDescription() << endl;
    currentRoom->ExitsAndItems();
}

//get fucntion
void get(Room* &currentRoom, vector<Item> &inventory) {
    char pick[100];
    cout << "Here are the items in the room: " << endl;

    currentRoom->printItems();
    cout << "Which item do you want to pick up?" << endl;
  
    cin >> pick;
    
    //picks the item up
    Item RoomItem = currentRoom->getItem(pick);
    inventory.push_back(RoomItem);
    currentRoom->removeItem(pick);
    cout << "You have picked up: " << pick << endl;
}

// drop function
void drop(Room* &currentRoom, vector<Item> &inventory) {
    vector<Item>::iterator ptr4;
    char drop[100];
    cout << "Here are the items in your inventory: " << endl;
    printInventory(inventory);
    cout << "Which item do you want to drop?" << endl;
    cin >> drop;
    
    //Levi helped me with this
    for(ptr4 = inventory.begin(); ptr4 != inventory.end(); ptr4++){
       if(strcmp(ptr4->getDescription(), drop) == 0){
           char tempDescription[100] = " ";
           
           Item tempItem(tempDescription);
           tempItem = (*ptr4);
          inventory.erase(ptr4);
          currentRoom->setItem(tempItem);
          cout << "Dropped: " << drop << endl;
          break;
       }
        }
}

// Prints inventory
void printInventory(vector<Item> &inventory) {
    vector<Item>::iterator ptr;
    for(ptr = inventory.begin(); ptr != inventory.end(); ptr++){
        cout << ptr->getDescription() << ",";;
    }
    cout << endl;
}
//Checks to see if you've collected all the items and you're in the dormitory (WinID is 8, not 0)
bool winCon(Room* &currentRoom, vector<Item> &inventory){
    vector<Item>::iterator ptrx;
    char winCondition[8] = "Key";
    bool itemWC = false;
    for(ptrx = inventory.begin(); ptrx != inventory.end(); ptrx++){
       if(strcmp(ptrx->getDescription(), winCondition) == 0){
           itemWC = true;
          break;
       }
        }
    
  if(itemWC == true && currentRoom->getWinID() != 0){
    return true;
  }
  return false;
}
