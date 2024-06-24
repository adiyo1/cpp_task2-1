// 318725520
// adi.yohanann@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

using namespace std;

namespace ariel
{

    class Graph
    {

        vector<vector<int>> _nei;
        bool _isSim;

    public:
        Graph();
        vector<vector<int>> &getNei();
        void loadGraph(vector<vector<int>> graph);
        void printGraph();
        size_t get_size();
        int get_nei(size_t i, size_t j);
        bool isSim();
        bool  checkSameSize(const Graph& other);// use const to avoid changing the other graph
        friend std::ostream &operator<<(std::ostream &os, const Graph &g);//friend to access the private members of the class Graph becouse the operator<< is not a member of the class Graph and i want to print the private members of the class Graph
        friend bool operator==(const Graph &g1, const Graph &g2);
        bool operator>(const Graph &other);
        bool operator<(const Graph &other);
        bool operator>=(const Graph &other);
        bool operator<=(const Graph &other);
        Graph operator+(const Graph &g);
        Graph operator-(const Graph &g);
        Graph operator*(const Graph &g);
        friend Graph operator*(const Graph& g1, const Graph& g2);//
        void operator+=(int num);
        void operator+=(const Graph &other);
        void operator-=(int num);
        void operator-=(const Graph &other);
        void operator*=(int num);
        void operator*=(const Graph& other);
        void operator/=(int num);
        void operator+() const;
        void operator-() ;
        Graph& operator++();
        Graph operator++(int num);
        Graph& operator--();
        Graph operator--(int num);
        bool operator!=(const Graph& other);
        size_t countEdges(const Graph &g);
        Graph& operator=(const Graph &other);
    };
}

#endif