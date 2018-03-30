#include "pqueue.h"
#include <stdlib.h>
#include <stdio.h>







//This function is initializing structure pqueue
void Makenull(struct pqueue* A,int e)
{
	A->last=0;
  //Allocating memory for structure edge to implement priority queue as binary heap.
  A->edge=(struct Edge*)malloc(e*sizeof(struct Edge));
}


//This function is inserting edge to a priority queue along with its source and dest vertex.
void insert(float x,struct pqueue* A,int p,int q,int e)
{
	int i;
	struct Edge temp;
	if(A->last>e)
		printf("Priority queue is full\n");
	else
	{
		A->last=A->last+1;
		A->edge[A->last].w=x;
		A->edge[A->last].x=p;
		A->edge[A->last].y=q;
		i=A->last;

    /*Comparing the weight of edge with weight of its parents weight to ensure
    that the property of min heap is satisfied and node with less value is at root.*/
		while(i>1&&(A->edge[i].w<A->edge[i/2].w))
		{
			temp=A->edge[i];
			A->edge[i]=A->edge[i/2];
			A->edge[i/2]=temp;
			i=i/2;
    }

}
}


//Deleting the root node from the implemented binary min heap one at a time.
struct Edge Deletemin(struct pqueue *A)
{
	int i,j;
	struct Edge temp;
	struct Edge min;

  if(A->last==0) //If no edges in the binary heap then priority queue is empty.
	 	printf("Priority queue is empty\n");
	else
	{
		min=A->edge[1]; //storing root node in structure min which is of type struct Edge.
		A->edge[1]=A->edge[A->last]; //replacing root node with last node.
		A->last=A->last-1; //reducing the size of heap
		i=1;

    //looking into loop until there are atleast two entries
		while(i<=(A->last/2))
		{
      //comparing both the children of node and if only two entries then set A->last=2*i.
			if((A->edge[2*i].w<A->edge[2*i+1].w)||(2*i==A->last))
				j=2*i;
			else
				j=2*i+1;

      //Comparing root node with smallest of its both children found in above step.
			if(A->edge[i].w>A->edge[j].w)
			{
				temp=A->edge[i];
				A->edge[i]=A->edge[j];
				A->edge[j]=temp;
				i=j;
			}
			else
				return min;

		}

		return min;//returning root node
}

}
