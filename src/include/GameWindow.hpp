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
        void clearHighlights();

        public slots:
        void displayPieceMoves(PieceLabel* pieceLabel);
        void displayMove(HighlightLabel *highlightLabel, Position originalPosition);
        
    private:
        QGridLayout* chessBoardLayout = new QGridLayout();
        GameManager* gameManager;
        std::vector<HighlightLabel*> highlightLabels;
};