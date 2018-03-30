#include <stdio.h>
#define L 499999
#include "prim.h"





void prims(float c[100][100],int v)
{
     //In our graph.vertexes are numbered as V={0,1,2....n-1}
     float LOWCOST[v];  //this matrix is storing weight of edges.
     int CLOSEST[v];  //this matrix is storing vertex number from which the edge is closest.
     int i,j,k,l=1;
     float min;
     float tcost=0.00;   //float variable is storing total cost of MST.

      /*we are looking for weight of edges as a distance from source vertex to other vertexes and choosed
     this source vertex in closest to all vertexes initially.*/
     /*Let U={0} and U-V={set of all other vertexes} where U stores vertexes which are a part of MST.*/
     for(i=0;i<v;i++)
     {
      LOWCOST[i]=c[0][i];
      CLOSEST[i]=0;
     }

    //starting from vertex number 1.we are looking for the vertex which is at shortest distance from vertex in set U
    printf("\n\tPrims Output\n\n");
    printf("\t********||||||||*********\n");
     for(i=1;i<v;i++)
     {
     min=LOWCOST[1];  //storing distance(weight) of vertex numbered 1 and storing it in variable min
     k=1;

     //checking for shortest distance and storing it in min and choosing closest as index of the choosed weight.
     for(j=2;j<v;j++)
     {

      if(LOWCOST[j]<min)
      {
        min=LOWCOST[j];
        k=j;

      }

     }
     tcost+=LOWCOST[k];
    printf("\tEdge %d-->(%d,%d)\tCost=%.2f\n",l,k,CLOSEST[k],LOWCOST[k]); //printing both the vertexes of the choosed edge.
    l++;
    LOWCOST[k]=L+1;

    //Finding minimum of adjacent short distance from the choosed vertices in U
      for(j=1;j<v;j++)
      {
        if(c[k][j]<LOWCOST[j]&&LOWCOST[j]<L+1)
        {
            LOWCOST[j]=c[k][j];
            CLOSEST[j]=k;}
         }
      }

printf("\t___________________________\n");
printf("\n\t  Total Cost = %.2f\n\n",tcost);
printf("\t___________________________\n");
}
