#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <array>

using namespace std;

struct Node {
    double rating;
    string comment;
    Node *next;
};

// Movie class with linked list and title private members
class Movie {
    private: 
    string title;
    Node* head;

    public:
    //class constructor
    Movie(string t = "") {
     title = t;
     head = nullptr;
    }
//adds node to head of linked list
//argument: double rating and string comment
//return: none
void addHead(double rating, string comment){
    Node *n = new Node;
    if (!head){
        head = n;
        n->next = nullptr;
        n->rating = rating;
        n->comment = comment;
    }
    else {
        n->next = head;
        n->rating = rating;
        n->comment = comment;
        head = n;
    }
}
//prints out movie title and review + average
//argument: none
//return: none
void print(){
    cout << "Movie: " << title << endl;
    int count = 1;
    int sum = 0;
    Node *current = head;
    while (current) {
        cout << "   > Review #" << (count++) << ": "
        << current->rating << ": " << current->comment << endl;
        sum += current->rating;
        current = current->next;
    }
    cout << "   > Average: " << (sum/count) << endl;
}

};


int main(){

//movie list
    array<Movie, 4> movies = {Movie("Hunger Games"), Movie("Divergent"),
     Movie("Harry Potter"), Movie("Him") };

//get comments
string comment;
srand(static_cast<unsigned>(time(0)));
ifstream fin("reviews.txt");
for (int i = 0; i < 4; i++){
    for (int j = 0; j < 3; j++) {
        getline(fin,comment);
        int x = 10 + rand() % 41;
       //random rating
         double rating = static_cast<double>(x) / 10.0;
        movies[i].addHead(rating, comment);
    }
}
fin.close();
//print
for (int i =0; i < 4; i++) {
    movies[i].print();
}

    return 0;
    

}