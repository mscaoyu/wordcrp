#ifndef PARAMETER_H
#define PARAMETER_H
#include <eigen3/Eigen/Dense>
#include <vector>
#include <random>
#include <boost/shared_ptr.hpp>
#include <iomanip>
#define DIMENSION  10
namespace redbud
{
class Parameter
{
    public:
        explicit Parameter(double sigma);
        ~Parameter();
        void print() const;
        const auto& getMeanByIndex(size_t index) const
        {
            return means_[index];
        }
        const auto& getVarianceByIndex(size_t index) const
        {
            return variances_[index];
        }
        const auto& getContext() const
        {
            return context_;
        }
        size_t getNumTopics() const
        {
            return numtopics_;
        }
        size_t& getTopicTimersByIndex(size_t index)
        {
            return topicTimes_[index];
        }
        void addNewTopic();
    private:
        void init();
        using MeanVector =  std::vector<boost::shared_ptr<Eigen::VectorXd>>;
        using VarianceVector = std::vector<boost::shared_ptr<Eigen::MatrixXd>>; 
        MeanVector                  means_;
        VarianceVector              variances_;
        boost::shared_ptr<Eigen::VectorXd>      context_;
        size_t                      numtopics_;
        std::vector<size_t>         topicTimes_;
        double                      sigma_;
        std::random_device          device_;
        std::mt19937                generator_;
        std::normal_distribution<double>  normal_;
};
}



#endif
