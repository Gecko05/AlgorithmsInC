#ifndef DEQUE_H
#define DEQUE_H
#include <stdio.h>
#include <stdlib.h>
#include "Item.h"

void QUEUEpush(Item item);

void QUEUEput(Item item);

Item QUEUEget();

Item QUEUEpop();

void QUEUEinit();

void QUEUEdestroy();

int QUEUEempty();

// Prints the contents of the QUEUE
void QUEUEprint();

#endif // DEQUE_H