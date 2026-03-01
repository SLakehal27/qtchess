#pragma once
#include <QLabel>
#include <QMouseEvent>
#include "Position.hpp"

class HighlightLabel : public QLabel {
    Q_OBJECT
    public:
        ~HighlightLabel() = default;

        HighlightLabel() { 
            setStyleSheet("background-color: rgba(255,255,255,35%)"); 
        }

        Position originalPosition;

    signals:
        void clicked(HighlightLabel* highlightLabel, Position originalPosition);

    protected:
        void mousePressEvent(QMouseEvent* event) override;
};