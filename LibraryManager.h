#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include "Book.h"
#include "Member.h"
#include "Transaction.h"
#include <vector>
#include <string>

class LibraryManager {
public:
    void add_book(const Book& book);
    void add_member(const Member& member);
    void lend_book(const std::string& member_id, const std::string& isbn);
    void return_book(const std::string& member_id, const std::string& isbn);
    void list_books() const;
    void list_members() const;
    void list_transactions() const;

private:
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Transaction> transactions;
};

#endif // LIBRARYMANAGER_H
