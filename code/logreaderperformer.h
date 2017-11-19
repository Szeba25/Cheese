#ifndef LOGREADERPERFORMER_H
#define LOGREADERPERFORMER_H

#include <sstream>
#include "taskperformerinterface.h"
#include "logreader.h"

class LogReaderPerformer : public TaskPerformerInterface
{
public:
    LogReaderPerformer(const string& fileName);
    virtual ~LogReaderPerformer();

    virtual void execute();
    virtual string getDescription() const;
    virtual string getResult() const;
private:
    string fileName;
    LogReader* logReader;
};

#endif // LOGREADERPERFORMER_H
