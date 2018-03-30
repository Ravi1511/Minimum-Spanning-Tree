#include <stdio.h>
#include <stdlib.h>
#define L 4999999999
#include <ctype.h>
#include <math.h>
#include <time.h>
#include "graph_adt.h"
#include "prim.h"
#include "kruskal.h"


int main()
{

    int v,e;
    clock_t start1,start2,end1,end2;
    double cpu_time1,cpu_time2;
    v=readvertex();   //This function is reading number of vertex and storing in variable v
    float a[100][100];
    creategraph(a,v);   //This function is creating a graph instance of input file given
    e=readedge(a,v)/2;//This function is reading number of edges and storing in variable e

start1= clock();
prims(a,v);
end1=clock();

cpu_time1=((double)(end1-start1));
printf("\n\t CPU Time = %f seconds\n",cpu_time1 );
start2= clock();
Kruskal(v,e,a);
end2=clock();
cpu_time2=((double)(end2-start2));
printf("\n\t CPU Time = %f seconds\n",cpu_time2 );

return 0;
}
