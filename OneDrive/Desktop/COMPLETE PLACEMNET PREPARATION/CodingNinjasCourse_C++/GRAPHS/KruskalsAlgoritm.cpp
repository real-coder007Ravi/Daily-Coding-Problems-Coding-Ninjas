#include <iostream>
using namespace std;
#include <algorithm>
class Edge
{
public:
    int source;
    int destination;
    int weight;
};
bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}
int findParent(int v, int *parent)
{
    if (parent[v] == v)
        return v;
    return findParent(parent[v], parent);
}
void Kruskals(Edge *input, int n, int e)
{
    sort(input, input + e, compare);
    Edge *output = new Edge[n - 1];
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int count = 0;
    int i = 0;
    while (count != n - 1)
    {
        Edge current = input[i];
        int sourceParent = findParent(current.source, parent);
        int DestinationParent = findParent(current.destination, parent);
        if (sourceParent != DestinationParent)
        {
            output[count++] = current;
            parent[sourceParent] = DestinationParent;
        }
        i++;
    }
    cout << "Output oF Kruskals Algorithm" << endl;
    for (int i = 0; i < n - 1; i++)
    {
        if (output[i].source < output[i].destination)
        {
            cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
        }
        else
        {
            cout << output[i].destination << " " << output[i].source << " " << output[i].weight << endl;
            ;
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    Edge *input = new Edge[e];
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].destination = d;
        input[i].weight = w;
    }
    Kruskals(input, n, e);
}