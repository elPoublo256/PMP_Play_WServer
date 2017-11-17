#ifndef PMPSERVER_H
#define PMPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include <QByteArray>
#include <QMap>
#define PMP_PORT 2323


//typedef PMPServFunctor<0> sendMedia ;
class PMPServer : public QObject
{

    Q_OBJECT
private:
    qint16 nextBlockSize;
    QTcpServer* TcPServer;
    QMap<int,QTcpSocket*> clientSocketBase;
    bool isListen;
    void sendToClient(QTcpSocket* clientSoket, QByteArray bytearr);
    void sendToClient(QTcpSocket* clientSoket, QString massage);
public:
    explicit PMPServer(int nPort=PMP_PORT,QObject *parent = 0);
///all functions for sending to client
private:
  void show_all_trecks_ofalbom();

 //find_alboms_of_group();
 //find_trecks_of_group();



signals:

public slots:
    void on_newConnection();
    void on_ReadClient();
};






#endif // PMPSERVER_H
