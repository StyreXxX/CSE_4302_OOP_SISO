# The C++ compiler
CXX = g++

CXXFLAGS = -Wall -g

TARGET = earthquake_system

SRCS = main.cpp \
       earthquakes_today.cpp \
       past_earthquakes.cpp \
       earthquake_prediction.cpp \
       building_mapping.cpp

OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET).exe