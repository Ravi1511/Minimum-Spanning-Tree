#ifndef _PQUEUE_H_
#define _PQUEUE_H_
 
struct pqueue
{

	int last;
	struct Edge *edge;
};


struct Edge
{
    int x, y;
    float w;
};

void Makenull(struct pqueue*,int );
void insert(float,struct pqueue *,int,int,int);
struct Edge Deletemin(struct pqueue * );

 
#endif