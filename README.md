# Library Management System

## Overview
This C++ program implements a simple library management system that allows users to manage books, borrowers, and transactions in a library. It provides functionalities such as adding books, searching for books, checking out books, returning books, calculating fines for overdue books, and displaying the list of books in the library.

## Features
- **Add Book**: Add a new book to the library database, including title, author, and ISBN.
- **Search Book**: Search for books in the library by title, author, or ISBN.
- **Check Out Book**: Allow borrowers to check out available books from the library.
- **Return Book**: Record the return of borrowed books and update their availability status.
- **Calculate Fine**: Calculate fines for overdue books (not implemented in this version).
- **Display Books**: Display the list of books in the library with their details.

## How it Works
- The program uses vectors to store information about books and borrowers.
- When the program starts, it displays a menu with options to perform various library operations.
- Users can choose an option from the menu by entering the corresponding number.
- Depending on the option chosen, the program executes the corresponding function:
    - **Add Book**: Prompts the user to enter details of a new book and adds it to the library.
    - **Search Book**: Allows users to search for books in the library by title, author, or ISBN.
    - **Check Out Book**: Enables borrowers to check out available books from the library.
    - **Return Book**: Records the return of borrowed books and updates their availability status.
    - **Calculate Fine**: Calculates fines for overdue books (not implemented in this version).
    - **Display Books**: Shows the list of books in the library with their details.
    - **Exit**: Terminates the program.
- The program runs in an infinite loop until the user chooses to exit.
- Input validation is not implemented in this version. Users are expected to enter valid input according to the prompts.

## How to Use
1. **Compile the Program**: Compile the C++ source code (`library_management.cpp`) using a C++ compiler.
    ```bash
    g++ library_management.cpp -o library_management
    ```
2. **Run the Program**: Execute the compiled binary to start the library management system.
    ```bash
    ./library_management
    ```
3. **Choose Options**: Follow the prompts to choose from various options in the menu to perform library operations such as adding books, searching for books, checking out books, returning books, and more.

## Contributors
- [Taha Rahman](https://github.com/TahaRahman1)

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
