#include "Dungeon.hpp"

Dungeon::Dungeon() : front(nullptr), rear(nullptr), current(nullptr) {}

Dungeon::~Dungeon() {
    Room* currentRoom = front;
    while (currentRoom != nullptr) {
        Room* nextRoom = currentRoom->next;
        delete currentRoom;
        currentRoom = nextRoom;
    }
}

void Dungeon::Enqueue(Room* room) {
    if (front == nullptr) {
        front = room;
        rear = room;
        current = front;
    } else {
        rear->next = room;
        rear = room;
    }
}

void Dungeon::ProceedToNextRoom() {
        current = current->next;
}

Room* Dungeon::GetCurrentRoom(){
    return current;
}

