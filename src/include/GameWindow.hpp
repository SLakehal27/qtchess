#pragma once
#include <stdio.h>
#include <iostream>
#include <QLabel>
#include <QGridLayout>
#include <QMainWindow>
#include "GameManager.hpp"
#include "HighlightLabel.hpp"

class GameWindow : public QMainWindow 
{
    Q_OBJECT
    public:
        virtual ~GameWindow() = default;
        GameWindow();
        void createChessBoard(Chessboard &chessBoard);
    public slots:
        void displayPieceMoves(PieceLabel* pieceLabel);
    private:
        QGridLayout* chessBoardLayout = new QGridLayout();
        GameManager* gameManager;
        std::vector<HighlightLabel*> highlightLabels;
};