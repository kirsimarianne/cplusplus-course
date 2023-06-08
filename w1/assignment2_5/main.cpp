/* Program stores books to unordered_map 
 * key: ISBN id and value: struct of book information
 * Funtion addBook adds a book to the map datastructure
 * Function removeBook deletes the instance of a book from the map
 * Function displayBook prints the information of the book
 * Function loanBook increases the variable of loaned and decreases the variable of quantaty of the book
 * There is no error handling at this version.
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

struct BookStruct
{
    std::string title {};
    std::string author {};
    int year {};
    int quantaty {};
    int loaned {0};
};

// Define own datatypes
using ISBN = int;
using BooksMap = std::unordered_map<ISBN, BookStruct>;


/* Function gets as parameters:
 * books_map and book_struct as reference,
 * and title, author, year, quantaty and loaned as const refrence.
 * Function adds book with not existing id to books_map
 */
void addBook(BooksMap &books_map, BookStruct book_struct, 
            const ISBN &id, const std::string &title, const 
            std::string &author, const int &year, const int &quantaty, const int &loaned)
{
    BooksMap::iterator it = books_map.find(id);
   
    if(it == books_map.end())
    {
        book_struct.title = title;
        book_struct.author = author;
        book_struct.year = year;
        book_struct.quantaty = quantaty;
        book_struct.loaned = loaned;

        books_map.insert(std::pair<ISBN,BookStruct>(id, book_struct));
    } 
}

/* Function parameters:
 * books_map as reference and id as const reference.
 * Function finds iterator of id and if id founded deletes the instance.
 */
void removeBook(BooksMap &books_map, const ISBN &id)
{
    BooksMap::iterator it = books_map.find(id); 

    if(it != books_map.end())
    {
        books_map.erase(it);
    }
        
}    

/* Function parameters:
 * books_map as reference and id as const reference.
 * Function prints the information of the book
 */
void displayBook(BooksMap &books_map, const ISBN &id)
{
    BooksMap::iterator it = books_map.find(id);

    if(it != books_map.end())
    {
        std::cout << "ISBN: " << it->first << '\n';
        std::cout << "Title: " << it->second.title << '\n';
        std::cout << "Author: " << it->second.author << '\n';
        std::cout << "Year: " << it->second.year << '\n';
        std::cout << "Quantaty: " << it->second.quantaty << '\n';
        std::cout << "Loaned: "  << it->second.loaned << '\n';
    }
}

/* Function parameters:
 * books_map as reference and id as conct reference
 * Function increase loan variable and decrease quantaty variable.
 */
void loanBook(BooksMap &books_map, const ISBN &id)
{
    BooksMap::iterator it = books_map.find(id);
    if(it != books_map.end() && it->second.loaned > 0)
    {
        it->second.quantaty--;
        it->second.loaned++;
    }
}

// For testing
void printMap(const BooksMap &books_map){
    for(const auto& pair : books_map)
    {
        std::cout << pair.first << ' ' << pair.second.title << ' '
        << pair.second.author << ' ' << pair.second.year << ' ' 
        << pair.second.quantaty << ' ' << pair.second.loaned  << '\n';
    }    
}


int main(){
    BookStruct book_struct;
    BooksMap books_map;

    //Testing
    addBook(books_map, book_struct, 1, "Example Book 1", "Example Author 1", 1990, 5, 0);
    addBook(books_map, book_struct, 2, "Example Book 2", "Example Author 2", 2000, 1, 0);
    addBook(books_map, book_struct, 3, "Example Book 3", "Example Author 3", 2020, 3, 1);
    std::cout << "Print out map: " << '\n';
    printMap(books_map);
    std::cout << "Remove a book 1: " << '\n';
    removeBook(books_map, 1);
    printMap(books_map);
    std::cout << "Display a book 2:" << '\n';
    displayBook(books_map, 2);
    std::cout << "Loan a book 3: " << '\n';
    loanBook(books_map, 3);
    displayBook(books_map, 3);
}