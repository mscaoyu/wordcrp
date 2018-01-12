#ifndef INITIALIZATION_H
#define INITIALIZATION_H
#include <string>

namespace wordcrp
{
using std::string;
class VocabularyEntry
{
    public:
    explicit VocabularyEntry(const string& word);
    ~VocabularyEntry();
    long long getCount() const
    {
        return cnt_;
    }
    string getWord() const
    {
        return word_;
    }
    private:
        long long           cnt_;
        string              word_;
};
class Initialization
{
    public:
    Initialization();
    ~Initialization();

};
class StringHasher
{
    public:
        explicit StringHasher(int hash);
        ~StringHasher();
        int operator()(const std string& str);
    private:
        int                     hash_;
};
}


#endif
