CXX= g++
exec = sexo
sources = $(wildcard src/*.cpp)
objects = $(sources:.cpp=.o)
flags = -g


$(exec): $(objects)
	g++ $(objects) $(flags) -o $(exec)

%.o: %.cpp include/%.hpp
	g++ -c $(flags) $< -o $@

install-linux:
	make
	cp ./sexo /usr/local/bin/hello

install-termux:
	make
	cp ./sexo /data/data/com.termux/files/usr/bin/sexo

clean:
	-rm src/*.o sexo
