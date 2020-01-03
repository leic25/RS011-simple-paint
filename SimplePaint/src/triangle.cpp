#include <iostream>
#include "headers/triangle.h"

Triangle::Triangle(QColor* color, int width, QImage* img)
    :Tool::Tool(color, width, img)
{}

Triangle::~Triangle(){}

void Triangle::mouseClicked(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        lastPoint = event->pos();
    }
}

void Triangle::mouseMoved(QMouseEvent *event) { event->ignore(); }

void Triangle::mouseReleased(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton)
    {
        paint(event->pos());
    }
}

void Triangle::setWidth(const int width) { myWidth = width; }

void Triangle::paint(QPoint endPoint)
{
    QPainter painter(image);
    Point3 = endPoint;
    Point1 = QPoint((lastPoint.x()+endPoint.x())/2, (lastPoint.y()+endPoint.y())/2);
    Point2 = QPoint(endPoint.x(), lastPoint.y());
    QVector<QPoint> points;
    points.append(Point2);
    points.append(Point1);
    points.append(Point3);

    painter.setPen(QPen(*myColor,
                        myWidth,
                        Qt::SolidLine,
                        Qt::RoundCap,
                        Qt::RoundJoin));

    painter.setRenderHint(QPainter::Antialiasing);

    QPolygon triangle(points);
    painter.drawPolygon(triangle);

    modified = true;
}
