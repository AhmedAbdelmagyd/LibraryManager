#include "LibraryManager.h"
#include <iostream>
#include <limits>

void display_menu() {
    std::cout << "Library Management System Menu:\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Add Member\n";
    std::cout << "3. Lend Book\n";
    std::cout << "4. Return Book\n";
    std::cout << "5. List Books\n";
    std::cout << "6. List Members\n";
    std::cout << "7. List Transactions\n";
    std::cout << "8. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    LibraryManager library_manager;
    int choice;
    std::string title, author, isbn, name, member_id;
    char buffer[256];
    std::time_t current_time = std::time(nullptr);

    while (true) {
        display_menu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

        switch (choice) {
            case 1:
                std::cout << "Enter book title: ";
                std::cin.getline(buffer, 256);
                title = buffer;
                std::cout << "Enter book author: ";
                std::cin.getline(buffer, 256);
                author = buffer;
                std::cout << "Enter book ISBN: ";
                std::cin.getline(buffer, 256);
                isbn = buffer;
                library_manager.add_book(Book(title, author, isbn));
                std::cout << "Book added successfully.\n";
                break;

            case 2:
                std::cout << "Enter member name: ";
                std::cin.getline(buffer, 256);
                name = buffer;
                std::cout << "Enter member ID: ";
                std::cin.getline(buffer, 256);
                member_id = buffer;
                library_manager.add_member(Member(name, member_id));
                std::cout << "Member added successfully.\n";
                break;

            case 3:
                std::cout << "Enter member ID: ";
                std::cin.getline(buffer, 256);
                member_id = buffer;
                std::cout << "Enter book ISBN: ";
                std::cin.getline(buffer, 256);
                isbn = buffer;
                library_manager.lend_book(member_id, isbn);
                break;

            case 4:
                std::cout << "Enter member ID: ";
                std::cin.getline(buffer, 256);
                member_id = buffer;
                std::cout << "Enter book ISBN: ";
                std::cin.getline(buffer, 256);
                isbn = buffer;
                library_manager.return_book(member_id, isbn);
                break;

            case 5:
                std::cout << "Books in the library:\n";
                library_manager.list_books();
                break;

            case 6:
                std::cout << "Library members:\n";
                library_manager.list_members();
                break;

            case 7:
                std::cout << "Transactions:\n";
                library_manager.list_transactions();
                break;

            case 8:
                std::cout << "Exiting the system.\n";
                return 0;

            default:
                std::cout << "Invalid option. Please try again.\n";
                break;
        }
    }
}
