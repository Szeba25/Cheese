#ifndef LOGREADER_H
#define LOGREADER_H

#include <fstream>
#include <string>
#include <map>
#include <list>
#include <sstream>

using namespace std;

class LogReader
{
public:
	enum LogErrorType // Enum to handle error types
	{
		LET_RELOGIN = 0,
		LET_LOGOUT_WITHOUT_LOGIN,
		LET_STAYED_LOGGED_IN,
		LET_FAILED_LOGIN,
		LET_INVALID_ENTRY_TYPE,
		LET_INVALID_USER_ID
	};

	struct LogEntryError // Inside structure to save errors
	{
		int line, user_id; // Line where occured, user_id (-1 is the error is invalid entry or id)
		LogErrorType error_type; // type of error

		LogEntryError(int line, int id, LogErrorType type):
			line(line),
			user_id(id),
			error_type(type)
		{}
	};
private:
	unsigned int failed_logins=0; // Number of failed logins
	list<LogEntryError> entry_errors; // List of errors
public:
	unsigned int getFailedLogins() const;
	const list<LogEntryError> &getEntryErrors() const;
	void clearData(); // To initialize member variables
	static string errorTypeToString(LogErrorType type); // Static function to convert error type from enum to text

	bool readLog(const string &file_name); // Function to read the file (must be written)
};

#endif // LOGREADER_H
