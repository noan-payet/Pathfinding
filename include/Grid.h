#pragma once

#include <vector>

#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define DEFAULT "\033[0m"

#define EMPTY ' '
#define OBSTACLE '#'
#define PLAYER 'O'

struct Tile
{
    int row, col;
    bool obstacle;
};

template<typename T>
struct Node;

class GridCoord;

class Grid
{
    std::vector<std::vector<Tile>> mTiles;
    std::vector<Node<Tile>*> mNodes;

public:
    int RowCount = 0;
    int ColCount = 0;

    Grid();

    bool Initialize(const std::vector<std::vector<char>>& map);

    Tile* GetTile(int row, int col);

    Tile* GetTile(const GridCoord* coord);

    std::vector<Node<Tile>*> GetNode() { return mNodes; }

    GridCoord* CreateCoord(int row = 0, int col = 0);
};

