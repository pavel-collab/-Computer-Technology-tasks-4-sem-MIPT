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

Status of last Deployment:<br>
<img src="http://github.com/adv4000/Computer-Technology-tasks-4-sem-MIPT/workflows/Run-tests-on-any-Push-event_to_master/bandge.svg?branch=master"><br>