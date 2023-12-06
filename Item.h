//Item Header
#ifndef ITEM_H

#define ITEM_H

#include <cstring>

//problem with description
using namespace std;

class Item {
private:

char description[100]; //weird error here
    
    
public:
Item(char* newDescription);
~Item();
char* getDescription();

};



#endif
