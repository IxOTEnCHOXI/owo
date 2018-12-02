#include "Player.h"
#include "Room.h"

Player::Player(string name){
    this->name = name;
}

void Player::addItem(Item *inItem){
    itemsInPlayer.push_back(*inItem);
}
string Player::longDescription(){
  string ret = this->name;
  ret += "\n Item list:\n";
  int j=0;
  for(vector<Item>::iterator i = itemsInPlayer.begin(); i != itemsInPlayer.end(); i++){
      j++;
      ret += "\t" + (std::to_string(j)) +  ": " + (*i).getShortDescription() + "\n";
  }
  return ret;
}

string Player::interact(Item inItem, int index, Room *currentRoom){
    string temp = "";
    if((inItem.getWeight()) > 10)
        temp = "Can't pickup " + inItem.getShortDescription() + " as it is too heavy!";
    else{
        temp = "You picked up " +inItem.getShortDescription() + ".";
        itemsInPlayer.push_back(inItem);
        currentRoom->removeItemFromRoom(index);
    }
    return temp;
}

int Player::removeItemFromPlayer(string item){
    for(int n = 0; n < itemsInPlayer.size(); n++){
          // compare inString with short description
          int tempFlag = item.compare( itemsInPlayer[n].getShortDescription());
              if (tempFlag == 0)
                  itemsInPlayer.erase(itemsInPlayer.begin()+ n);
          }
    return -1;
}

bool Player::isItemInInventory(string inString){
    int sizeItems = (itemsInPlayer.size());
    bool temp = false;
    if (itemsInPlayer.size() < 1){
        return false;
        }
    else
      for(int n = 0; n < itemsInPlayer.size(); n++){
            // compare inString with short description
            int tempFlag = inString.compare( itemsInPlayer[n].getShortDescription());
                if (tempFlag == 0)
                    temp = true;
            }

    return temp;
}

