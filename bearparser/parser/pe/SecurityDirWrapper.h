#pragma once

#include "DataDirEntryWrapper.h"

/*
typedef struct WIN_CERTIFICATE {
  DWORD dwLength;
  WORD wRevision;
  WORD wCertificateType;
  BYTE bCertificate[];
} WIN_CERTIFICATE, *LPWIN_CERTIFICATE;
*/

class SecurityDirWrapper : public DataDirEntryWrapper
{
public:

    enum SecurityDirFID {
        NONE = FIELD_NONE,
        CERT_LEN = 0,
        REVISION,
        TYPE,
        CERT_CONTENT,
        FIELD_COUNTER
    };

    SecurityDirWrapper(PEFile * pe)
        : DataDirEntryWrapper(pe, pe::DIR_SECURITY), sizeOk(false)
    {
        wrap();
    }

    ~SecurityDirWrapper() { clear(); }

    bool wrap();

    virtual void* getPtr();

    virtual bufsize_t getSize();
    virtual QString getName() { return "Security"; }
    virtual size_t getFieldsCount() { return FIELD_COUNTER; }
    virtual size_t getSubFieldsCount() { return 1; }

    virtual void* getFieldPtr(size_t fieldId, size_t subField);
    virtual QString getFieldName(size_t fieldId);
    virtual WrappedValue::data_type containsDataType(size_t fieldId, size_t subField = FIELD_NONE);

    QString translateType(int type);
    virtual QString translateFieldContent(size_t fieldId);

private:
    pe::WIN_CERTIFICATE* getCert();
    void clear() {}

    bool sizeOk;
};
