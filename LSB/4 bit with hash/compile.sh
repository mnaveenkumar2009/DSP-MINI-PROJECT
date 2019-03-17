g++ -ggdb hashgen.cpp -o hashgen `pkg-config --cflags --libs opencv`
g++ -ggdb hider.cpp -o hider `pkg-config --cflags --libs opencv`
g++ -ggdb unhider.cpp -o unhider `pkg-config --cflags --libs opencv`
g++ -ggdb memetest.cpp -o memetest `pkg-config --cflags --libs opencv`