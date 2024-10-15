#include "tests.h"

void Tests::testDynamicVector() {
    DynamicVector<Movie> da = DynamicVector<Movie>();
    da.test_construct();
    da.test_add();
    da.test_remove();
    da.test_size();
    da.test_resize();
    da.test_copy_constructor();
    da.test_operator_index();
}

void Tests::testRepository() {
    Repository repo = Repository();
    repo.test_construct_repo();
    repo.test_add_movie();
    repo.test_remove_movie();
    repo.test_update_movie();
    repo.test_get_intial_movies();
    repo.test_get_all_movies();
    repo.test_get_movies_by_genre();
}

void Tests::testController() {
    Controller controller = Controller();
    controller.test_construct_controller();
    controller.test_add_movie();
    controller.test_remove_movie();
    controller.test_update_movie();
    controller.test_get_movies_by_genre();
    controller.test_next_movie();
    controller.test_add_watchlist();
    controller.test_remove_watchlist();
}

void Tests::testMovies() {
    Movie movie;
    movie.test_constructor_and_getters();
    movie.test_setters();
    movie.test_operators();
}

void Tests::testAll() {
    testDynamicVector();
    testRepository();
    testController();
    testMovies();
    testWatchlist();
    std::cout<<"Tests passed successfully! \n"<<endl;
}

void Tests::testWatchlist() {
    Watchlist watchlist;
    watchlist.test_add_watchlist();
    watchlist.test_remove_watchlist();
    watchlist.test_get_watchlist();
    watchlist.test_operator_watchlist();
    watchlist.test_get_length();
}


