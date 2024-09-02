#include "LibraryManager.h"
#include <iostream>

// Book Class Implementation
Book::Book(const std::string& title, const std::string& author, const std::string& isbn)
    : title(title), author(author), isbn(isbn), available(true) {}

std::string Book::get_title() const {
    return title;
}

std::string Book::get_author() const {
    return author;
}

std::string Book::get_isbn() const {
    return isbn;
}

bool Book::is_available() const {
    return available;
}

void Book::set_availability(bool available) {
    this->available = available;
}

// Member Class Implementation
Member::Member(const std::string& name, const std::string& member_id)
    : name(name), member_id(member_id) {}

std::string Member::get_name() const {
    return name;
}

std::string Member::get_member_id() const {
    return member_id;
}

// Transaction Class Implementation
Transaction::Transaction(const std::string& member_id, const std::string& isbn, const std::time_t& date, bool returned)
    : member_id(member_id), isbn(isbn), date(date), returned(returned) {}

std::string Transaction::get_member_id() const {
    return member_id;
}

std::string Transaction::get_isbn() const {
    return isbn;
}

std::time_t Transaction::get_date() const {
    return date;
}

bool Transaction::is_returned() const {
    return returned;
}

// LibraryManager Class Implementation
void LibraryManager::add_book(const Book& book) {
    books.push_back(book);
}

void LibraryManager::add_member(const Member& member) {
    members.push_back(member);
}

void LibraryManager::lend_book(const std::string& member_id, const std::string& isbn) {
    for (auto& book : books) {
        if (book.get_isbn() == isbn && book.is_available()) {
            book.set_availability(false);
            transactions.emplace_back(member_id, isbn, std::time(nullptr), false);
            std::cout << "Book lent to member.\n";
            return;
        }
    }
    std::cout << "Book not available or does not exist.\n";
}

void LibraryManager::return_book(const std::string& member_id, const std::string& isbn) {
    for (auto& book : books) {
        if (book.get_isbn() == isbn && !book.is_available()) {
            book.set_availability(true);
            transactions.emplace_back(member_id, isbn, std::time(nullptr), true);
            std::cout << "Book returned.\n";
            return;
        }
    }
    std::cout << "Book was not lent or does not exist.\n";
}

void LibraryManager::list_books() const {
    for (const auto& book : books) {
        std::cout << "Title: " << book.get_title() << "\nAuthor: " << book.get_author() << "\nISBN: " << book.get_isbn() << "\nAvailable: " << (book.is_available() ? "Yes" : "No") << "\n\n";
    }
}

void LibraryManager::list_members() const {
    for (const auto& member : members) {
        std::cout << "Name: " << member.get_name() << "\nMember ID: " << member.get_member_id() << "\n\n";
    }
}

void LibraryManager::list_transactions() const {
    for (const auto& transaction : transactions) {
        std::cout << "Member ID: " << transaction.get_member_id() << "\nISBN: " << transaction.get_isbn() << "\nDate: " << std::ctime(&transaction.get_date()) << "\nReturned: " << (transaction.is_returned() ? "Yes" : "No") << "\n\n";
    }
}
