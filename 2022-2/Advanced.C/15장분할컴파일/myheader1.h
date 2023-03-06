#ifndef __MYHEADER1_H__
#define __MYHEADER1_H__

#include <stdio.h>
#define SIZE 3

struct student {
    int id;
    double score;
};
extern struct student st[SIZE];

#endif