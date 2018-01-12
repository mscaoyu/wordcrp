#include <Vocabulary.h>
#include <FileReader.h>
using namespace redbud;
#include <iostream>
using namespace std;

Vocabulary::Vocabulary(const char* file):fileReader_(new FileReader(file))
{
}
void Vocabulary::insert(const string& word)
{
    if(table_.find(word) == table_.end())
    {
        table_[word] = vocab_.size();
        VocabularyEntry entry;
        entry.cnt_ = 1;
        entry.word_ = word;
        vocab_.push_back(entry);
    }
    else
    {
        size_t w = table_[word];
        vocab_[w].cnt_++;
    }
}
void Vocabulary::print() const
{
    for(int i =0; i < vocab_.size(); ++i)
    {
        cout<< vocab_[i].word_ << " "<< vocab_[i].cnt_ << endl;
    }
    for(auto s:table_)
    {
        cout << s.first << " " << s.second << endl;
    }
}
void Vocabulary::build()
{
    while(1)
    {
        char buf[FileReader::MAX_WORD_SIZE];
        fileReader_->readWord(buf);
        if(fileReader_->isEof())
        {
            break;
        }
        insert(string(buf));
    }

}
