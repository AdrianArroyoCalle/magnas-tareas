PROJECT(sqlite3 C)
SET(sqlite3_SRC "sqlite3.c")
ADD_LIBRARY(sqlite3 STATIC ${sqlite3_SRC})

