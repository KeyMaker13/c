#include <stdio.h>
#include <stdlib.h>

typedef enum {FALSE, TRUE} bool;

#define MAXV 100

typedef struct edgenode {
int y;
int weight;
struct edgenode *next;
} edgenodeT;

typedef struct {
edgenodeT *edges[MAXV+1];
int degree[MAXV+1];
int nvertices;
int nedges;
bool directed;
} graphT;

main(int argc, char *argv[])
{
/*
printf("%s %s %s",argv[0], argv[1],argv[2]);
char *in = "undirectedgraph1.txt";
*/
FILE *inFile = fopen(argv[1],"r");
//FILE *inFile = fopen("undirectedgraph1.txt","r");
//FILE *inFile = fopen("graphTest.txt","r");
graphT myg1, *myg2=NULL;
initialize_graph(&myg1, FALSE);
//read_graph(&myg1, FALSE);
read_graph(&myg1, FALSE, inFile);
printf("\nPrinting Graph 1\n");
print_graph(&myg1);
printf("\ncopy_graph_list\n");	
copy_graph_list(&myg1, &myg2);
printf("\nPrinting new Graph 2\n");
print_graph(&myg2);
free_graph(myg2);
fclose(inFile);
}

copy_graph_list(graphT *g, graphT **newg, FILE *in)
{
graphT *tmpG;
tmpG = (graphT *) malloc(sizeof(graphT));
	if(tmpG==NULL) {
		printf("no memory");
		exit(-1);
	}
initialize_graph(tmpG, FALSE);
read_graph(&newg,FALSE,in);

/*int i;
printf("debug here\n");
for (i=1; i<=MAXV; i++){
tmpG->degree[i] = g->degree[i];
}
for (i=1; i<=MAXV; i++){
tmpG->edges[i] = g->edges[i];
}
tmpG->nvertices = g->nvertices;
tmpG->nedges = g->nedges;
tmpG->directed = g->directed;
*newg = tmpG;
*/

}

print_graph(graphT *g)
{
edgenodeT *pe;
int i;
if(!g) return 0;
for(i=1; i<=g->nvertices; i++) {
printf("Node %d: ", i);
pe = g->edges[i];
while(pe){
// printf(" %d", pe->y);
printf(" %d(w=%d),", pe->y, pe->weight);
pe = pe->next;
}
printf("\n");
}
}

initialize_graph(graphT *g, bool directed)
{
int i;
g->nvertices = 0;
g->nedges = 0;
g->directed = directed;
for (i=1; i<=MAXV; i++)
g->edges[i] = NULL;
for (i=1; i<=MAXV; i++)
g->degree[i] = 0;
}

//read_graph(graphT *g, bool directed)
read_graph(graphT *g, bool directed, FILE *in)
{
int i;
int m;
int x, y, w;


fscanf(in,"%d %d",&(g->nvertices),&m);
for (i=1; i<=m; i++) {
fscanf(in,"%d %d %d",&x,&y, &w);
insert_edge(g, x, y, w, directed);
}
rewind(in);
}

insert_edge(graphT *g, int x, int y, int w, bool directed)
{
edgenodeT *pe;
pe = malloc(sizeof(edgenodeT));
pe->weight = w;
pe->y = y;
pe->next = g->edges[x];
g->edges[x] = pe;
g->degree[x]++;
if (directed == FALSE)
insert_edge(g, y, x, w, TRUE);
else
g->nedges ++;
}

free_graph(graphT *g)
{
edgenodeT *pe, *olde;
int i;
for(i=1; i<=g->nvertices; i++) {
pe = g->edges[i];
while(pe){
olde = pe;
pe = pe->next;
free(olde);
}
}
free(g);
}