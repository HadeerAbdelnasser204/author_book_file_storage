#include <iostream>
#include<fstream>

using namespace std;
struct Book {
    char ISBN[15]; //primary key
    char bookTitle[30];
    char authorID[15]; //secondary key
    uint8_t recordLength;
};
struct Author {
    char authorID[15]; // primary key
    char authorName[30];
    char address[30];
    uint8_t recordLength;
};

void add(Author &author, string fileName) {
    fstream outFile(fileName, ios::app | ios::binary);
    if (!outFile.is_open()) {
        cout << "Error!\n";
    }
    //explain
    // outFile.write(reinterpret_cast<const char*>(&author.recordLength), sizeof(author.recordLength));

    outFile << author.authorID << '|' << author.authorName << '|' << author.address << '\n';
    outFile.close();
}

void addBook(Book &book, string fileName) {
    fstream outFile(fileName, ios::app | ios::binary);
    if (!outFile.is_open()) {
        cout << "Error!\n";
    }
    //explain
   // outFile.write(reinterpret_cast<const char *>(&book.recordLength), sizeof(book.recordLength));

    outFile << book.ISBN << '|' << book.bookTitle << '|' << book.authorID << '\n';
    outFile.close();
}

int main() {
    Author a{};
    a.recordLength = static_cast<uint8_t>(sizeof(a) - sizeof(a.recordLength));
    cout << "ID: ";
    cin.getline(a.authorID, 15);
    cout << "Name: ";
    cin.getline(a.authorName, 30);
    cout << "address: ";
    cin.getline(a.address, 30);
    add(a, "Author.txt");
    Book b{};
    b.recordLength = static_cast<uint8_t>(sizeof(b) - sizeof(b.recordLength));
    cout << "ISBN: ";
    cin.getline(b.ISBN, 15);
    cout << "Name: ";
    cin.getline(b.bookTitle, 30);
    cout << "authorID: ";
    cin.getline(b.authorID, 15);
    addBook(b, "Book.txt");
}
