#include <iostream>

using namespace std;
#include "ZorkUL.h"


ZorkUL::ZorkUL(){
	createRooms();
}

void ZorkUL::createRooms(){

    a = new Room("A");
        a->addItem(new Item("Rock", 1, 10));
    b = new Room("B");
        b->addItem(new Item("A Lone Oak Tree", 100, 100));
        b->addItem(new Item("A Twig", 1, 44));
    c = new Room("C");
    d = new Room("D");
    e = new Room("E");
    f = new Room("F");
    g = new Room("G");
    h = new Room("H");
        h->addItem((new Item("A Glass Case", 100, 75)));
    i = new Room("I");
        i->addItem(new Item("A Locked Metal Box", 100, 80));
    j = new Room("J");
    k = new Room("K");
    l = new Room("L");
    z = new Room("Z");
        z->addItem(new Item("A Tiny Top Hat", 100, 80));

//             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
    j->setExits(i, NULL, NULL, NULL);
    k->setExits(d, NULL, NULL, NULL);
    l->setExits(e, NULL, NULL, NULL);
    z->setExits(NULL, NULL, NULL, NULL);

    roomList.push_back(a);
    roomList.push_back(b);
    roomList.push_back(c);
    roomList.push_back(d);
    roomList.push_back(e);
    roomList.push_back(f);
    roomList.push_back(g);
    roomList.push_back(h);
    roomList.push_back(i);
    roomList.push_back(j);
    roomList.push_back(k);
    roomList.push_back(l);
    roomList.push_back(z);
    currentRoom = a;
}

/** COMMANDS **/
void ZorkUL::goRoom(Command command){
    if (!command.hasSecondWord()){
        cout << "incomplete input"<< endl;
        return;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "underdefined input"<< endl;
    else{
        currentRoom = nextRoom;
    }
}

void ZorkUL::teleportRoom(){
    int randNumber = rand() % 13;
    Room *newRoom = roomList[randNumber];
    if (newRoom != currentRoom)
        currentRoom = newRoom;
}
Room* ZorkUL::getCurrentRoom(){
    return currentRoom;
}

string ZorkUL::go(string direction){
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return("direction null");
    else{
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}
