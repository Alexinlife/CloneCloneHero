#include "QMNote.h"

QMNote::QMNote(QGraphicsItem* parent, int c, int t) :QGraphicsItem(parent)
{
    speed = 1;
    color = c;
    type = t;
    age = 0;
    x = 0;
    z = 0;
    startpos = -400 + speed;
    y = startpos + (150 / 4) - (9 / 2);
    w = startpos + (150 / 4);
}

int QMNote::getColor()
{
    return color;
}

int QMNote::getType()
{
    return type;
}

int QMNote::getAge()
{
    return age;
}

void QMNote::setAge(int a)
{
    age = a;
}

QRectF QMNote::boundingRect() const
{
    return QRectF(0, -500, 150, 100);
}

void QMNote::advance(int)
{
    setPos(mapToParent(0, speed));
}

void QMNote::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    if (type != 3)
    {
        switch (color)
        {
        case 0:
            x = -520 - (112 / 2);
            z = -570;

            if (type == 1)
            {
                painter->setOpacity(0.15);
                painter->setBrush(QColorConstants::Svg::orange);
                painter->drawEllipse(-620, startpos, 200, 150);
                break;
            }
            if (type == 4)
            {
                painter->setBrush(QColorConstants::Svg::orange);
                painter->drawEllipse(-630, -(190 / 4) - 490 + (15 / 2), 220, 165);
                painter->setBrush(Qt::black);
                painter->drawEllipse(-620, -(190 / 4) - 475, 200, 150);
                painter->setBrush(QColorConstants::Svg::orange);
                painter->drawEllipse(-615, -(190 / 4) - 471, 190, 190 - (190 / 4));
                break;
            }
            painter->setBrush(QColorConstants::Svg::orange);
            painter->drawEllipse(-620, startpos, 200, 150);
            break;

        case 1:
            x = -220 - (112 / 2);
            z = -270;

            if (type == 1)
            {
                painter->setOpacity(0.15);
                painter->setBrush(Qt::blue);
                painter->drawEllipse(-320, startpos, 200, 150);
                break;
            }
            if (type == 4)
            {
                painter->setBrush(Qt::blue);
                painter->drawEllipse(-330, -(190 / 4) - 490 + (15 / 2), 220, 165);
                painter->setBrush(Qt::black);
                painter->drawEllipse(-320, -(190 / 4) - 475, 200, 150);
                painter->setBrush(Qt::blue);
                painter->drawEllipse(-315, -(190 / 4) - 471, 190, 190 - (190 / 4));
                break;
            }
            painter->setBrush(Qt::blue);
            painter->drawEllipse(-320, startpos, 200, 150);
            break;

        case 2:
            x = 80 - (112 / 2);
            z = 30;

            if (type == 1)
            {
                painter->setOpacity(0.15);
                painter->setBrush(Qt::yellow);
                painter->drawEllipse(-20, startpos, 200, 150);
                break;
            }
            if (type == 4)
            {
                painter->setBrush(Qt::yellow);
                painter->drawEllipse(-30, -(190 / 4) - 490 + (15 / 2), 220, 165);
                painter->setBrush(Qt::black);
                painter->drawEllipse(-20, -(190 / 4) - 475, 200, 150);
                painter->setBrush(Qt::yellow);
                painter->drawEllipse(-15, -(190 / 4) - 471, 190, 190 - (190 / 4));
                break;
            }
            painter->setBrush(Qt::yellow);
            painter->drawEllipse(-20, startpos, 200, 150);
            break;

        case 3:
            x = 380 - (112 / 2);
            z = 330;

            if (type == 1)
            {
                painter->setOpacity(0.15);
                painter->setBrush(Qt::red);
                painter->drawEllipse(280, startpos, 200, 150);
                break;
            }
            if (type == 4)
            {
                painter->setBrush(Qt::red);
                painter->drawEllipse(270, -(190 / 4) - 490 + (15 / 2), 220, 165);
                painter->setBrush(Qt::black);
                painter->drawEllipse(280, -(190 / 4) - 475, 200, 150);
                painter->setBrush(Qt::red);
                painter->drawEllipse(285, -(190 / 4) - 471, 190, 190 - (190 / 4));
                break;
            }
            painter->setBrush(Qt::red);
            painter->drawEllipse(280, startpos, 200, 150);
            break;

        case 4:
            x = 680 - (112 / 2);
            z = 630;


            if (type == 1)
            {
                painter->setOpacity(0.15);
                painter->setBrush(Qt::green);
                painter->drawEllipse(580, startpos, 200, 150);
                break;
            }
            if (type == 4)
            {
                painter->setBrush(Qt::green);
                painter->drawEllipse(570, -(190 / 4) - 490 + (15 / 2), 220, 165);
                painter->setBrush(Qt::black);
                painter->drawEllipse(580, -(190 / 4) - 475, 200, 150);
                painter->setBrush(Qt::green);
                painter->drawEllipse(585, -(190 / 4) - 471, 190, 190 - (190 / 4));
                break;
            }
            painter->setBrush(Qt::green);
            painter->drawEllipse(580, startpos, 200, 150);
            break;
        }

    }

    switch (type)
    {
    case 0:
        painter->setBrush(Qt::black);
        painter->drawEllipse(x, y, 112, 84);
        painter->setBrush(Qt::white);
        painter->drawEllipse(z, w, 100, 75);
        break;
    case 1:
        painter->setBrush(Qt::black);
        painter->drawEllipse(x, y, 112, 84);
        painter->setBrush(Qt::white);
        painter->drawEllipse(z, w, 100, 75);
        break;
    case 2:
        painter->setBrush(Qt::white);
        painter->drawEllipse(z, w, 100, 75);
        break;
        // strum bar
    case 3:
        painter->setBrush(QColorConstants::Svg::purple);
        painter->drawRoundedRect(-620, 300, 1400, 20, 10, 10);
        break;
    }
}