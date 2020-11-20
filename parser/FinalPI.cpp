#include "Tools.h"
/*
FinalPI.cpp is the last step in Parse_SELECT FUNCTION which do the last PI operation in a SELECT query.
E.g
when string sql_statement = "SELECT Customer.name,Book.title,Publisher.name,Orders.quantity FROM Customer,Book,Publisher,Orders WHERE Customer.id=Orders.customer_id and Book.id=Orders.book_id and Book.publisher_id=Publisher.id and Customer.id>308000 and Book.copies>100 and Orders.quantity>1 and Publisher.nation='PRC';"
the execution tree need to Get [Customer.name,Book.title,Publisher.name,Orders.quantity] from all the data we get in the process. I realize this function in the FinalPI.cpp
*/