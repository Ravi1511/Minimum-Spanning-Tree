



struct MFSET{
   int *vertex;
   int *parent;
};




//Merging two components of graph
void Merge(int x, int y,int v, struct MFSET *component)
{
    int i;
    for(i=0;i<v;i++)
    {
      //for all vertices whose parent is x..set it to y.
      if(component->parent[i]==x)
      component->parent[i] = y;

    }
}


//Finding parent of the node v.
int find(int v,struct MFSET *component)
{
     return component->parent[v];
}


//Initialzing each vertex and its parent in the graph
void initial(int ncomp,int v,struct MFSET *component)
{
    int i=ncomp;
  component->vertex[i]=i;
  component->parent[i]=i;
}


