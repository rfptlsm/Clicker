g_build=g++ -std=c++11 Clicker.cpp -o ./bin/main
g_run=./bin/main

default: build run	

build:
	@$(g_build)

run:
	@$(g_run)