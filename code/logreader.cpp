#include "logreader.h"

void LogReader::evaluateLine(int line, const string &line_data, set<int> &logins)
{
    if (line_data != "") {
        stringstream ss(line_data);
        string entry("");
        string strid("");
        ss >> entry;
        ss >> strid;
        int id = -1;

        // No user ID, or NaN
        try {
            id = stoi(strid);
        } catch (exception& e) {
            entry_errors.push_back(LogEntryError(line, id, LET_INVALID_USER_ID));
            return; // Skip all other operations
        }

        // Find out if the user is logged in or not (points to end iterator)
        set<int>::iterator find_it = logins.find(id);

        if (entry == "userlogin") {
            if (find_it != logins.end()) {
                // User is already logged in
                entry_errors.push_back(LogEntryError(line, id, LET_RELOGIN));
            } else {
                // Login the user...
                logins.insert(id);
            }
        } else if (entry == "userlogout") {
            if (find_it == logins.end()) {
                // User logout without login
                entry_errors.push_back(LogEntryError(line, id, LET_LOGOUT_WITHOUT_LOGIN));
            } else {
                // Logout the user...
                logins.erase(find_it);
            }
        } else if (entry == "failedlogin") {
            // User failed to login
            entry_errors.push_back(LogEntryError(line, id, LET_FAILED_LOGIN));
            failed_logins++;
        } else {
            // Invalid entry
            entry_errors.push_back(LogEntryError(line, -1, LET_INVALID_ENTRY_TYPE));
        }

    }
}

void LogReader::checkForLoggedInUsers(int line, set<int> &logins)
{
    for (int id : logins) {
        entry_errors.push_back(LogEntryError(line, id, LET_STAYED_LOGGED_IN));
    }
}

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
    ifstream file(file_name);
    string line_data;
    set<int> logins;
    int line = 1;

    if (file.is_open()) {
        while (file.good()) {
            getline(file, line_data);
            evaluateLine(line, line_data, logins);
            line++;
        }
        file.close();
        checkForLoggedInUsers(line, logins);
        return true;
    } else {
        return false;
    }
}
