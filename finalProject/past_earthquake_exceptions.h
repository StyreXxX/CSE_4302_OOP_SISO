#ifndef PAST_EARTHQUAKE_EXCEPTIONS_H
#define PAST_EARTHQUAKE_EXCEPTIONS_H

#include <bits/stdc++.h>
using namespace std;

class FileOpenException : public exception {
private:
    string message;
public:
    FileOpenException(const string& filename) {
        message = "Could not open file: " + filename;
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InvalidRecordFormatException : public exception {
private:
    string message;
public:
    InvalidRecordFormatException(const string& line) {
        message = "Invalid record format found in line: " + line;
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InvalidInputException : public exception {
private:
    string message;
public:
    InvalidInputException(const string& msg) {
        message = msg;
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class RecordNotFoundException : public exception {
private:
    string message;
public:
    RecordNotFoundException(const string& msg) {
        message = msg;
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif