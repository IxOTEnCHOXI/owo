#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"

using namespace std;
using std::vector;

class Room{
private:
	string description;
	map<string, Room*> exits;
    vector <Item> itemsInRoom;


public:
    int numberOfItems();
	Room(string description);
	void setExits(Room *north, Room *east, Room *south, Room *west);
	string shortDescription();
	string longDescription();
	Room* nextRoom(string direction);
    void addItem(Item *inItem);
    string displayItem();
    int isItemInRoom(string inString);
    Item returnItem(int index);
    int removeItemFromRoom(int location);
    string exitString();
};

#endif
