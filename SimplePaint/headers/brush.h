#ifndef BRUSH_H
#define BRUSH_H

#include "headers/tool.h"

class Brush : public Tool
{
    Q_OBJECT
public:
    Brush(QColor, int, QImage*);

    ~Brush() override;

    void paint(QPoint) override;
    void mouseMoved(QMouseEvent *) override;
    void mouseClicked(QMouseEvent *) override;
    void mouseReleased(QMouseEvent *) override;

    QColor getColor() const override { return myColor; }

    void setColor(QColor color) override;
    void setWidth(const int width) override;

signals:
    void updateRect(QRect) override;

private:
    QPoint lastPoint;
};

#endif // BRUSH_H