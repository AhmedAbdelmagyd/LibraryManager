#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    Book(const std::string& title, const std::string& author, const std::string& isbn);
    std::string get_title() const;
    std::string get_author() const;
    std::string get_isbn() const;
    bool is_available() const;
    void set_availability(bool available);

private:
    std::string title;
    std::string author;
    std::string isbn;
    bool available;
};

#endif // BOOK_H
