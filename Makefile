CXX = g++
CXXFLAGS = -Wall -g -std=c++17

TARGET = earthquake_system.exe

SRCS = main.cpp \
       earthquakes_today.cpp \
       past_earthquakes.cpp \
       past_earthquake_record.cpp \
       earthquake_prediction.cpp \
       building_mapping.cpp

OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

run: $(TARGET)
	.\$(TARGET)

clean:
	del /Q *.o $(TARGET) 2>nul