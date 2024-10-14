#ifndef MULTIPLYFUNCTIONS_H
#define MULTIPLYFUNCTIONS_H

void makeTable(int**& table, unsigned int rows, unsigned int cols);

void releaseTable(int**& table, unsigned int& rows, unsigned int& cols);

void printTable(const int*const* nums, unsigned int rows, unsigned int cols);

#endif
