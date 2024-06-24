// 318725520
// adi.yohanann@gmail.com

#include "Graph.hpp"
#include <set>

using namespace std;

namespace ariel
{

    Graph::Graph() {}                    // constructor
    vector<vector<int>> &Graph::getNei() // get the matrix
    {
        return this->_nei; // return the matrix
    }

    void Graph::loadGraph(vector<vector<int>> graph) // load the matrix
    {
        for (size_t i = 0; i < graph.size(); i++)
        {
            if (graph[i].size() != graph.size()) // check if the matrix is a square matrix if not throw an error
                throw std::runtime_error("An error occurred.");
        }
        this->_nei = graph;           // load the matrix
        this->_isSim = this->isSim(); // check if the matrix is simetric
    }

    size_t Graph::get_size()
    {
        // Check if the adjacency matrix has been loaded
        if (this->_nei.empty())
        {
            return 0; // Return 0 if no graph loaded
        }
        else
        {
            // Return the number of rows (assuming square matrix)
            return this->_nei.size();
        }
    }
    size_t Graph::countEdges(const Graph &g)// count the number of edges in the matrix
    {
        size_t numOfdges = 0;
        for (size_t i = 0; i < g._nei.size(); ++i)
        {
            for (size_t j = 0; j < g._nei.size(); ++j)
            {
                if (g._nei[i][j] != 0)
                {
                    numOfdges++;
                }
            }
        }
        return numOfdges;
    }
    void Graph::printGraph() // print the matrix
    {

        int edges = 0; // initialize the number of edges

        for (size_t i = 0; i < this->get_size(); i++)
        {
            for (size_t j = 0; j < this->get_size(); j++)
            {
                if (this->get_nei(i, j) != 0) // if the element is not 0, it is an edge
                    edges++;
            }
        }
        cout << "Graph with " << this->get_size() << " vertices and " << edges << " edges." << endl;
    }

    int Graph::get_nei(size_t i, size_t j) // get the value of the matrix at the specified indices
    {
        // Validate indices within graph dimensions
        if (i < 0 || i >= this->_nei.size() || j < 0 || j >= this->_nei.size()) // check if the indices are valid
        {
            return 0; // Indicate invalid indices
        }
        // Access the value at the specified row (i) and column (j)
        return this->_nei[i][j];
    }

    bool Graph::isSim() // check if the matrix is simetric
    {

        for (size_t i = 0; i < this->_nei.size(); i++)
        {
            for (size_t j = 0; j < this->_nei.size(); j++)
            {
                if (this->_nei[i][j] != this->_nei[j][i]) // check if the matrix is simetric if not return false
                    return false;
            }
        }
        return true;
    }

    ////////OPERATORS///////////

    std::ostream &operator<<(std::ostream &os, const Graph &g)
    {

        for (size_t i = 0; i < g._nei.size(); ++i) // print the matrix
        {
            os << "[";
            for (size_t j = 0; j < g._nei.size(); ++j)
            {
                os << g._nei[i][j];
                if (j < g._nei.size() - 1)
                    os << ", ";
            }
            os << "]";
            if (i < g._nei.size() - 1)
                os << ", ";
        }
        return os;
    }

    Graph Graph::operator+(const Graph &other) // add two matrixs
    {
        size_t num_vertices_other = other._nei.size();
        size_t num_vertices_this = _nei.size();
        size_t total_vertices = num_vertices_other + num_vertices_this;
        if (num_vertices_other != num_vertices_this)
        {
            throw("not same size");
        }

        vector<vector<int>> newMat(num_vertices_other, vector<int>(num_vertices_other, 0)); // create new matrix
        Graph g3;

        // add this matrix and the other matrix to the new matrix
        for (size_t i = 0; i < num_vertices_other; ++i)
        {
            for (size_t j = 0; j < num_vertices_other; ++j)
            {
                newMat[i][j] = other._nei[i][j] + _nei[i][j]; // add the matrixs
            }
        }
        g3.loadGraph(newMat);
        return g3;
    }

    Graph Graph::operator-(const Graph &other)// substract two matrixs
    {
        //
        if (other._nei.size() != _nei.size()) // check if the matrixs is in the same size
        {
            throw("not same size");
        }

        vector<vector<int>> newMat(other._nei.size(), vector<int>(other._nei.size(), 0)); // create new matrix
        Graph g3;

        // Compute the difference between the two matrices
        for (size_t i = 0; i < other._nei.size(); ++i)
        {
            for (size_t j = 0; j < other._nei.size(); ++j)
            {
                newMat[i][j] = _nei[i][j] - other._nei[i][j]; // substract the matrixs
            }
        }
        g3.loadGraph(newMat);

        return g3;
    }

