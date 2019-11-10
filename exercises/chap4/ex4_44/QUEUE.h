#ifndef FIFO_H
#define FIFO_H
#include "Item.h"

void QUEUEinsert(Item item, int pos);

Item QUEUEdelete(int pos);

void QUEUEinit(int maxN);

void QUEUEdestroy();

#endif // DEQUE_H