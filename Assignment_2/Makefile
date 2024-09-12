SANFLAGS = -fsanitize=address
CXXFLAGS += -Wall -std=c++23 -g $(SANFLAGS)
LDFLAGS += $(SANFLAGS)

main:	main.o device.o manager.o
	$(CXX) -o $@ $^ $(LDFLAGS)

main.o:	main.cpp manager.h
manager.o:	manager.cpp manager.h
device.o:	device.cpp device.h