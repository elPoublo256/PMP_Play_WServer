#include "myserver.h"

MyServer::MyServer(int nPort, QWidget *pwgt) : QWidget(pwgt), m_nNextBlockSize(0)
{
    m_ptcpServer=new QTcpServer(this);
    if(!m_ptcpServer->listen(QHostAddress::Any,nPort))
    {
        QMessageBox::critical(0,"Server Error","Unable to start the server:"
                             + m_ptcpServer->errorString());
                m_ptcpServer->close();
                return;
    }
    connect(m_ptcpServer,SIGNAL(newConnection()),this,SLOT(slotNewConnection()));
    m_ptxt=new QTextEdit;
    QVBoxLayout* pvbxLayout = new QVBoxLayout;

        //pvbxLayout->addWidget(new QLabel("<H1>Server</H1>"));
        pvbxLayout->addWidget(m_ptxt);
        setLayout(pvbxLayout);

}

 void MyServer::slotNewConnection()
{
    QTcpSocket* pClientSocket = m_ptcpServer->nextPendingConnection();
    int userID;
    userID=pClientSocket->socketDescriptor();
    SClients[userID]=pClientSocket;
    connect(SClients[userID],SIGNAL(disconnected()),pClientSocket,SLOT(deleteLater()));
    connect(SClients[userID],SIGNAL(readyRead()), this, SLOT(slotReadClient()));
    sendToClient(SClients[userID],"Server Response: Connected!");
}

 void MyServer::slotReadClient()
 {
     QTcpSocket* pClientSocket = (QTcpSocket*)sender();

     QDataStream in(pClientSocket);
     in.setVersion(QDataStream::Qt_4_2);
     for(;;)
     {
         if(!m_nNextBlockSize)
         {
             if(pClientSocket->bytesAvailable()<sizeof(quint16))
             {
                 break;
             }
             in >> m_nNextBlockSize;
         }
         if(pClientSocket->bytesAvailable()<m_nNextBlockSize)
         {
             break;
         }
         QTime time;
         QString str;
         in>>time>>str;QString strMessage =
                 time.toString() + " " + "Client has sended - " + str;

         m_ptxt->append(strMessage);
         m_nNextBlockSize = 0;
         sendToClient(pClientSocket,"Server Response: Received \"" + str + "\"");



     }
 }

void MyServer::sendToClient(QTcpSocket* pSocket, const QString& str)
{
   QByteArray arrBlock;
   QDataStream out(&arrBlock, QIODevice::WriteOnly);
   out.setVersion(QDataStream::Qt_4_2);
   out.device()->seek(0);
   out<<quint16(arrBlock.size()-sizeof(quint16));
   pSocket->write(arrBlock);
}
