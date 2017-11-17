#ifndef MYSERVER_H
#define MYSERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextEdit>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QTime>
#include <QMap>
#include <QFile>
#include <QDataStream>

class MyServer : public QWidget
{
    Q_OBJECT
private:
    QTcpServer* m_ptcpServer;
    QTextEdit*  m_ptxt;
    quint16     m_nNextBlockSize;
    QMap <int,QTcpSocket*> SClients;
    QBitArray* bitmap;
    QFile* file;

private:
    void sendToClient(QTcpSocket* pSocket, const QString& str);
public:
    MyServer(int nPort, QWidget* pwgt = 0);

public slots:
    virtual void slotNewConnection();
    void slotReadClient();

};

#endif // MYSERVER_H
