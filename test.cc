#include <Vocabulary.h>
#include <unordered_map>
#include <Parameter.h>
#include <string>
#include <iostream>
using namespace redbud;
using namespace std;
int main()
{
    Parameter par(2);
    par.print();
    printf("\n");
    printf("now the topic numbers is %lu\n",par.getNumTopics());
    par.addNewTopic();
    par.print();
}
