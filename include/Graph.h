#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

template<typename T>
struct Node
{
    T* data;

    bool path;

    bool added;
    Node* cameFrom;

    std::vector<Node*> neighbors;
};

template<typename T>
class Graph
{
private:
    std::vector<Node<T>*> m_Nodes;

public:
    void ResetTiles(std::vector<Node<T>*> mNodes)
    {
        m_Nodes.clear();
        for (Node<T>* node : mNodes)
        {
            node->added = false;
            node->path = false;
            node->cameFrom = nullptr;
        }
    }

    bool BuildPath(Node<T>* startNode, T* endT, std::vector<Node<T>*> mNodes)
    {
        ResetTiles(mNodes);

        startNode->added = true;
        m_Nodes.push_back(startNode);

        while (m_Nodes.size() > 0)
        {
            Node<T>* current = m_Nodes[0];
            m_Nodes.erase(m_Nodes.begin());

            if (current->data == endT)
            {
                while (current != nullptr)
                {
                    current->path = true;
                    current = current->cameFrom;
                }

                return true;
            }

            for (int i = 0; i < current->neighbors.size(); ++i)
            {
                Node<T>* neighbor = current->neighbors[i];

                if (neighbor->added)
                    continue;

                neighbor->added = true;
                neighbor->cameFrom = current;
                m_Nodes.push_back(neighbor);
            }
        }

        return false;
    }

    void SetNode(std::vector<Node<T>*> nodes) { m_Nodes = nodes; }
    std::vector<Node<T>*> GetNode() { return m_Nodes; }
};

#endif // !GRAPH_H
