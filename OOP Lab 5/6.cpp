#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Movie {
    string title, director;
    int duration;
public: 
    Movie(string title, string director, int duration) : title(title), director(director), duration(duration) {}
    string getTitle() const { return title; }
    string getDirector() const { return director; }
    int getDuration() const { return duration; }
};

class Cinema {
    int size;
    Movie** movieList;
    int currentMovies;
public:
    Cinema(int size) {
        currentMovies = 0;
        this->size = size;
        movieList = new Movie*[size];
    }
    ~Cinema(){
        for(int i=0; i<currentMovies; i++)
            delete movieList[i];
        delete[] movieList;
    }
    void addMovie(string title, string director, int duration){
        if(currentMovies < size){
            movieList[currentMovies] = new Movie(title, director, duration);
            currentMovies++;
        }
        else{
            cout << "\nMax. Capacity Hit\n";
        }
    }
    void display() {
        if (currentMovies == 0) {
            cout << "There is no Movie yet!\n";
        } else {
            cout << left << setw(25) << "Title" << setw(25) << "Director" << setw(25) << "Duration (min)" << endl;
            for (int i = 0; i < currentMovies; i++) {
                cout << left << setw(25) << movieList[i]->getTitle()
                     << setw(25) << movieList[i]->getDirector()
                     << setw(25) << movieList[i]->getDuration() << endl;
            }
        }
    }
};

int main() {
    Cinema cinema(3);

    cinema.addMovie("Inception", "Christopher Nolan", 148);
    cinema.addMovie("Interstellar", "Christopher Nolan", 169);
    cinema.addMovie("The Godfather", "Francis Ford Coppola", 175);

    // cinema.addMovie("Titanic", "James Cameron", 195);     //For checking max. capacity
    
    nl;
    cinema.display();
    nl;

    return 0;
}
