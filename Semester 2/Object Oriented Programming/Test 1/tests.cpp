#include "tests.h"

void Test::test_add_repo() {
    Repository repo = Repository();
    repo.test_add();
}

void Test::test_add_controller() {
    Controller controller = Controller();
    controller.test_add();
}

void Test::testAll() {
    test_add_repo();
    test_add_controller();
}
