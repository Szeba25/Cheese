#include <iostream>
#include "speedtester.h"
#include "fibonacci.h"
#include "logreader.h"
#include "taskperformerinterface.h"

using namespace std;

int main()
{
	{
		SpeedTester tester(1234.33, 43.2, '+', 100000000);
		chrono::duration<double, milli> dur=tester.test();
		cout << dur.count() << " milliseconds" << endl; // 202.159 milliseconds
	}
	{
		SpeedTester tester(1234.33, 43.2, '-', 100000000);
		chrono::duration<double, milli> dur=tester.test();
		cout << dur.count() << " milliseconds" << endl; // 198.14 milliseconds
	}
	{
		SpeedTester tester(1234.33, 43.2, '*', 100000000);
		chrono::duration<double, milli> dur=tester.test();
		cout << dur.count() << " milliseconds" << endl; // 199.14 milliseconds
	}
	{
		SpeedTester tester(1234.33, 43.2, '/', 100000000);
		chrono::duration<double, milli> dur=tester.test();
		cout << dur.count() << " milliseconds" << endl; // 594.422 milliseconds
	}

	{
		cout << Fibonacci::getFibo(41) << endl; // 165580141
	}

	{
		LogReader reader;
		reader.readLog("log1.log");
		cout << "number of failed logins: " << reader.getFailedLogins() << endl;
		const list<LogReader::LogEntryError> &errors=reader.getEntryErrors();
		for (const LogReader::LogEntryError &e : errors)
		{
			cout << "in line " << e.line << ": user id: " << e.user_id << ", problem: " << LogReader::errorTypeToString(e.error_type) << endl;
		}
//		number of failed logins: 2
//		in line 3: user id: 24, problem: logout without login
//		in line 5: user id: 17, problem: failed login
//		in line 8: user id: -1, problem: invalid log entry type
//		in line 10: user id: 13, problem: relogin
//		in line 12: user id: -1, problem: invalid user id
//		in line 14: user id: -1, problem: invalid user id
//		in line 18: user id: 13, problem: logout without login
//		in line 19: user id: 25, problem: failed login
//		in line 22: user id: 5, problem: stayed logged in at the end
//		in line 22: user id: 17, problem: stayed logged in at the end
	}

//	{
//		TaskPerformerInterface *task=new FibonacciPerformer(43);
//		cout << task->getDescription() << endl; // fibonacci, number: 43
//		task->execute();
//		cout << task->getResult() << endl; // 433494437
//		delete task;
//	}

//	{
//		TaskPerformerInterface *task=new SpeedTesterPerformer(1234.56, 765.43, '*', 200000000);
//		cout << task->getDescription() << endl; // speed test, numbers: 1234.560000, 765.430000, operation: *, iterations: 200000000
//		task->execute();
//		cout << task->getResult() << endl; // 399.299400 milliseconds (500.877287 million operations per second)
//		delete task;
//	}

//	{
//		TaskPerformerInterface *task=new LogReaderPerformer("log1.log");
//		cout << task->getDescription() << endl; // logreader, file: log1.log
//		task->execute();
//		cout << task->getResult() << endl;
//		delete task;
////		number of failed logins: 2
////		in line 3: user id: 24, problem: logout without login
////		in line 5: user id: 17, problem: failed login
////		in line 8: user id: -1, problem: invalid log entry type
////		in line 10: user id: 13, problem: relogin
////		in line 12: user id: -1, problem: invalid user id
////		in line 14: user id: -1, problem: invalid user id
////		in line 18: user id: 13, problem: logout without login
////		in line 19: user id: 25, problem: failed login
////		in line 22: user id: 5, problem: stayed logged in at the end
////		in line 22: user id: 17, problem: stayed logged in at the end
//	}
	return 0;
}
