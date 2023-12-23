#include "Jonson.hpp"

bool fordBellman(int s, std::vector<std::vector<std::pair<int, int>>>& graph, std::vector<int>& d)
{
    for (int i = 0; i < graph.size(); ++i)
        d[i] = INF;
    d[s] = 0;
    for (size_t k = 0;  k < graph.size(); ++k){
        for(size_t j = 0; j < graph.size(); ++j){
            for(size_t i = 0; i < graph[j].size(); ++i)
                if(d[graph[j][i].first] > d[j] + graph[j][i].second)
                    d[graph[j][i].first] = d[j] + graph[j][i].second;
        }
    }

    for(size_t j = 0; j < graph.size(); ++j){
        for(size_t i = 0; i < graph[j].size(); ++i)
            if(d[graph[j][i].first] > d[j] + graph[j][i].second)
                return false;
    }
    return true;
}


void dijkstra(std::vector<std::vector<std::pair<int, int>>>& graph, int s, std::vector<int>& d){
    std::vector<int> colors(graph.size());
    for (int i = 0; i < graph.size(); ++i)
    {        
        d[i] = INF;
        colors[i] = 0;
    }
    d[s] = 0;
    for (size_t i = 0; i < graph.size(); ++i)
    {
        int v = -1;
        for (size_t j = 0; j < graph.size(); ++j)

                        // найдём вершину с минимальным расстоянием
            if (!colors[j] && (v == -1 || d[j] < d[v]))
                v = j;
        if (d[v] == INF)
            break;
        colors[v] = 1;
        for (size_t j = 0; j < graph[v].size(); ++j)    // произведём релаксацию по всем рёбрам, исходящим из v
            if (d[v] + graph[v][j].second < d[graph[v][j].first])
                d[graph[v][j].first] = d[v] + graph[v][j].second;
    }
}






std::vector<std::vector<int>> jonson(std::vector<std::vector<std::pair<int, int>>>& graph)
{
    std::vector<std::vector<int>> result(graph.size());

    std::vector<std::pair<int, int>> extra_vertex(graph.size());
    for(size_t i = 0; i < graph.size(); ++i)
    {
        extra_vertex[i].first = i;
        result[i].resize(graph.size(), INF);
    }
    graph.push_back(extra_vertex);
    std::vector<int> d(graph.size());

    if(fordBellman(graph.size(), graph, d) == 0){
        throw std::runtime_error("negative cycle");
        return {{}};
    }
    for(size_t i = 0; i < graph.size(); ++i){
        for(size_t j = 0; j < graph[i].size(); ++j){
            graph[i][j].second =  graph[i][j].second + d[i] - d[graph[i][j].first];
        }
    }
    graph.pop_back();
    std::vector<int> dijkstra_dist(graph.size());
    for(int i = 0; i < graph.size(); ++i){
        dijkstra(graph, i, dijkstra_dist);
        for(int j = 0; j < graph.size(); ++j)
        {
            result[i][j] = dijkstra_dist[j] + d[j] - d[i];
        }
    }
    return result;
}
