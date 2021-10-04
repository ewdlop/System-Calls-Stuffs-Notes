#ifndef STATEMENT_H
#define STATEMENT_H

#include "common.h"

typedef enum
{
    STATEMENT_INSERT,
    STATEMENT_SELECT
} StatementType;

typedef struct
{
    StatementType type;
    Row row_to_insert; // only used by insert statement
} Statement;


ExecuteResult execute_statement(Statement* statement, Table* table)
{
    switch (statement->type)
    {
    case (STATEMENT_INSERT):
        return execute_insert(statement, table);
    case (STATEMENT_SELECT):
        printf("This is where we would do a select.\n");
        return execute_select(statement, table);
    }
}
#endif