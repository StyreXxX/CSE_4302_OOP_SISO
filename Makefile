CXX = g++
CXXFLAGS = -Wall -g -std=c++17

TARGET = earthquake_system.exe

# This automatically grabs EVERY .cpp file in your current folder
SRCS = $(wildcard *.cpp)

OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

run: $(TARGET)
	.\$(TARGET)

clean:
	del /Q *.o $(TARGET) 2>nul