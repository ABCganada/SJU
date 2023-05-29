
#include <stdio.h>
#include <Windows.h>
#include <sql.h>
#include <sqlext.h>

bool db_connect();
void db_disconnect();

SQLHENV hEnv = NULL;	// Environment Handle
SQLHDBC hDbc = NULL;	// Connection Handle

const char *dataSourceName = "DB01_Server";
const char *serverId = "sa";
const char *serverPw = "aaaa";

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

const char *get_data_type_in_string(SQLSMALLINT dataType)
{
    switch (dataType)
    {
    case SQL_CHAR:
        return "CHAR";
        break;
    case SQL_VARCHAR:
        return "VARCHAR";
        break;
    case SQL_LONGVARCHAR:
        return "LONGVARCHAR";
        break;
    case SQL_WCHAR:
        return "WCHAR";
        break;
    case SQL_WVARCHAR:
        return "WVARCHAR";
        break;
    case SQL_WLONGVARCHAR:
        return "WLONGVARCHAR";
        break;
    case SQL_NUMERIC:
        return "NUMERIC";
        break;
    case SQL_SMALLINT:
        return "SMALLINT";
        break;
    case SQL_INTEGER:
        return "INTEGER";
        break;
    case SQL_REAL:
        return "REAL";
        break;
    case SQL_FLOAT:
        return "FLOAT";
        break;
    case SQL_DOUBLE:
        return "DOUBLE";
        break;
    case SQL_BIT:
        return "BIT";
        break;
    case SQL_TINYINT:
        return "TINYINT";
        break;
    case SQL_BIGINT:
        return "BIGINT";
        break;
    case SQL_BINARY:
        return "BINARY";
        break;
    case SQL_VARBINARY:
        return "VARBINARY";
        break;
    case SQL_LONGVARBINARY:
        return "LONGVARBINARY";
        break;
    case SQL_TYPE_DATE:
        return "TYPE_DATE";
        break;
    case SQL_TYPE_TIME:
        return "TYPE_TIME";
        break;
    case SQL_TYPE_TIMESTAMP:
        return "TYPE_TIMESTAMP";
        break;
    case SQL_INTERVAL_MONTH:
        return "INTERVAL_MONTH";
        break;
    case SQL_INTERVAL_YEAR:
        return "INTERVAL_YEAR";
        break;
    case SQL_INTERVAL_YEAR_TO_MONTH:
        return "INTERVAL_YEAR_TO_MONTH";
        break;
    case SQL_INTERVAL_DAY:
        return "INTERVAL_DAY";
        break;
    case SQL_INTERVAL_HOUR:
        return "INTERVAL_HOUR";
        break;
    case SQL_INTERVAL_MINUTE:
        return "INTERVAL_MINUTE";
        break;
    case SQL_INTERVAL_SECOND:
        return "INTERVAL_SECOND";
        break;
    case SQL_INTERVAL_DAY_TO_HOUR:
        return "INTERVAL_DAY_TO_HOUR";
        break;
    case SQL_INTERVAL_DAY_TO_MINUTE:
        return "INTERVAL_DAY_TO_MINUTE";
        break;
    case SQL_INTERVAL_DAY_TO_SECOND:
        return "INTERVAL_DAY_TO_SECOND";
        break;
    case SQL_INTERVAL_HOUR_TO_MINUTE:
        return "INTERVAL_HOUR_TO_MINUTE";
        break;
    case SQL_INTERVAL_HOUR_TO_SECOND:
        return "INTERVAL_HOUR_TO_SECOND";
        break;
    case SQL_INTERVAL_MINUTE_TO_SECOND:
        return "INTERVAL_MINUTE_TO_SECOND";
        break;
    case SQL_GUID:
        return "GUID";
        break;
    default:
        return "UNKNOWN";
    }
}


int main(int argc, char *argv[])
{
    if (db_connect())
    {
        printf("Connected to %s!\n\n", dataSourceName);

        SQLHSTMT hStmt;	// Statement Handle
        SQLCHAR query[101];

        int deptNo, floor;
        char deptName[31];
        printf("Enter a DEPARTMENT number: ");
        scanf_s("%d", &deptNo);
        printf("Enter a DEPARTMENT name: ");
        scanf_s("%s", deptName, 31);
        printf("Enter a DEPARTMENT floor: ");
        scanf_s("%d", &floor);

        if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
        {
            sprintf_s((char *)query, 101, "INSERT INTO DEPARTMENT VALUES(%d,'%s',%d)", deptNo, deptName, floor);
            SQLExecDirect(hStmt, query, SQL_NTS);

            sprintf_s((char *)query, 101, "SELECT * FROM DEPARTMENT");
            SQLExecDirect(hStmt, query, SQL_NTS);

            SQLBindCol(hStmt, 1, SQL_C_SLONG, &deptNo, sizeof(int), NULL);
            SQLBindCol(hStmt, 2, SQL_C_CHAR, deptName, 31, NULL);
            SQLBindCol(hStmt, 3, SQL_C_SLONG, &floor, sizeof(int), NULL);

            printf("\n");
            while (SQLFetch(hStmt) != SQL_NO_DATA)
            {
                printf("%-5d", deptNo);
                printf("%-3s", deptName);
                printf("%d\n", floor);
            }

            SQLCloseCursor(hStmt);
            SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
        }

        db_disconnect();
    }

    return 0;
}
