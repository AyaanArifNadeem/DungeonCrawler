#pragma once
#include "Room.hpp"

class Dungeon {
private:
    Room* front; 
    Room* rear;  
    Room* current;

public:
    Dungeon();
    ~Dungeon();

    void Enqueue(Room* room);
    void ProceedToNextRoom();
    Room* GetCurrentRoom();
};