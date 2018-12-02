#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Room.h"
#include "item.h"
#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL{
private:
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *z;
	Room *currentRoom;
    Player *user;
    std::vector<Room*> roomList;
	void createRooms();
	void printWelcome();
	bool processCommand(Command command);
	void printHelp();
    void goRoom(Command command);
    void createItems();
    void displayItems();

public:
	ZorkUL();
	void play();
    Room* getCurrentRoom();
	string go(string direction);
    void teleportRoom();
};

#endif /*ZORKUL_H_*/
