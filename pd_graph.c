#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NODES 100
#define NULL_NAME ""

struct graph_node
{
	char name[20];
	int count;
	int arcptr;
	int nextnode;
}

struct arc
{
	int nodeptr;
	int nextarc;
};

static struct graph_node graphnodes[MAX_NODES];
static struct arc arcs[MAX_NODES];
static int availarc;
static int numnodes = 0;

int find(int n)
{
	//Hash function to find the node/ create one if it doesn't exist.
}

void join(int a, int b)
{
	//function to join two nodes.
}

void freearc(int n)
{
	//function to free the arcs.
}

int main()
{
	int output = 0, nextout = 0;
	int p = 0, q = 0, r = 0, s = 0, t = 0;
	char node1[20] = { '\0' };
	char node2[20] = { '\0' };

	for(p = 0; p < MAX_NODES; p++)
	{
		strcpy(graphnodes[p].name, NULL_NAME);
	}

	for(p = 0; p < MAX_NODES - 1; p++)
	{
		arcs[p].nextarc = p + 1;
	}
	arcs[MAX_NODES - 1].nextarc = -1;

	//creating the graph
	availarc = 0;
	while(scanf("%s %s", node1, node2) != EOF)
	{
		p = find(node1);
		q = find(node2);
		join(p, q);
	}

	//traversing the graph
	output = -1;
	for(p = 0; p < MAX_NODES; p++)
	{
		if(strcmp(graphnodes[p].name, NULL_NAME) && graphnodes[p].count == 0)
		{
			graphnodes[p].nextnode = output;
			output = p;
		}
	}

	while(output != -1)
	{
		nextout = -1;
		p = output;
		while(p != -1)
		{
			printf("%s ", graphnodes[p].name);
			q = graphnodes[p].arcptr;
			while(q != -1)
			{
				r = arcs[q].nextarc;
				s = arcs[q].nodeptr;
				--graphnodes[s].count;
				if(graphnodes[s].count == 0)
				{
					graphnodes[s].nextnode = nextout;
					nextout = s;
				}
				freearc(q);
				q = r;
			}

			strcpy(graphnodes[p].name, NULL_NAME);
			--numnodes;
			p = graphnodes[p].nextnode;
		}

		output = nextout;
	}
	if(numnodes != 0)
	{
		printf("Error! Cyclic dependency detected.\n");
	}

	return EXIT_SUCCESS;
}