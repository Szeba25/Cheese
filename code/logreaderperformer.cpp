#include "logreaderperformer.h"

LogReaderPerformer::LogReaderPerformer(const string &fileName) :
    fileName(fileName),
    fileExists(false)
{
    logReader = new LogReader();
}

LogReaderPerformer::~LogReaderPerformer()
{
    delete logReader;
}

void LogReaderPerformer::execute()
{
    fileExists = logReader->readLog(fileName);
}

string LogReaderPerformer::getDescription() const
{
    stringstream ss;
    ss << "logreader, file: " << fileName;
    return ss.str();
}

string LogReaderPerformer::getResult() const
{
    if (fileExists) {
        stringstream ss;
        ss << "number of failed logins: " << logReader->getFailedLogins() << endl;

        list<LogReader::LogEntryError> log = logReader->getEntryErrors();

        for (const LogReader::LogEntryError &e : log)
        {
            ss << "in line " << e.line << ": user id: " <<
                  e.user_id << ", problem: " << LogReader::errorTypeToString(e.error_type) << endl;
        }
        return ss.str();
    } else {
        return string("Cannot read file\n");
    }
}
