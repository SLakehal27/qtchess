#pragma once
#include <stdio.h>
#include <iostream>
#include <QLabel>
#include <QGridLayout>
#include <QMainWindow>
#include "GameManager.hpp"

class GameWindow : public QMainWindow 
{
    Q_OBJECT
    public:
        virtual ~GameWindow() = default;
        GameWindow();
        void createChessBoard();
    public slots:
        void displayPieceMoves(PieceLabel* pieceLabel);
    private:
        QGridLayout* chessBoardLayout = new QGridLayout();
        GameManager* gameManager;
};