#include "topology_sort.hpp"
#include <iostream>

Graph::Graph(int count_of_verticles){
    this->count_of_verticles = count_of_verticles;
    this->adjacency_matrix = std::vector<std::vector<int>>(count_of_verticles, std::vector<int>());
    this->verticles = std::vector<bool>(count_of_verticles, false);
}

void Graph::AddEdge(int first_verticle, int second_verticle){
    this->verticles[first_verticle] = true;
    this->verticles[second_verticle] = true;
    adjacency_matrix[first_verticle].push_back(second_verticle);
}

void Graph::DFS(int vertex, std::vector<Colors> &visited, std::stack<int> &stack){
    if (visited[vertex] == kGray)
        this->has_cycle = true;
    else if (visited[vertex] == kWhite){
        visited[vertex] = kGray;
        for (int i = 0; i < this->adjacency_matrix[vertex].size(); i++)
            DFS(this->adjacency_matrix[vertex][i], visited, stack);
        visited[vertex] = kBlack;
        stack.push(vertex);
    }
}

std::vector<int> Graph::TopologicalSort(){   
    std::stack<int> stack;
    std::vector<Colors> visited(this->count_of_verticles, kWhite);
    for (int i = 0; i < this->count_of_verticles; i++)
        if (visited[i] == kWhite)
            DFS(i, visited, stack);
    std::vector<int> result;
    while (!stack.empty() && !this->has_cycle) {
        if (this->verticles[stack.top()]) result.push_back(stack.top());
        stack.pop();
    }
    return result;
}

void Graph::FillGraph(std::vector<std::vector<int>> graph){
    for (int i = 0; i < graph.size(); i++){
        this->AddEdge(graph[i][0], graph[i][1]);
    }
}

void Graph::AddVerticle(int verticle){
    this->verticles[verticle] = true;
}