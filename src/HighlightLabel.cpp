#include "HighlightLabel.hpp"

void HighlightLabel::mousePressEvent(QMouseEvent* event)
{
    if (event->button() != Qt::LeftButton) return;
    emit clicked(this, originalPosition);
}