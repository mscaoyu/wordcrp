#ifndef TRAINER_H
#define TRAINER_H
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <Vocabulary.h>
#include <Sampler.h>
#include <FileReader.h>
#include <Parameter.h>
#include <vector>
namespace redbud
{
class Trainer:boost::noncopyable
{
	public:
		//parameter file and threshold is used by vocabulary
		//parmeter sigma is used by the sampler
		explicit Trainer(const char* file,long long unsigned threadhold,double sigma);
		~Trainer();
		void train();
	private:
		void init();
		boost::scoped_ptr<Vocabulary>  vocab_;
		boost::scoped_ptr<Sampler>     sampler_;
		boost::scoped_ptr<FileReader>  fileReader_;
		std::vector<Parameter>  	   parameters_;

};

}


#endif
