#ifndef STRUCTURE_H
#define STRUCTURE_H

typedef struct
{
    char symbol[10];
    int shares;
    float purchasePrice;
    float currentPrice;
} Stock;

typedef struct
{
    Stock stocks[100];
    int count;
} Portfolio;

#endif