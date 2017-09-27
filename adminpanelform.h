#ifndef ADMINPANELFORM_H
#define ADMINPANELFORM_H

#include <QWidget>

namespace Ui {
class AdminPanelForm;
}

class AdminPanelForm : public QWidget
{
    Q_OBJECT

public:
    explicit AdminPanelForm(QWidget *parent = 0);
    ~AdminPanelForm();

private:
    Ui::AdminPanelForm *ui;
};

#endif // ADMINPANELFORM_H
