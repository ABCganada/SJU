#include <stdio.h>
#include <Windows.h>
#include <sql.h>
#include <sqlext.h>

bool db_connect();
void db_disconnect();

SQLHENV hEnv = NULL;	// Environment Handle
SQLHDBC hDbc = NULL;	// Connection Handle

const char *dataSourceName = "DB01_Server";
const char *serverId = "KIM";
const char *serverPw = "kim123";

bool db_connect()
{
	SQLRETURN Ret;

	// Allocate the Environment Handle (hEnv)
	if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv) != SQL_SUCCESS)
	{
		return false;
	}

	// Set attributes of the Environment Handle (hEnv)
	if (SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER) != SQL_SUCCESS)
	{
		return false;
	}

	// Allocate the Connection Handle (hDbc)
	if (SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc) != SQL_SUCCESS)
	{
		return false;
	}

	// Connect to the SQL Sever with ODBC name, ID, and PW
	Ret = SQLConnect(hDbc, (SQLCHAR *)dataSourceName, SQL_NTS, (SQLCHAR *)serverId, SQL_NTS, (SQLCHAR *)serverPw, SQL_NTS);

	if ((Ret != SQL_SUCCESS) && (Ret != SQL_SUCCESS_WITH_INFO))
	{
		return false;
	}

	return true;
}

void db_disconnect()
{
	SQLDisconnect(hDbc);					// Disconnect from the SQL Server
	SQLFreeHandle(SQL_HANDLE_DBC, hDbc);	// Free the Connection Handle
	SQLFreeHandle(SQL_HANDLE_ENV, hEnv);	// Free the Environment Handle
}

int main(int argc, char *argv[])
{
	if (db_connect())
	{
		printf("Connected to %s!\n\n", dataSourceName);

		/* Your code goes here, */
		SQLHSTMT hStmt;	// Statement Handle
		SQLCHAR query[101];

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
		{
			sprintf_s((char *)query, 101, "INSERT INTO DEPARTMENT VALUES(4, 'DATABASE', 8)");
			SQLExecDirect(hStmt, query, SQL_NTS);

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}


		db_disconnect();
	}

	return 0;
}


