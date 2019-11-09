#ifndef DEQUE_H
#define DEQUE_H

#include "Item.h"
#include "stdlib.h"

void QUEUEinit(int maxN);

void QUEUEpush(Item item);

void QUEUEput(Item item);

Item QUEUEget();

Item QUEUEpop();

void QUEUEdestroy();

#endif // DEQUE_H