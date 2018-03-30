#ifndef _MFSET_H_
#define _MFSET_H_
 
struct MFSET{
   int *vertex;
   int *parent;
};

void Merge(int,int,int,struct MFSET*);
void initial(int,int,struct MFSET *);
int find(int,struct MFSET*);
 
#endif