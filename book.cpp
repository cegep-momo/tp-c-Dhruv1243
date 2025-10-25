#include <sstream>
#include <algorithm>

#include "book.h"


// Default constructor
Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerName("")  {}

// Parameterized constructor
Book::Book(const std::string& title, const std::string& author, const std::string& isbn) 
    : title(title), author(author), isbn(isbn) {}

// Getters
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }
string Book::getBorrowerName() const { return borrowerName; }

// Setters
void Book::setTitle(const string& title) { this->title = title; }
void Book::setAuthor(const string& author) { this->author = author; }
void Book::setISBN(const string& isbn)  { this->isbn = isbn;}
void Book::setAvailability(bool available)  {  isAvailable = available;}
void Book::setBorrowerName(const string& borrowerName)  { this->borrowerName = borrowerName; }