#include "pmpserver.h"

PMPServer::PMPServer(int nPort, QObject *parent) : QObject(parent)
{
    TcPServer=new QTcpServer(this);
    isListen=TcPServer->listen(QHostAddress::Any,nPort);
    if(!isListen)
    {
        qDebug()<<"Error. Unable start this server"+TcPServer->errorString();
    }

    connect(TcPServer,SIGNAL(newConnection()),this,SLOT(on_newConnection()));


}

void PMPServer::on_newConnection()
{
    QTcpSocket* clientSocket=TcPServer->nextPendingConnection();
    int userID=clientSocket->socketDescriptor();
    clientSocketBase[userID]=clientSocket;
    connect(clientSocketBase[userID],SIGNAL(readyRead()),
            this,SLOT(on_ReadClient()));
    connect(clientSocketBase[userID],SIGNAL(disconnected()),
            this, SLOT(deleteLater()));
}

void PMPServer::on_ReadClient()
{
    QTcpSocket* actClient=(QTcpSocket*)sender();//sender is QObject that emit this slot
    QDataStream in(actClient);
    for(;;)
    {
        if(!nextBlockSize)
        {
            if(actClient->bytesAvailable()<sizeof(qint16))
            {
                break;
            }
        }
        if(actClient->bytesAvailable()<nextBlockSize)
        {
            break;
        }

        QString str;

        in>>str;
        QStringList strL=str.split('|');
        const int n=QVariant(strL[0]).toInt();


    }
}
