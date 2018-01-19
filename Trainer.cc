#include <Trainer.h>
using namespace redbud;

Trainer::Trainer(const char* file,long long unsigned threashold,double sigma):
		vocab_(new Vocabulary(file,threashold)),
		fileReader_(new FileReader(file))
{

}
Trainer::~Trainer()
{
	vocab_->init();
	vector<long long unsigned> fre = vocab_->getFrequency();

}
void Trainer::init()
{
	vocab_->init();
	sampler_.reset(new Sampler(vocab_->getFrequency()));
	sampler_->init();
}
void Trainer::train()
{

}

