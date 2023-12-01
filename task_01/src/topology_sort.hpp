#pragma once

#include <string>
#include <vector>

/*
Taryan algotirthm is used there: https://ru.wikipedia.org/wiki/Топологическая_сортировка
In these interpreatation all vertices can be:
    1) "white" (if not visited)
    2) "black" (if visited)
    3) "gray"  (if gone in but not gone out)
*/

enum Colour
{
    WHITE,
    GRAY,
    BLACK,
};

class Vertex
{
    /* Struct of a vertex in a graph */

    public:
        Vertex(int number, std::vector<Vertex*> parents = std::vector<Vertex*>()): 
            _parents{parents}, _number{number} {}

        std::vector<Vertex*> GetParents() {return _parents; }
        std::vector<Vertex*> GetChildren() { return _children; }
        Colour GetColour() { return _colour; }
        int GetNumber() { return _number; }

        void AddChild(Vertex* children) { _children.push_back(children); }
        void ChangeColour(Colour new_colour) { this->_colour = new_colour; }
        void AddParent(Vertex* parent) { _parents.push_back(parent); }

    private:
        int _number;
        std::vector<Vertex*> _parents;
        std::vector<Vertex*> _children;
        Colour _colour = WHITE; // possbile colours are "white", "gray" and "'black"
};

class Graph
{
    public:
        Graph() = default;

        void AddRoot(Vertex* root); // add new root to the graph
        void AddElement(int number, std::vector<Vertex*> parents); // add new element to the graph
        std::vector<int> TopologySort(); // get sorted vertices
    private:
        std::vector<int> _TopologySort(Vertex* vertex); // recursion of topology sort for this vertex
        std::vector<Vertex*> _roots; // vector with all roots in graph
      //  size_t _cur_number = 1; // number of last added vertex
};

void AddEdge(Vertex* root, Vertex* child);