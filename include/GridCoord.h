#pragma once

class GridCoord
{
public:
    int GetRow() const { return mRow; }
    int GetCol() const { return mCol; }

    bool AddRow(int row) { return SetRow(mRow + row); }
    bool AddCol(int col) { return SetCol(mCol + col); }

    bool SetRow(int row);
    bool SetCol(int col);

    void Set(const GridCoord* coord);

    bool Is(int row, int col) const { return mRow == row && mCol == col; }

private:
    GridCoord(int row, int col, int maxRow, int maxCol);

    int mRow, mCol;
    int mMaxRow, mMaxCol;

    friend class Grid;
};

