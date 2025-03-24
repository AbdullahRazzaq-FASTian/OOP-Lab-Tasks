#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Media
{
protected:
    string title;
    int publicationDate;
    int uniqueID;
    string publisher;
    static int idCounter;

public:
    Media() {}
    Media(string title, int publicationDate, string publisher)
        : title(title), publicationDate(publicationDate), publisher(publisher) { uniqueID = idCounter++; }
    virtual void displayInfo() const
    {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
    }

    virtual void checkOut()
    {
        cout << title << " has been checked out." << endl;
    }
    virtual void returnItem()
    {
        cout << title << " has been returned." << endl;
    }
    
    virtual string getTitle() const
    {
        return title;
    }
    virtual int getPublicationDate() const
    {
        return publicationDate;
    }
    virtual string getPublisher() const
    {
        return publisher;
    }

    virtual ~Media() {}
};
int Media::idCounter = 0;

class Book : public Media
{
protected:
    string author;
    int ISBN;
    int noOfPages;

public:
    Book() {}
    Book(string title, int publicationDate, string publisher, string author, int ISBN, int noOfPages)
        : Media(title, publicationDate, publisher), author(author), ISBN(ISBN), noOfPages(noOfPages) {}
    void displayInfo() const override
    {
        Media ::displayInfo();
        cout << "Author : " << author << endl;
        cout << "ISBN : " << ISBN << endl;
        cout << "Number of Pages : " << noOfPages << endl;
    }
};

class DVD : public Media
{
protected:
    string director;
    float duration;
    float rating;

public:
    DVD() {}
    DVD(string title, int publicationDate, string publisher, string director, float duration, float rating)
        : Media(title, publicationDate, publisher), director(director), duration(duration), rating(rating) {}

    void displayInfo() const override
    {
        Media ::displayInfo();
        cout << "Director : " << director << endl;
        cout << "Duration : " << duration << endl;
        cout << "Rating : " << rating << endl;
    }
};

class CD : public Media
{
protected:
    string artist;
    int numberOFtracks;
    string genre;

public:
    CD() {}
    CD(string title, int publicationDate, string publisher, string artist, int numberOFtracks, string genre)
        : Media(title, publicationDate, publisher), artist(artist), numberOFtracks(numberOFtracks), genre(genre) {}

    void displayInfo() const override
    {
        Media ::displayInfo();
        cout << "Artist : " << artist << endl;
        cout << "Number of Tracks : " << numberOFtracks << endl;
        cout << "Genre : " << genre << endl;
    }
};

void searchMedia(Media* library[], int n, string title) {
    for (int i = 0; i < n; i++) {
        if (title == library[i]->getTitle()) {
            cout << "Media found! \n";
            library[i]->displayInfo();
            return;
        }
    }
    cout << "Media not found!" << endl;
}
void searchMedia(Media* library[], int n, int publicationDate) {
    for (int i = 0; i < n; i++) {
        if (publicationDate == library[i]->getPublicationDate()) {
            cout << "Media found! \n";
            library[i]->displayInfo();
            return;
        }
    }
    cout << "Media not found!" << endl;
}

int main()
{
    Media *library[3];
    library[0] = new Book("C++ Basics", 2020, "XYZ Publications", "John Doe", 123456, 250);
    library[1] = new DVD("Inception", 2010, "WB Studios", "Christopher Nolan", 148, 8.8);
    library[2] = new CD("Thriller", 1982, "Epic Records", "Michael Jackson", 9, "Pop");

    cout << "\n---Library Collection---\n\n";
    for (int i = 0; i < 3; i++)
    {
        library[i]->displayInfo();
        cout << "----------------------\n";
    }

    cout << "\n---Searching Examples---\n";
    cout << "\nSearching media from title for 'Inception':\n";
    searchMedia(library, 3, "Inception");

    cout << "\nSearching for media from year 2020:\n";
    searchMedia(library, 3, 2020);
   

    for (int i = 0; i < 3; i++)
        delete library[i];
    return 0;
}