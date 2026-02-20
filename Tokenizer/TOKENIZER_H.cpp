#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string.h>
#include <stringstream.h>

class Tokenizer{
    private:
        stringstream ss;
        string str;
    public:
        Tokenizer();
        Tokenizer(string str);

        bool readWord(string &val);
        bool readInteger(int &val);
        bool readDouble(double &val);
        bool readLine(string &val);

        void setString(constant string &val);
        void clear();
        void rewind();
        bool isEmpty(); 
}

#endif