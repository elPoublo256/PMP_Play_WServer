#ifndef PMP_METADATEBASE_H
#define PMP_METADATEBASE_H
#include <QMap>
typedef QString Groupname;
typedef QString Albomname;
typedef QString Treckname;
typedef QMap<Treckname,QString> PMPTreckBase;
typedef QMap<Albomname,PMPTreckBase> PMPAlbomBase;
typedef QMap<Groupname,PMPAlbomBase> PMPGroupBase;

class PMP_MetaDateBase
{
private:
    PMPGroupBase base;
public:


    PMP_MetaDateBase();
};

#endif // PMP_METADATEBASE_H
