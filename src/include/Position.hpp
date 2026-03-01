#pragma once
#include <ostream>

struct Position
{
    int x;
    int y;

    bool operator==(const Position& other) const { 
        return x == other.x && y == other.y; 
    }

    friend std::ostream& operator<<(std::ostream& stream, const Position& pos) {
        return stream << "(" << pos.x << " : " << pos.y << ")";
    }

    bool isLegal(const int board_size = 8) {
        return this->x >= 0 && this->x < board_size
        && this->y >= 0 && this->y < board_size;
    }
};
