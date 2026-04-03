test:
    mkdir -p build
    g++ -std=c++23 -I./include ./tests/test.cpp -o ./build/test && ./build/test
