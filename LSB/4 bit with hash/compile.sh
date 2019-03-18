g++ -ggdb hashgen.cpp -o hashgen `pkg-config --cflags --libs opencv`
g++ -ggdb hider.cpp -o hider `pkg-config --cflags --libs opencv`
g++ -ggdb unhider.cpp -o unhider `pkg-config --cflags --libs opencv`
g++ -ggdb imagetest.cpp -o imagetest `pkg-config --cflags --libs opencv`


# g++ -E -x c -P -C -traditional-cpp hider.cpp > code_after.cpp `pkg-config --cflags --libs opencv`