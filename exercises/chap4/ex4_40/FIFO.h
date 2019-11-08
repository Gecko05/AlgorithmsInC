#ifndef FIFO_H
#define FIFO_H
#include "Item.h"

void QUEUEput(Item item);

Item QUEUEget();

void QUEUEinit(int maxN);

#endif // DEQUE_H