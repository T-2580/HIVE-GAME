#include "hexbutton.h"
#include <QMouseEvent>

HexButton::HexButton(QWidget *parent) :
    QPushButton(parent)
{
    setAttribute(Qt::WA_TranslucentBackground, true);
    setFlat(true);
}

HexButton::~HexButton()
{
}

void HexButton::paintEvent(QPaintEvent *event)
{
    QStyleOptionButton option;
    initStyleOption(&option);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QRect rect = this->rect();
    int sideLength = std::min(rect.width(), rect.height()) / 2;

    QPainterPath path;
    path.moveTo(rect.center().x(), rect.top());
    path.lineTo(rect.right(), rect.center().y() - sideLength / 2);
    path.lineTo(rect.right(), rect.center().y() + sideLength / 2);
    path.lineTo(rect.center().x(), rect.bottom());
    path.lineTo(rect.left(), rect.center().y() + sideLength / 2);
    path.lineTo(rect.left(), rect.center().y() - sideLength / 2);
    path.closeSubpath();


    painter.setClipPath(path);

    QPixmap pixmap("D:/images/pieces/1.png");
    painter.drawPixmap(rect, pixmap);

    style()->drawControl(QStyle::CE_PushButton, &option, &painter, this);
}

QRectF HexButton::hexagonRect(const QRect &rect) const
{
    int sideLength = std::min(rect.width(), rect.height()) / 2;
    return QRectF(rect.center().x() - sideLength, rect.top(), sideLength * 2, rect.height());
}
