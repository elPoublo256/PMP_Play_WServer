#include "adminpanelform.h"
#include "ui_adminpanelform.h"

AdminPanelForm::AdminPanelForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminPanelForm)
{
    ui->setupUi(this);
}

AdminPanelForm::~AdminPanelForm()
{
    delete ui;
}
