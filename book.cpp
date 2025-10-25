#include <sstream>
#include <algorithm>
#include <iostream>
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

// Checkout
void Book::checkOut(const string& borrower) {
    if (isAvailable){
        isAvailable = false;
        borrowerName = borrower;
        std::cout << "Le livre \"" << title << "\" a été emprunté par " << borrower << "." << std::endl;
    } else {
        std::cout << "Le livre \"" << title << "\" est déja emprunté . " <<  std::endl;
    }
}

// Return Book
void Book::returnBook(){
    if (!isAvailable) {
        isAvailable = true;
        borrowerName = "";
        std::cout << "Le livre \"" << title << "\" a été retourné . " << std::endl;
    }else {
        std::cout << "Le livre \"" << title << "\" est déja retourné . " <<  std::endl;
    }
}
// to string
string Book::toString() const {
    string result = "Titre: " + title + "\nAuteur " + author+ 
                        "\nISBN : " + isbn + "\nDisponible : " + (isAvailable ? std::string("Oui") : std::string("Non"));
    
    if (!isAvailable) {
        result += "\nEmprunté par: " + borrowerName;

    }
    return result;
}

// Format for file storage
std::string Book::toFileFormat() const {
    std::string result = title + "|" + author + "|" + isbn + "|" 
        + (isAvailable ? "1" : "0") + "|" + borrowerName;
    return result;
}

// Parse from file format

void Book::fromFileFormat(const std::string& line) {
    std::stringstream ss(line);
    std::string availableStr;

    std::getline(ss, title, '|');
    std::getline(ss, author, '|');
    std::getline(ss, isbn, '|');
    std::getline(ss, availableStr, '|');
    std::getline(ss, borrowerName, '|');

    isAvailable = (availableStr == "1");
}

