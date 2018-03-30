
#include "graph_adt.h"
#include <stdio.h>
#define L 499999
#include <ctype.h>
#include <math.h>


int readvertex()
{
    FILE *myFile;
    char r;
    int y;

    myFile = fopen("input_graph2.txt", "r"); //input file is read in myFile
    /*We are searching for \n and then will check for read
    digits in the given input file to find number of vertices*/
   while(r!=EOF)
    {

        r = fgetc(myFile);
        if(isdigit(r))
        {
            y++;

         //printf("1\n");
         r = fgetc(myFile);
         if(isdigit(r))
        {
            //printf("2\n");
            r=fgetc(myFile);
            if(isdigit(r))
            {

                //printf("3\n");
                r=fgetc(myFile);
                if(isdigit(r))
                {
                }

                    //printf("4\n");
            }



            }


         }





}
int v=sqrt(y);
    return v;
}


void creategraph(float a[100][100],int v)
{
    int i,j;
    FILE *myFile;
    myFile = fopen("input_graph2.txt", "r");//reading input file

    for (i=0; i<v; i++)
    {
        for(j=0;j<v;j++)

        fscanf(myFile,"%f",&a[i][j]);

        }
         //all digits are read and copied to matrix a[][]
        //..




    for (i=0; i<v; i++)
    {
        for(j=0;j<v;j++)
    {
        if(a[i][j]==-1)
          a[i][j]=L;
    }
    }

}


int readedge(float a[100][100],int v)
{
   /*If we remove 0 and -1 entres from our graph then all the remaining entires will be edges.Now
   since the given graph is undirected.total number of edges will be half of the value returned by this function.*/
   int i,j,x=0;
   for ( i = 0; i <v ; i++)
   {
    for ( j= 0; j <v; j++)
    {
     if(a[i][j]!=0&&a[i][j]!=L)
          x++;
    }
   }
 return x;
}
