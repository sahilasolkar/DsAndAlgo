
/*
AUTHOR : SAHIL.A 2107
PROGRAM: GRAPH USING ADJACENCY LIST. library
DATE CREATED: 1st DEC 2021
DATE MODIFIED: 9th DEC 2021
*/
// DS DEVELOPER


#ifndef _bst_H
#define _bst_H

struct graphNode {
  char *vertexVector;
  int **adjMatrix;
  int vertexCount;
};

typedef struct graphNode graphNd;

graphNd * creategraph(int count);
void readvertices(graphNd *newgraph, int count);
int locate(graphNd *newgraph, char a[]);
void readedges(graphNd *newgraph, int i, int j);
void displayMatrix(graphNd * newgraph);
int insertEdge(graphNd *newgraph, char srcName, char destName);
void BFS(graphNd *graph);
void DFS(graphNd *graph);

#endif