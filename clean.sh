rm -r __pycache__
rm -r build
rm -r .vscode
rm .coverage

cd test
rm test_go *.gcno *.info *.gcda
rm -r report