#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> dijkstra(int n, int origen, const vector<vector<pair<int,int>>>& grafo) {
    vector<int> distancias(n, INF);
    distancias[origen] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,origen});

    while(!pq.empty()) {
        int distancias_actual = pq.top().first;
        int nodo_actual = pq.top().second;
        pq.pop();

        if(distancias_actual > distancias[nodo_actual]) continue;

        for(const auto& vecino : grafo[nodo_actual]) {
            int nodo_vecino = vecino.first;
            int peso_arista = vecino.second;

            int nueva_distancia = distancias_actual + peso_arista;

            if (nueva_distancia < distancias[nodo_vecino]) {
                distancias[nodo_vecino] = nueva_distancia;
                pq.push({nueva_distancia, nodo_vecino});
            }
        }
    }

    return distancias;
}

int main()
{
    int n = 5;

    vector<vector<pair<int,int>>> grafo(n);
    /*n cantidad de datos*/

    grafo[0].push_back({1,10});
    grafo[0].push_back({2,5});
    grafo[1].push_back({2,2});
    grafo[1].push_back({3,1});
    grafo[2].push_back({1,3});
    grafo[2].push_back({3,9});
    grafo[3].push_back({4,4});
    grafo[3].push_back({4,2});
    grafo[4].push_back({0,7});
    grafo[4].push_back({3,6});

    int origen = 0;
    vector<int> distancias = dijkstra(n,origen,grafo);

    cout << "Distancia desde el nodo " << origen << " : " <<endl;
    for (int i=0;i<n;i++) {
        if(distancias[i]==INF)
            cout << "Nodo " << i << ": Inalcanzable" << endl;
        else
            cout << "Nodo " << i << ": " << distancias[i] << endl;
    }

    return 0;
}