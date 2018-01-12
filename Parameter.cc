#include <Parameter.h>
#include <iostream>
#include <stdio.h>
using namespace redbud;

Parameter::Parameter(double sigma):
            numtopics_(0),
            sigma_(sigma),
            device_(),
            generator_(device_()),
            normal_(0,sigma)
{
    init();
}
Parameter::~Parameter()
{

}

void Parameter::init()
{
    context_.reset(new Eigen::VectorXd(DIMENSION));
    for(int i = 0; i < DIMENSION; ++i)
    {
        double d = normal_(generator_);
        (*context_)(i) = d; 
    }
    boost::shared_ptr<Eigen::VectorXd> mean(new Eigen::VectorXd(DIMENSION));
    for(int i =0; i < DIMENSION; ++i)
    {
        double d = normal_(generator_);
        (*mean)(i) = d;
    }
    means_.emplace_back(mean);

    boost::shared_ptr<Eigen::MatrixXd> variance(new Eigen::MatrixXd(DIMENSION,DIMENSION));
    for(int i =0; i < DIMENSION; ++i)
    {
        double d = normal_(generator_);
        (*variance)(i,i) = d;
    }
    variances_.emplace_back(variance);
    
    ++numtopics_;
}

void Parameter::print() const
{
    printf("\nnow the word has %lu means\n",means_.size());
    for(size_t i = 0; i < means_.size(); ++i)
    {
        std::cout << *means_[i];
    }
    printf("\nnow the word has %lu variance\n",variances_.size());
    for(size_t i = 0 ; i < variances_.size(); ++i)
    {
        std::cout << *variances_[i];
    }
    printf("context vector is:\n");
    std::cout << *context_;
}

void Parameter::addNewTopic()
{
    boost::shared_ptr<Eigen::VectorXd> mean(new Eigen::VectorXd(DIMENSION));
    for(int i =0; i < DIMENSION; ++i)
    {
        double d = normal_(generator_);
        (*mean)(i) = d;
    }
    means_.emplace_back(mean);
    boost::shared_ptr<Eigen::MatrixXd> variance(new Eigen::MatrixXd(DIMENSION,DIMENSION));
    for(int i =0; i < DIMENSION ;++i)
    {
        double d = normal_(generator_);
        (*variance)(i,i) = d;
    }
    variances_.emplace_back(variance);
    
    ++numtopics_;

}
