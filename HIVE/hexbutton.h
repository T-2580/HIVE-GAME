#ifndef HEXBUTTON_H
#define HEXBUTTON_H

#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QStyleOption>
#include <QPainterPath>
class HexButton : public QPushButton
{
    Q_OBJECT

public:
    explicit HexButton(QWidget *parent = nullptr);
    ~HexButton() override;

protected:
    void paintEvent(QPaintEvent *event) override;
    QRectF hexagonRect(const QRect &rect) const;
};

#endif // HEXBUTTON_H
