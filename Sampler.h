#ifndef SAMPLER_H
#define SAMPLER_H
#include <boost/noncopyable.hpp>
#include <vector>
#include <random>
namespace redbud
{
using std::vector;
class Sampler:boost::noncopyable
{
    public:
        explicit Sampler(const vector<long long unsigned>& fre);
        ~Sampler() = default;
        size_t sample();
    private:
        void init(const vector<long long unsigned>& fre);
        vector<size_t>                      roulette_;
        size_t                              size_;
        std::random_device                  device_;
        std::mt19937                        generator_;
        std::uniform_int_distribution<int>     distribution_;
};
}

#endif
