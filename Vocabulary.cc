#include <Vocabulary.h>
#include <FileReader.h>
#include <iostream>
using namespace redbud;

Vocabulary::Vocabulary(const char* file,long long unsigned threashold):
			fileReader_(new FileReader(file)),
			threashold_(threashold)
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
    for(size_t i =0; i < vocab_.size(); ++i)
    {
        std::cout<< vocab_[i].word_ << " "<< vocab_[i].cnt_ << std::endl;
    }
    for(auto s:table_)
    {
        std::cout << s.first << " " << s.second << std::endl;
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
void Vocabulary::filter()
{
	EntryVector    newVocab;
	HashTable      newTable;
	for(size_t i = 0; i < vocab_.size(); ++i)
	{
	    VocabularyEntry entry = vocab_[i];
	    if(entry.cnt_ >= threashold_)
	    {
			newTable[entry.word_] = newVocab.size();
			newVocab.push_back(entry);
	  		frequency_.push_back(entry.cnt_);
		}
	}
	vocab_ = std::move(newVocab);
	table_ = std::move(newTable);
}
size_t Vocabulary::findWord(const string& word)
{
	return table_[word];
}
void Vocabulary::init()
{
	build();
	filter();
}
vector<long long unsigned> Vocabulary::getFrequency() const
{
	return frequency_;
}
