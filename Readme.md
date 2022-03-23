# Readme

Study project -- realisation of class "Fraction" on C++ and python.

## C++ realisation

To build the project use:
```
mkdir build && cd build
cmake ..
make
```
If you want to run main file, use:
```
./main
```
If you want to run unit tests, use:
```
./runUnitTests
```
If you want to clean current directory from executable files, use:
```
make clean
```

### Test coverage

Let's create info about test coverage. Firstly you need to go to the directory "test" and run special prepare script:
```
chmod +x run_tests.sh
./run_tests.sh
```
Directory named "report" will be created in curent directory (dir "test"). In this directory you need to open file index.html, after it you will able to view test coverage of file frac_class.hpp.

To clean workspace from useless files, go to ../ and execute special script named "clean.sh":
```
chmod +x clean.sh
./clean.sh
```

ATTENTION: after the running file "clean.sh" all info files include dir "report" in dir test will be deleted.

## Python realisation

File frac_class.py contain python realisation of class "Fraction".   
To run test file use:
```
python3 tests.py -v
```
We use _python coverage_ for output test coverage. If you want to veiw it, firstly you need to install nessesary package:
```
pip install coverage
```
Then you can use
```
coverage run tests.py && coverage report -m
```
and you will see detailed information about tests and test coverage.
```
----------------------------------------------------------------------
Ran 26 tests in 0.003s

OK (expected failures=21)
Name            Stmts   Miss  Cover   Missing
---------------------------------------------
frac_class.py     141      5    96%   34, 169, 175, 181, 190
tests.py          168      0   100%
---------------------------------------------
TOTAL             309      5    98%
```

### About GitHub Actions

In the directory .github/workfolws you can find file named main.yml. This is a script for GitHub actions, it creat a virtual machine and run python tests every time you push some commits to branch master. Status of last python tests you can veiw of the banner.

Status of last test:
<br><img src="https://github.com/pavel-collab/Computer-Technology-tasks-4-sem-MIPT/actions/workflows/main.yml/badge.svg"><br>