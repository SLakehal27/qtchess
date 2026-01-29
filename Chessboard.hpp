#pragma once
#include <vector>
#include <QLabel>

struct Chessboard
{
    std::vector<std::vector<QLabel*>> board{8, std::vector(8, new QLabel(""))};
};
