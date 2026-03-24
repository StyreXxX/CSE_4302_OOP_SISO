# Compiler
CXX = g++

# Flags
CXXFLAGS = -Wall -g -std=c++17

# Output
TARGET = earthquake_system

# Source files
SRCS = main.cpp \
       earthquakes_today.cpp \
       past_earthquakes.cpp \
       past_earthquake_record.cpp \
       earthquake_prediction.cpp \
       building_mapping.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Clean
clean:
	rm -f $(OBJS) $(TARGET) $(TARGET).exe