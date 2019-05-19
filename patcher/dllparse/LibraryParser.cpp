#include "LibraryParser.h"

void LibraryParser::on_parseLibrary(QString& fileName)
{
    try {
        FileView *buf = new FileView(fileName);

        ExeFactory::exe_type exeType = ExeFactory::findMatching(buf);
        if (exeType == ExeFactory::NONE) {
            delete buf;
            return;
        }

        Executable *exe = ExeFactory::build(buf, exeType);
        makeLibraryInfo(exe, fileName);
        delete exe;
        delete buf;
    } catch (CustomException &e) {
        printf("ERR: %s\n", e.what());
    }
}

ExportDirWrapper* LibraryParser::getExports(Executable* exe)
{
    MappedExe *mappedExe = dynamic_cast<MappedExe*>(exe);
    if (mappedExe == NULL) return NULL;
    return dynamic_cast<ExportDirWrapper*>(mappedExe->getWrapper(PEFile::WR_DIR_ENTRY + pe::DIR_EXPORT));
}

void LibraryParser::makeLibraryInfo(Executable* exe, QString fileName)
{
    if (!exe) return;
    ExportDirWrapper* exports = getExports(exe);
    if (!exports) return;
    size_t entriesCnt = exports->getEntriesCount();
    if (entriesCnt == 0) return;

    LibraryInfo *info = new LibraryInfo(fileName);
    for(int i = 0; i < entriesCnt; i++) {
        ExportEntryWrapper* entry = dynamic_cast<ExportEntryWrapper*>(exports->getEntryAt(i));
        if (!entry) continue;
        info->functions.append(FunctionInfo(entry->getName(), entry->isByOrdinal()));
    }
    emit infoCreated(info);
}
