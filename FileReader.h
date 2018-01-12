#ifndef FILE_READER_H
#define FILE_READER_H
#include <stdio.h>
#include <boost/noncopyable.hpp>
namespace redbud
{
class FileReader:boost::noncopyable
{
public:
    static const int MAX_WORD_SIZE = 128;
    explicit FileReader(const char* file);
    ~FileReader();
    int readWord(char* word);
    bool isEof() const
    {
        return feof(fin_) != 0;
    }
private:
    FILE*   fin_;
};
}

#endif
