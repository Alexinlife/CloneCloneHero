#ifndef QMNOTE_H
#define QMNOTE_H

#include <QGraphicsItem>
#include <QPainter>

class QMNote : public QGraphicsItem
{
public slots:
    void advance(int);

public:
    QMNote(QGraphicsItem* parent = NULL, int c = 0, int t = 0);

    int getColor();
    int getType();
    int getAge();
    void setAge(int a);

protected:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    QRectF boundingRect() const;

private:
    int type;
    int color;
    int age;
    int x, y, w, z;
    int startpos;
    qreal speed;
};

#endif