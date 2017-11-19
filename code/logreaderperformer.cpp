#include "logreaderperformer.h"

LogReaderPerformer::LogReaderPerformer(const string &fileName) :
    fileName(fileName)
{
    logReader = new LogReader();
}

LogReaderPerformer::~LogReaderPerformer()
{
    delete logReader;
}

void LogReaderPerformer::execute()
{
    logReader->readLog(fileName);
}

string LogReaderPerformer::getDescription() const
{
    stringstream ss;
    ss << "logreader, file: " << fileName;
    return ss.str();
}

string LogReaderPerformer::getResult() const
{
    stringstream ss;
    ss << "number of failed logins: " << logReader->getFailedLogins() << endl;

    list<LogReader::LogEntryError> log = logReader->getEntryErrors();
    int listSize = log.size();
    int idx = 0;
    for (const LogReader::LogEntryError &e : log)
    {
        ss << "in line " << e.line << ": user id: " <<
              e.user_id << ", problem: " << LogReader::errorTypeToString(e.error_type);
        if (idx != listSize-1) {
            ss << endl;
        }
        idx++;
    }
    return ss.str();
}
