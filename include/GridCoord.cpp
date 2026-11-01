#include "GridCoord.h"

GridCoord::GridCoord(int row, int col, int maxRow, int maxCol)
{
    mRow = row;
    mCol = col;
    mMaxRow = maxRow;
    mMaxCol = maxCol;
}

bool GridCoord::SetRow(int row)
{
    if (row < 0 || row >= mMaxRow)
        return false;

    mRow = row;
    return true;
}

bool GridCoord::SetCol(int col)
{
    if (col < 0 || col >= mMaxCol)
        return false;

    mCol = col;
    return true;
}

void GridCoord::Set(const GridCoord* coord)
{
    mRow = coord->mRow;
    mCol = coord->mCol;
}
