#include <stdio.h>
#include <sqlite3.h>  // Include the SQLite header file

// Function to execute an SQL statement
int createDatabase(const char* db_name) {
    sqlite3* DB;
    char* errorMessage;

    // Open or create the database
    int exit = sqlite3_open(db_name, &DB);

    if (exit != SQLITE_OK) {
        printf("Error opening database: %s\n", sqlite3_errmsg(DB));
        return exit;
    }
    printf("Opened database successfully\n");

    // SQL query to create a table
    char* sql = "CREATE TABLE IF NOT EXISTS STUDENTS("
                "ID INT PRIMARY KEY NOT NULL, "
                "NAME TEXT NOT NULL, "
                "AGE INT NOT NULL, "
                "ADDRESS CHAR(50), "
                "GRADE CHAR(1));";

    // Execute the SQL query to create the table
    exit = sqlite3_exec(DB, sql, NULL, 0, &errorMessage);

    if (exit != SQLITE_OK) {
        printf("SQL error: %s\n", errorMessage);
        sqlite3_free(errorMessage);
    } else {
        printf("Table created successfully\n");
    }

    // SQL query to insert data into the table, including "RAHUL BANSOD"
    sql = "INSERT INTO STUDENTS (ID, NAME, AGE, ADDRESS, GRADE) "
          "VALUES (1, 'John Doe', 20, '123 Elm St', 'A'), "
          "(2, 'Jane Smith', 22, '456 Oak St', 'B'), "
          "(3, 'Mike Johnson', 19, '789 Pine St', 'C'), "
          "(4, 'RAHUL BANSOD', 27, '456 Oak St', 'A');";

    // Execute the SQL query to insert the data
    exit = sqlite3_exec(DB, sql, NULL, 0, &errorMessage);

    if (exit != SQLITE_OK) {
        printf("SQL error: %s\n", errorMessage);
        sqlite3_free(errorMessage);
    } else {
        printf("Data inserted successfully\n");
    }

    // Close the database connection
    sqlite3_close(DB);
    return exit;
}

int main() {
    // Name of the database
    const char* db_name = "school.db";

    // Create the database, table, and insert data
    int result = createDatabase(db_name);

    // Check if there was an error
    if (result == SQLITE_OK) {
        printf("Database, table, and data created successfully.\n");
    } else {
        printf("Failed to create database or insert data.\n");
    }

    return 0;
}
