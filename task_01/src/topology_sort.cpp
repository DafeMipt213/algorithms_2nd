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

void Graph::DFS(int v, std::vector<colors> &visited, std::stack<int> &stack){
    if (visited[v] == kGray)
        this->hasCycle = true;
    else if (visited[v] == kWhite){
        visited[v] = kGray;
        for (int i = 0; i < this->adjacency_matrix[v].size(); i++)
            DFS(this->adjacency_matrix[v][i], visited, stack);
        visited[v] = kBlack;
        stack.push(v);
    }
}


std::vector<int> Graph::TopologicalSort(){   
    std::stack<int> stack;
    std::vector<colors> visited(this->count_of_verticles, kWhite);
    for (int i = 0; i < this->count_of_verticles; i++)
        if (visited[i] == kWhite)
            DFS(i, visited, stack);
    std::vector<int> result;
    while (!stack.empty() && !this->hasCycle) {
        //std::cout << "top: " << stack.top() << " size: " << this->adjacency_matrix[stack.top()].size() << "\n";
        if (this->verticles[stack.top()]) result.push_back(stack.top());
        stack.pop();
    }
    return result;
}

void Graph::FillGraph(std::vector<std::vector<int>> vector){
    for (int i = 0; i < vector.size(); i++){
        this->AddEdge(vector[i][0], vector[i][1]);
    }
}

void Graph::addVerticle(int verticle){
    this->verticles[verticle] = true;
}