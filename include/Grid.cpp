#include "Grid.h"

#include "GridCoord.h"
#include "../pf-core/Graph.h"

Grid::Grid()
{

}

bool Grid::Initialize(const std::vector<std::vector<char>>& map)
{
    if (map.size() == 0)
        return false;

    RowCount = map.size();
    ColCount = map[0].size();

    mTiles.resize(RowCount);
    for (int row = 0; row < RowCount; ++row)
    {
        mTiles[row].resize(ColCount);
        for (int col = 0; col < ColCount; ++col)
        {
            Tile& tile = mTiles[row][col];
            tile.row = row;
            tile.col = col;
            tile.obstacle = map[row][col] == OBSTACLE;

            Node<Tile>* node = new Node<Tile>;
            node->data = GetTile(row, col);
            node->added = false;
            node->path = false;
            node->cameFrom = nullptr;

            if (node->data->obstacle)
            {
                mNodes.push_back(node);
                continue;
            }

            for (Node<Tile>* neighborNode : mNodes)
            {
                if (neighborNode->data->obstacle)
                    continue;

                if (node->data->row - 1 == neighborNode->data->row
                    && node->data->col == neighborNode->data->col)
                {
                    node->neighbors.push_back(neighborNode);
                    neighborNode->neighbors.push_back(node);
                }
                if (node->data->col - 1 == neighborNode->data->col
                    && node->data->row == neighborNode->data->row)
                {
                    node->neighbors.push_back(neighborNode);
                    neighborNode->neighbors.push_back(node);
                }
            }

            mNodes.push_back(node);
        }
    }

    return true;
}

Tile* Grid::GetTile(int row, int col)
{
    if (row < 0 || row >= RowCount)
        return nullptr;

    if (col < 0 || col >= ColCount)
        return nullptr;

    return &mTiles[row][col];
}

Tile* Grid::GetTile(const GridCoord* coord)
{
    return &mTiles[coord->mRow][coord->mCol];
}

GridCoord* Grid::CreateCoord(int row, int col)
{
    GridCoord* out = new GridCoord(row, col, RowCount, ColCount);

    return out;
}
