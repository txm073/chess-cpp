#ifndef CUSTOMLABEL_H
#define CUSTOMLABEL_H

#include <QtWidgets>
#include <QtGui>

class CustomLabel : public QLabel
{
    Q_OBJECT
public:
    CustomLabel();
    ~CustomLabel(){}

signals:
    void clicked();

public slots:
    void slotClicked();

protected:
    void mousePressEvent ( QMouseEvent * event ) ;

};

#endif // CUSTOMLABEL_H
