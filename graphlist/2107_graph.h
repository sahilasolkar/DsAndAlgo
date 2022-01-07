
/*
AUTHOR : SAHIL.A
PROGRAM: GRAPH USING ADJACENCY LIST.
DATE CREATED: 1st DEC 2021
DATE MODIFIED: 9th DEC 2021
*/
// DS DEVELOPER


#ifndef _bst_H
#define _bst_H

struct linkNode
    {
        //float weight;
        struct vertexNode *destination;
        struct linkNode *nextLink;
    };
    struct vertexNode
    {
        char name[20];
        //float weight;
        short in_degree, out_degree; // in case of undirected graph, we need only degree
        short processed;//to be used in case of BFS and DFS
        struct vertexNode *nextVertex;
        struct linkNode *firstLink;
    };
    struct graphNode
    {
        struct vertexNode *firstVertex;
        int vertexCount;
    };

    
    typedef struct linkNode linkNd;
    typedef struct vertexNode vertexNd;
    typedef struct graphNode graphNd; // head for the graph

    //linkedlist 
    struct stack
    {

        struct stack_node *top;
        int countt;
    };

    typedef struct stack stackType;

    struct stack_node
    {
        vertexNd * data;
        struct stack_node *next;
    };
    typedef struct stack_node snode;

    vertexNd * locate(graphNd *graph, char name[]);
    int insertEdge(graphNd *graph, char src[], char dest[]);
    int insert(graphNd * graph, char name[]);
    graphNd * createGraph();
    int deleteVertex(graphNd *graph, char val[]);
    void dfs(graphNd *graph);
    void bfs(graphNd *graph);

#endif