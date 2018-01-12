#ifndef VOCABULARY_H
#define VOCABULARY_H
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>
#include <boost/scoped_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <FileReader.h>
namespace redbud
{
using std::unordered_map;
using std::string;
using std::vector;
struct VocabularyEntry
{
    long long unsigned cnt_;
    string              word_;
};
class Vocabulary: boost::noncopyable
{
    public:
        explicit Vocabulary(const char* file);
        ~Vocabulary() = default;
        void print() const;
        void build();
    private:
        void insert(const string& str);
        using EntryVector = vector<VocabularyEntry>;
        using HashTable = unordered_map<string,size_t>;
        EntryVector                             vocab_;
        HashTable                               table_;
        boost::scoped_ptr<FileReader>           fileReader_;

};
}


#endif