    Graph Graph::operator*(const Graph &other) // multiply two matrixs
    {
        if (checkSameSize(other) == false) // check if the matrixs is in the same size
        {
            throw("the matrixs is not in the same size");
            exit(1);
        }

        vector<vector<int>> newMat(other._nei.size(), vector<int>(other._nei.size(), 0)); // create new matrix
        Graph g3;
        for (size_t i = 0; i < other._nei.size(); ++i)
        {
            for (size_t j = 0; j < other._nei.size(); ++j)
            {
                newMat[i][j] = 0; // initialize the matrix
                for (size_t k = 0; k < other._nei.size(); ++k)
                {
                    newMat[i][j] += _nei[i][k] * other._nei[k][j]; // multiply the matrixs
                }
            }
        }

        g3.loadGraph(newMat);

        return g3;
    }

    Graph operator*(const Graph &g1, const Graph &g2) // multiply two matrixs
    {

        if (g1._nei.size() != g2._nei.size()) // check if the matrixs is in the same size
        {
            throw("not same size");
        }

        vector<vector<int>> newMat(g1._nei.size(), vector<int>(g1._nei.size(), 0)); // create new matrix
        Graph g3;
        for (size_t i = 0; i < g1._nei.size(); ++i)
        {
            for (size_t j = 0; j < g1._nei.size(); ++j)
            {
                newMat[i][j] = 0; // initialize the matrix
                for (size_t k = 0; k < g1._nei.size(); ++k)
                {
                    newMat[i][j] += g1._nei[i][k] * g2._nei[k][j]; // multiply the matrixs
                }
            }
        }

        g3.loadGraph(newMat);
        return g3;
    }

    void Graph::operator+=(int num) // add a number to the matrix
    {
        for (size_t i = 0; i < _nei.size(); ++i)
        {
            for (size_t j = 0; j < _nei.size(); ++j)
            {
                _nei[i][j] = _nei[i][j] + num; // add the number to the matrix
            }
        }
    }

    void Graph::operator-=(int num) // substract a number from the matrix
    {
        for (size_t i = 0; i < _nei.size(); ++i)
        {
            for (size_t j = 0; j < _nei.size(); ++j)
            {
                _nei[i][j] = _nei[i][j] - num; // substract the number from the matrix
            }
        }
    }

    void Graph::operator*=(const Graph &other) // multiply two matrixs
    {
        if (checkSameSize(other) == false) // check if the matrixs is in the same size
        {
            throw("the matrixs is not in the same size");
            exit(1);
        }
        vector<vector<int>> newMat(this->get_size(), vector<int>(this->get_size(), 0)); // create new matrix
        Graph g3;
        for (size_t i = 0; i < this->get_size(); ++i)
        {
            for (size_t j = 0; j < this->get_size(); ++j)
            {
                newMat[i][j] = 0; // initialize the matrix
                for (size_t k = 0; k < this->get_size(); ++k)
                {
                    newMat[i][j] += _nei[i][k] * other._nei[k][j]; // multiply the matrixs
                }
            }
        }
        // update the matrix
        for (size_t i = 0; i < this->get_size(); ++i)
        {
            for (size_t j = 0; j < this->get_size(); ++j)
            {
                this->_nei[i][j] = newMat[i][j]; // update the matrix
            }
        }
    }

    bool Graph::checkSameSize(const Graph &other) // check if the matrixs is in the same size
    {
        if (this->get_size() != other._nei.size())
        {
            return false;
        }
        return true;
    }

    void Graph::operator+=(const Graph &other) // add two matrixs
    {
        if (checkSameSize(other) == false) // check if the matrixs is in the same size
        {
            throw("the matrixs is not in the same size");
            exit(1);
        }
        for (size_t i = 0; i < _nei.size(); ++i)
        {
            for (size_t j = 0; j < _nei.size(); ++j)
            {
                _nei[i][j] = _nei[i][j] + other._nei[i][j]; // add the matrixs
            }
        }
    }

    void Graph::operator-=(const Graph &other) // substract two matrixs
    {
        if (checkSameSize(other) == false) // check if the matrixs is in the same size
        {
            throw("the matrixs is not in the same size");
            exit(1);
        }
        for (size_t i = 0; i < _nei.size(); ++i)
        {
            for (size_t j = 0; j < _nei.size(); ++j)
            {
                _nei[i][j] = _nei[i][j] - other._nei[i][j]; // substract the matrixs
            }
        }
    }

