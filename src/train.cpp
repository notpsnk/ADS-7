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
    if (!first) {
        countOp = 0;
        return 0;
    }
    int length = 0;
    const Car* cur = first;
    bool x = false;

    do {
        if (!cur->light) x = true;
        cur = cur->next;
        ++length;
    } while (cur != first);

    if (x) {
        countOp = 2 * length;
    } else {
        countOp = length * (length + 1);
    }

    return length;
}

int Train::getOpCount() {
    return countOp;
}
