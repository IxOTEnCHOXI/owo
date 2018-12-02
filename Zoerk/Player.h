#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include <string>
#include "item.h"
#include "Room.h"

using namespace std;
using std::vector;

class Player{
private:
    string name;
    vector <Item> itemsInPlayer;
    int j;

public:
    Player(string name);
    string longDescription();
    string interact(Item inItem, int index, Room *currentRoom);
    void addItem(Item *inItem);
    bool isItemInInventory(string inString);
    int removeItemFromPlayer(string item);
};

#endif
