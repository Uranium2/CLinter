cmake_minimum_required(VERSION 3.10)
project(CLinter)
set(CMAKE_C_STANDARD 99)

if (WIN32)
    find_path(MYSQL_INCLUDE_DIR
            NAMES "mysql.h"
            PATHS "include")

    find_library(MYSQL_LIBRARY
            NAMES "libmysql.dll"
            PATHS "vendor")
else ()
    find_path(MYSQL_INCLUDE_DIR
            NAMES "mysql.h"
            PATHS "/usr/include/mysql"
            "/usr/local/include/mysql"
            "/usr/mysql/include/mysql")

    find_library(MYSQL_LIBRARY
            NAMES "mysqlclient" "mysqlclient_r"
            PATHS "/vendor/mysql"
            "/lib64/mysql"
            "/usr/lib/mysql"
            "/usr/lib64/mysql"
            "/usr/local/lib/mysql"
            "/usr/local/lib64/mysql"
            "/usr/mysql/lib/mysql"
            "/usr/mysql/lib64/mysql")
endif ()


if (MYSQL_INCLUDE_DIR AND EXISTS "${MYSQL_INCLUDE_DIRS}/mysql_version.h")
    file(STRINGS "${MYSQL_INCLUDE_DIRS}/mysql_version.h"
            MYSQL_VERSION_H REGEX "^#define[ \t]+MYSQL_SERVER_VERSION[ \t]+\"[^\"]+\".*$")
    string(REGEX REPLACE
            "^.*MYSQL_SERVER_VERSION[ \t]+\"([^\"]+)\".*$" "\\1" MYSQL_VERSION_STRING
            "${MYSQL_VERSION_H}")
endif ()

# handle the QUIETLY and REQUIRED arguments and set MYSQL_FOUND to TRUE if
# all listed variables are TRUE
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
        MYSQL DEFAULT_MSG
        REQUIRED_VARS MYSQL_LIBRARY MYSQL_INCLUDE_DIR
        VERSION_VAR MYSQL_VERSION_STRING)

set(MYSQL_INCLUDE_DIRS ${MYSQL_INCLUDE_DIR})
set(MYSQL_LIBRARIES ${MYSQL_LIBRARY})

mark_as_advanced(MYSQL_INCLUDE_DIR MYSQL_LIBRARY)

# Library database
add_library(
        MainLibrary
        src/config/config.c
        src/config/config.h
        src/file/files.c
        src/file/files.h
        src/file/listFiles.c
        src/file/listFiles.h
        src/parse/changeType.c
        src/parse/changeType.h
        src/parse/parser.c
        src/parse/parser.h
        src/parse/token.c
        src/parse/token.h
        src/rules/checkCoding.c
        src/rules/checkCoding.h
        src/rules/checker.c
        src/rules/checker.h
        src/rules/checkVarFunc.c
        src/rules/checkVarFunc.c
        src/rules/checkVarFunc.h
        src/headers.h
        src/rules/checkUnusedVariable.c src/rules/checkUnusedVariable.h)

# Main
add_executable(clinter src/main.c)
target_link_libraries(clinter ${MYSQLLIBRARY} MainLibrary)


# Tests
#add_executable(tests_db_access tests/test_db_access.c)
#target_link_libraries(tests_db_access ${MYSQL_LIBRARY} MainLibrary)
