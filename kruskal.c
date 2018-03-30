#include <stdlib.h>
#include <stdio.h>
#define L 499999
#include "pqueue.h"
#include "mfset.h"

/*
struct MFSET{
   int *vertex;
   int *parent;
};

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

void Merge(int,int,int,struct MFSET*);
void initial(int,int,struct MFSET *);
int find(int,struct MFSET*);

*/



void Kruskal(int v,int e,float a[100][100])
{
   //Variable Declaration
   int ncomp,q,z,nextcomp=0,ucomp,vcomp,i,j,k=0,m=2*e;
   float cost=0,u;
   float *b;
   int *c,*d;

   //Declaration of pointer to structures.
   b=(float*)malloc(2*e*sizeof(float));
   c=(int*)malloc(2*e*sizeof(int));
   d=(int*)malloc(2*e*sizeof(int));
   struct pqueue* edges=(struct pqueue*)malloc(sizeof(struct pqueue));
   struct pqueue* T=(struct pqueue*)malloc(sizeof(struct pqueue));
   struct MFSET *component=(struct MFSET*)malloc(sizeof(struct MFSET));;
   struct Edge F;//=(struct Edge)malloc(sizeof(struct Edge));
   struct Edge *E=(struct Edge*)malloc(sizeof(struct Edge));
   component->vertex=(struct MFSET*)malloc(v*sizeof(struct MFSET));
   component->parent=(struct MFSET*)malloc(v*sizeof(struct MFSET));;

   //Function Makenull() is initializing the structure of type pqueue.
   Makenull(T,e);
   Makenull(edges,e);

   /*ncomp is implying number of components in graph which is
   initially equal to number of vertices as all vertices are initally isolated.*/
   ncomp=v;

   //This loop is initializing all vertex and counting total number of vertices in nextcomp.
   for(i=0;i<v;i++)
   {
    initial(nextcomp,v,component); //Initializing vertex[] and parent[] members of struct component.
    nextcomp=nextcomp+1;
   }




 /*This loop is storing weight,source,destination vertex of and edge in matrix b[],c[],d[] respectively
 and since the graph is not directed..total number of edges will be half of which are stored in this matrices*/

 for (int i = 0; i <v ; i++)
 {
 	for (int j= 0; j <v; j++)
 	{
 		if((a[i][j]!=0&&a[i][j]!=L))
 		{
 		  b[k]=a[i][j];
 			c[k]=i;
 			d[k]=j;
 			k++;
 	}

 	}
 }


/*since the graph is undirected.we have duplicate edges stored in b[] matrix so
 we are removing duplicacy here*/
 for(i=0; i < m; i++)
   {
      for(j=i+1; j < m; )
      {
         if(b[j]==b[i]&&c[j]==d[i]&&d[j]==c[i])
         {
            for(k=j; k < m;k++)
            {
               b[k] = b[k+1];
               c[k] = c[k+1];
               d[k] = d[k+1];
            }
            m--;
         }
         else {
            j++;
         }
      }
   }


//All the edges are inserted one by one in priority queue
 for (i = 0; i < e; i++)
 {
 	float x=b[i];
 	int y=c[i];
 	int z=d[i];
 	insert(x,edges,y,z,e);//This function inserts edge in the priority queue.
 }


/*ncomp is initialized to total number of vertices in the graph initially
 here after selecting the edge to be added in MST.ncomp is decremented by one.*/
while(ncomp>1)
{

	F=Deletemin(edges); //Deleting Each Edge one by one and returning to structure F which is always root node.
  *E=F;
  u=E->w;
	q=E->x;
	z=E->y;


 //ucomp and vcomp will store parent of q and z vetex.
ucomp=find(q,component);
vcomp=find(z,component);

 //If both parents are not equal,it means that that belong to different components
  if(ucomp!=vcomp)
  {
  	Merge(ucomp,vcomp,v,component); //Merging two components of graph
  	ncomp=ncomp-1;
  	insert(u,T,q,z,e);
    cost=u+cost;
    //printf("%f\n",cost);
  }
 }

//Printing output
printf("\n\n\tKruskals Output\n\n");
printf("\t********||||||||*********\n");
for(i=1;i<v;i++)
	printf("\tEdge %d-->(%d,%d)\tCost=%.2f \n",i,T->edge[i].x,T->edge[i].y,T->edge[i].w);
  printf("\t________________________\n" );
  printf("\n\tTotal Cost = %.2f\n",cost );
  printf("\t________________________\n" );


}

