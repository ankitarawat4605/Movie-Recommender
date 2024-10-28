#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

struct Movie {
    string title;
    string genre;
    double rating;
};
class MovieRecommender {
private:
    vector<Movie> movieList;
    unordered_map<string, vector<Movie>> genreMap;

public:
    void addMovie(const string& title, const string& genre, double rating) {
        Movie movie = {title, genre, rating};
        movieList.push_back(movie);
        genreMap[genre].push_back(movie);
    }

    void recommendMovies(const string& genre, int numRecommendations = 3) {
        if (genreMap.find(genre) == genreMap.end()) {
            cout << "No movies available in this genre.\n";
            return;
        }

        vector<Movie> genreMovies = genreMap[genre];
        sort(genreMovies.begin(), genreMovies.end(), [](Movie& m1, Movie& m2) {
            return m1.rating > m2.rating;
        });

        cout << "Top " << numRecommendations << " recommended movies in genre '" << genre << "':\n";
        for (int i = 0; i < min(numRecommendations, (int)genreMovies.size()); i++) {
            cout << genreMovies[i].title << " (" << genreMovies[i].rating << "/5)\n";
        }
    }
};

int main() {
    MovieRecommender recommender;

    recommender.addMovie("Inception", "Sci-Fi", 4.8);
    recommender.addMovie("The Matrix", "Sci-Fi", 4.7);
    recommender.addMovie("Interstellar", "Sci-Fi", 4.6);
    recommender.addMovie("Drishyam", "Thriller", 4.5);
    recommender.addMovie("Badla", "Thriller", 4.2);
    recommender.addMovie("Andhadhun", "Thriller", 4.5);
    recommender.addMovie("Barfi!", "Drama", 4.8);
    recommender.addMovie("The Forrest Gump", "Drama", 4.8);
    recommender.addMovie("Pathaan", "Action", 4.3);
    recommender.addMovie("The Shawshank Redemption", "Drama", 4.9);
    recommender.addMovie("Saaho", "Action", 3.9);
    recommender.addMovie("Avengers:The Endgame", "Action", 4.8);

    string genre;
    cout << "Enter your preferred genre (e.g., Sci-Fi, Thriller, Drama, Action): ";
    cin >> genre;

    recommender.recommendMovies(genre);

    return 0;
}
