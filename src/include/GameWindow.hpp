#pragma once
#include <stdio.h>
#include <iostream>
#include <QLabel>
#include <QGridLayout>
#include <QMessageBox>
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
        void togglePieceLabels();

        public slots:
        void displayPieceMoves(PieceLabel* pieceLabel);
        void displayMove(HighlightLabel *highlightLabel, Position originalPosition);
        
    private:
        void proposePromotion(PieceLabel* pieceLabel);

        QGridLayout* chessBoardLayout = new QGridLayout();
        GameManager* gameManager;
        std::vector<HighlightLabel*> highlightLabels;
};