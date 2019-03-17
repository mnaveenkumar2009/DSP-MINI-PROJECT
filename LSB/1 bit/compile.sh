g++ -ggdb hider.cpp -o hider `pkg-config --cflags --libs opencv`
g++ -ggdb unhider.cpp -o unhider `pkg-config --cflags --libs opencv`
