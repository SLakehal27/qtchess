#pragma once
#include <stdio.h>
#include <iostream>
#include <QLabel>
#include <QGridLayout>
#include <QMainWindow>

class GameWindow : public QMainWindow 
{
    Q_OBJECT
    public:
        virtual ~GameWindow() = default;
        GameWindow();
        void createChessBoard();
    private:
        const int BOARD_SIZE = 8;
        QGridLayout* chessBoardLayout = new QGridLayout();
        std::vector<std::vector<QLabel*>> chessSquares{8, std::vector(8, new QLabel(""))};
};