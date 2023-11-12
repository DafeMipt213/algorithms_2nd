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
        Vertex(size_t number, Vertex* parent = nullptr): 
            _parent{parent}, _number{number} {}

        Vertex* get_parent() {return _parent; };
        std::vector<Vertex*> get_children() { return _children; };

        void add_child(Vertex* children) { _children.push_back(children); };
        void change_colour(Colour new_colour) { this->_colour = new_colour; };

    private:
        size_t _number;
        Vertex* _parent = nullptr;
        std::vector<Vertex*> _children;
        Colour _colour = WHITE; // possbile colours are "white", "gray" and "'black"
};

class Graph
{
    public:
        Graph(bool root=false){
            if (root)
                this->_roots.push_back(new Vertex(this->_cur_number++));
        }

        void add_element(Vertex* parent=nullptr); // add new element to the graph
        std::vector<Vertex*> topology_sort(); // get sorted vertices
    private:
        std::vector<Vertex*> _roots; // vector with all roots in graph
        size_t _cur_number = 1; // number of last added vertex
};
