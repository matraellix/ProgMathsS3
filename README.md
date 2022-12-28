# ProgMathsS3
This project is a library of rationals coded by Olivia Crépin and Maëlle Fleitz
We suggest that you use an IDE such as Visual Studio Code

## Install dependencies

## To compile this project, you should use CMAKE
## How to install CMAKE
-Linux : sudo apt install cmake
-Mac : brew install cmake
-Windows : https://cmake.org/install

## to compile CMAKE without visual studio code extensions
-for the first time :
cd project_directory
mkdir build
cd build
cmake ..
make
-then : 
make


## How to install google Test
# Google Test
- gitHub: [source](https://github.com/google/googletest)
- gitHub: [readme](https://github.com/google/googletest/blob/master/README.md)
- documentation:[doc](https://github.com/google/googletest/blob/master/googletest/docs/primer.md#simple-tests)
- other documentation : [doc](https://developer.ibm.com/technologies/systems/articles/au-googletestingframework)


# Install

-mac
```
sudo apt-get install libgtest-dev
```

-mac
```
cd /tmp
git clone https://github.com/google/googletest.git
cd googletest
mkdir build && cd build
cmake ..
make && sudo make install
```
-windows : https://www.doxygen.nl/manual/install.html 