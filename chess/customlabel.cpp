#include "customlabel.h"

CustomLabel::CustomLabel() : QLabel()
{
    connect( this, SIGNAL( clicked() ), this, SLOT( slotClicked() ) );
}

void CustomLabel::slotClicked()
{
    qDebug()<<"Clicked";
}

void CustomLabel::mousePressEvent ( QMouseEvent * event )
{
    emit clicked();
}
