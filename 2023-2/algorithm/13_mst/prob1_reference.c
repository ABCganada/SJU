//13-1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge {
    int weight;
    int vertex1, vertex2;
}Edge;
typedef struct IncidentEdge {
    int edge_num;
    struct IncidentEdge* next;
}IncidentEdge;
typedef struct Vertex {
    int name;
    int check;
    struct IncidentEdge* incidentEdge;
}Vertex;
typedef struct Graph {
    struct Edge edge[1000];
    struct Vertex vertex[100];
}Graph;

IncidentEdge* getnode(int n);
void enqueue(int* queue, int* rear, int n, int i); // rear
int dequeue(int* queue, int* front, int n); //front 
int isEmpty(int front, int rear);
int isFull(int front, int rear, int n);
int checkQueue(int front, int rear, int* queue, int n, int check);
int Prim_JarnikMST(int n, Graph * graph);

int main()
{
    int n, m, distance;
    int edge_cnt = 0, vertex_cnt = 0;
    int vertex11, vertex22, vertexweight, vertex_oppo;
    Graph graph;
    IncidentEdge* p, * pt, * q, * qt;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        graph.vertex[i].incidentEdge = NULL;
        graph.vertex[i].check = 0;
    }
    for (int i = 0; i < m; i++, edge_cnt++)
    {
        scanf("%d %d %d", &vertex11, &vertex22, &vertexweight);
        graph.edge[edge_cnt].vertex1 = vertex11;
        graph.edge[edge_cnt].vertex2 = vertex22;
        graph.edge[edge_cnt].weight = vertexweight;
        graph.vertex[vertex11 - 1].name = vertex11;
        graph.vertex[vertex22 - 1].name = vertex22;
        p = graph.vertex[vertex11 - 1].incidentEdge;
        q = graph.vertex[vertex22 - 1].incidentEdge;
        if (p == NULL)
        {
            graph.vertex[vertex11 - 1].incidentEdge = getnode(-1);
            graph.vertex[vertex11 - 1].incidentEdge->next = getnode(edge_cnt);
        }
        else
        {
            pt = p->next;
            while (pt != NULL)
            {
                vertex_oppo = graph.edge[pt->edge_num].weight;
                if (vertex_oppo > vertexweight)
                break;
                p = pt;
                pt = pt->next;
            }
            p->next = getnode(edge_cnt);
            p->next->next = pt;
        }

        if (q == NULL)
        {
            graph.vertex[vertex22 - 1].incidentEdge = getnode(-1);
            graph.vertex[vertex22 - 1].incidentEdge->next = getnode(edge_cnt);
        }
        else
        {
            qt = q->next;
            while (qt != NULL)
            {
                vertex_oppo = graph.edge[qt->edge_num].weight;
                if (vertex_oppo > vertexweight)
                break;
                q = qt;
                qt = qt->next;
            }
            q->next = getnode(edge_cnt);
            q->next->next = qt;
        }
    }
    distance = Prim_JarnikMST(n, &graph);
    printf("\n%d", distance);

    return 0;
}
IncidentEdge* getnode(int n)
{
    IncidentEdge* newnode = (IncidentEdge*)malloc(sizeof(IncidentEdge));
    newnode->next = NULL;
    newnode->edge_num = n;
    return newnode;
}
void enqueue(int* queue, int* rear, int n, int i) // rear
{
    queue[*rear] = i;
    *rear = (*rear + 1) % n;
}
int dequeue(int* queue, int* front, int n) //front 
{
    int sol = queue[*front];
    *front = (*front + 1) % n;
    return sol;
}
int isEmpty(int front, int rear)
{
    if (front == rear)
        return 1;
    else
        return 0;
}
int isFull(int front, int rear,int n)
{
    if (front == (rear + 1) % n)
        return 1;
    else return 0;
}
int checkQueue(int front, int rear, int* queue, int n, int check)
{
    for (int i = front; i != rear; i = (i + 1) % n)
        if (check == queue[i])
            return i;
    return -1;
}
int Prim_JarnikMST(int n, Graph* graph)
{
    int distance = 0;
    int vertex0, min_weight, tmp_weight, min_vertex;
    int* queue1 = (int*)malloc(sizeof(int) * n); // 현재 추가된 vertex
    IncidentEdge* p = NULL;
    int front1 = 0, rear1 = 0;
    //for (int i = 0; i < n; i++)
    //   queue1[i] = -1;
    enqueue(queue1, &rear1 , n , 1);
    printf(" %d", 1);
    while (!isEmpty(front1, rear1)) {
        min_weight = -1;
        min_vertex = -1;
        for (int i = front1; i != rear1; i = (i + 1) % n) {
            p = graph->vertex[queue1[i]-1].incidentEdge;
            p = p->next;
            while (p != NULL) {
                tmp_weight = graph->edge[p->edge_num].weight;
                vertex0 = graph->edge[p->edge_num].vertex1;
                if(vertex0 == queue1[i])
                vertex0 = graph->edge[p->edge_num].vertex2;
                if ((min_weight == -1 || tmp_weight < min_weight) && checkQueue(front1, rear1, queue1, n, vertex0) == -1)
                {
                min_weight = tmp_weight;
                min_vertex = vertex0;
                break;
                }
                p = p->next;
            }
        }
        printf(" %d", min_vertex);
        enqueue(queue1, &rear1, n, min_vertex);
        distance += min_weight;
    }
    return distance;
}