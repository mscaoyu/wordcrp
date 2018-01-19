#include <Sampler.h>
#include <math.h>
using namespace redbud;
Sampler::Sampler(const vector<long long unsigned>& fre):
				frequency_(fre),
                device_(),
                generator_(device_()),
                distribution_(0,static_cast<int>(fre.size()-1))
{

}

size_t Sampler::sample()
{
    int i =  distribution_(generator_);
    return roulette_[i]; 
}
void Sampler::init()
{
    double pow_total = 0;
    double power = 0.75;
    for(size_t i =0; i < frequency_.size(); ++i)
    {
        pow_total += pow(frequency_[i],power);
    }
    size_t i = 0;
    double d1 = pow(frequency_[i],power) / pow_total;
    size_t sz = frequency_.size();
    for(size_t a =0 ;a < sz;++a)
    {
        roulette_[a] = i;
        if(frequency_[a] / (double)sz > d1)
        {
            i++;
            d1 += pow(frequency_[i],power) / pow_total;
        }
        if(i >= sz)
        {
            i = sz -1;
        }
    }

}
