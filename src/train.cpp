// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train()
    : countOp(0), first(nullptr)
{}

void Train::addCar(bool light) {
    Car* car = new Car{light, nullptr, nullptr};
    if (!first) {
        car->next = car->prev = car;
        first = car;
    } else {
        Car* last = first->prev;
        last->next = car;
        car->prev = last;
        car->next = first;
        first->prev = car;
    }
}

int Train::getLength() {
    countOp = 0;
    if (!first) return 0;
    Car* cur = first;
    int len = 0;
    do {
        cur = cur->next;
        ++countOp;
        ++len;
    } while (cur != first);
    return len;
}

int Train::getOpCount() {
    return countOp;
}
