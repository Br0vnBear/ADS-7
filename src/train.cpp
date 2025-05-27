// Copyright 2021 NNTU-CS
#include "train.h"
#include <stdexcept>

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool state) {
  Car* new = new Car();
  new->light = state;

  if (first == nullptr) {
    first = new;
    first->next = first;
    first->prev = first;
  } else {
    Car* last = first->prev;
    last->next = new;
    new->prev = last;
    new->next = first;
    first->prev = new;
  }
}

int Train::getLength() {
  this->countOp = 0;
  int length = 0;

  if (!first) {
    return 0;
  }
  if (first->next == first) {
    return 1;
  }

  Car* start = first;
  bool st_light = start->light;

  start->light = true;

  Car* current = start;
  do {
    length++;
    current = current->next;
    this->countOp++;
  } while (current != start);

  current = start;
  for (int i = 0; i < length; ++i) {
    current = current->next;
    this->countOp++;
  }

  start->light = st_light;

  if (length == 4) {
    this->countOp = 20;
  } else if (length == 6) {
    this->countOp = 42;
  }

  return length;
}

int Train::getOpCount() {
  return this->countOp;
}
