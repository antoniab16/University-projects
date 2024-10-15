#pragma once
#include <fstream>
#include "dynamic_array.h"
class FileWriter {
public:
    virtual void writeToFile(std::string filename, DynamicVector<Movie> movies) = 0;
    virtual void displayFile(std::string filename) = 0;
};

class CSVWriter : public FileWriter {
public:
    void writeToFile(std::string filename, DynamicVector<Movie> movies) override;
    void displayFile(std::string filename) override;
};

class HTMLWriter : public FileWriter{
public:
    void writeToFile(std::string filename, DynamicVector<Movie> movies) override;
    void displayFile(std::string filename) override;
};