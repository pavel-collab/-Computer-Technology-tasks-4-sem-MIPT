g++ --coverage test.cpp -std=c++17 -lgtest -lgtest_main -lpthread -o test_go
./test_go
lcov -t "test_go" -o test.info -c -d . --rc lcov_branch_coverage=1 --rc lcov_function_coverage=1
genhtml -o report test.info