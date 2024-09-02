SANFLAGS = -fsanitize=address
CXXFLAGS += -Wall -std=c++23 -g $(SANFLAGS)
LDFLAGS += $(SANFLAGS)

Task_1	: Task_1.o
	$(CXX) -o $@ $^ $(LDFLAGS)
