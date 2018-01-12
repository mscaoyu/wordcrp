#include <Sampler.h>
#include <math.h>
using namespace redbud;
Sampler::Sampler(const vector<long long unsigned>& fre):
                size_(fre.size()),
                device_(),
                generator_(device_()),
                distribution_(0,static_cast<int>(size_-1))
{
    init(fre);
}

size_t Sampler::sample()
{
    int i =  distribution_(generator_);
    return roulette_[i]; 
}
void Sampler::init(const vector<long long unsigned>& fre)
{
    double pow_total = 0;
    double power = 0.75;
    for(size_t i =0; i < fre.size(); ++i)
    {
        pow_total += pow(fre[i],power);
    }
    size_t i = 0;
    double d1 = pow(fre[i],power) / pow_total;
    size_t sz = fre.size();
    for(size_t a =0 ;a < sz;++a)
    {
        roulette_[a] = i;
        if(fre[a] / (double)sz > d1)
        {
            i++;
            d1 += pow(fre[i],power) / pow_total;
        }
        if(i >= sz)
        {
            i = sz -1;
        }
    }

}
