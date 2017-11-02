#include "logreader.h"

unsigned int LogReader::getFailedLogins() const
{
	return failed_logins;
}

const list<LogReader::LogEntryError> &LogReader::getEntryErrors() const
{
	return entry_errors;
}

void LogReader::clearData()
{
	failed_logins=0;
	entry_errors.clear();
}

string LogReader::errorTypeToString(LogReader::LogErrorType type)
{
	if (type==LET_RELOGIN) return "relogin";
	else if (type==LET_LOGOUT_WITHOUT_LOGIN) return "logout without login";
	else if (type==LET_STAYED_LOGGED_IN) return "stayed logged in at the end";
	else if (type==LET_FAILED_LOGIN) return "failed login";
	else if (type==LET_INVALID_ENTRY_TYPE) return "invalid log entry type";
	else if (type==LET_INVALID_USER_ID) return "invalid user id";
	return "----------";
}

bool LogReader::readLog(const string &file_name)
{
}
