#pragma once
#include <QLabel>

class HighlightLabel : public QLabel {
    Q_OBJECT
    public:
        ~HighlightLabel() = default;

        HighlightLabel() { 
            setStyleSheet("background-color: rgba(255,255,255,35%)"); 
        }
};