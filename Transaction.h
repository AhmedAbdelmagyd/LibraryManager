#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>

class Transaction {
public:
    Transaction(const std::string& member_id, const std::string& isbn, const std::time_t& date, bool returned);
    std::string get_member_id() const;
    std::string get_isbn() const;
    std::time_t get_date() const;
    bool is_returned() const;

private:
    std::string member_id;
    std::string isbn;
    std::time_t date;
    bool returned;
};

#endif // TRANSACTION_H
