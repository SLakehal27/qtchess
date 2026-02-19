#pragma once
#include <stdio.h>
#include <iostream>
#include <QLabel>
#include <QGridLayout>
#include <QMainWindow>
#include "Chessboard.hpp"

class GameWindow : public QMainWindow 
{
    Q_OBJECT
    public:
        virtual ~GameWindow() = default;
        GameWindow();
        void createChessBoard();
    private:
        QGridLayout* chessBoardLayout = new QGridLayout();
        Chessboard chessBoard;
};