    void Graph::operator*=(int num) // multiply the matrix by a number
    {
        for (size_t i = 0; i < _nei.size(); ++i)
        {
            for (size_t j = 0; j < _nei.size(); ++j)
            {
                _nei[i][j] = _nei[i][j] * num; // multiply the matrix by the number
            }
        }
    }

    void Graph::operator/=(int num) // divide the matrix by a number
    {
        if (num == 0) // check if the number is 0
        {
            throw "ERROR: divide by 0";
            return;
        }
        for (size_t i = 0; i < _nei.size(); ++i)
        {
            for (size_t j = 0; j < _nei.size(); ++j)
            {
                _nei[i][j] = _nei[i][j] / num; // divide the matrix by the number
            }
        }
    }

    void Graph::operator+() const
    {
        return;
    }
    void Graph::operator-()
    {
        operator*=(-1); // use the multiply operator to multiply the matrix by -1
    }

    Graph &Graph::operator++()
    {
        *this += (1); // use the add operator to add 1 to the matrix
        return *this;
    }

    Graph Graph::operator++(int num)
    {

        Graph copy = *this;
        operator+=(1); // use the add operator to add 1 to the matrix
        return copy;
    }

    Graph &Graph::operator--()
    {
        *this -= (1); // use the substract operator to substract 1 from the matrix
        return *this;
    }
    Graph Graph::operator--(int num)
    {
        Graph copy = *this; // create a copy of the matrix
        operator-=(1);      // use the substract operator to substract 1 from the matrix
        return copy;        // return the copy of the matrix, before the substract operator, but the matrix is already substracted
    }

    bool Graph::operator>(const Graph &other)
    {
        if (_nei.size() < other._nei.size()) // check if the other matrix is bigger
        {
            return false;
        }
        size_t minG = 0;                           // initialize the minimum size of the matrixs
        if (this->_nei.size() > other._nei.size()) // check the minimum size of the matrixs
        {
            minG = other._nei.size(); // check the minimum size of the matrixs
        }
        else
        {
            minG = other._nei.size();
        }
        int count = 0; // count the number of same elements in the matrixs
        for (size_t i = 0; i < minG; ++i)
        {
            for (size_t j = 0; j < minG; ++j)
            {
                if (_nei[i][j] == other._nei[i][j]) // check if the elements are the same
                {
                    count++; // count the number of same elements
                }
            }
        }
        if (minG * minG == count && other._nei.size() != _nei.size()) // check if the matrixs are the same
        {
            return true;
        }
        size_t thisNumEdges = countEdges(*this);  // count the number of edges in the matrix
        size_t otherNumEdges = countEdges(other); // count the number of edges in the matrix
        cout << "thisNumEdges: " << thisNumEdges << endl;
        cout << "otherNumEdges: " << otherNumEdges << endl;
        if (thisNumEdges > otherNumEdges) // check if the number of edges in the matrix is bigger
        {
            return true;
        }
        if (thisNumEdges < otherNumEdges) // check if the number of edges in the matrix is smaller
        {
            return false;
        }

        return _nei.size() > other._nei.size();
    }
    bool Graph::operator!=(const Graph &other) // check if the matrixs are not the same
    {
        if ((*this == other) == false) // check if the matrixs are the same
        {
            return true;
        }
        return false;
    }

    bool Graph::operator>=(const Graph &other) // check if the matrix is bigger or equal to the other matrix
    {
        if (*this == other || operator>(other)) // use the equal or bigger operator to check if the matrix is bigger
        {
            return true;
        }
        return false;
    }

    bool Graph::operator<=(const Graph &other) // check if the matrix is smaller or equal to the other matrix
    {
        if (operator>(other)) // use the bigger operator to check if the matrix is smaller
        {
            return false;
        }
        return true;
    }

    bool Graph::operator<(const Graph &other) //
    {
        if (operator>=(other)) // use the bigger or equal operator to check if the matrix is smaller
        {
            return false;
        }
        return true;
    }
    bool operator==(const Graph &g1, const Graph &g2) // check if the matrixs are the same
    {
        if (g1._nei.size() != g2._nei.size()) // check if the matrixs are in the same size if not return false
        {
            return false;
        }
        for (size_t i = 0; i < g2._nei.size(); ++i)
        {
            for (size_t j = 0; j < g2._nei.size(); ++j)
            {
                if (g1._nei[i][j] != g2._nei[i][j])
                {
                    return false; // if one element is not the same return false
                }
            }
        }
        return true;
    }
    Graph &Graph::operator=(const Graph &other) // assign the matrix to another matrix
    {
        Graph g;                                // create a new matrix
        vector<vector<int>> graph = other._nei; // create a copy of the matrix
        this->loadGraph(graph);                 // load the matrix
        return *this;                           // return the matrix
    }

}
