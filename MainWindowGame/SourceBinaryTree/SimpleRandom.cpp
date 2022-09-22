#include "SimpleRandom.h"
#include <random>

SimpleRandom::SimpleRandom()
{

}

qint32 SimpleRandom::getNumber(const qint32 min, const qint32 max)
{
    qint32 newRandomNumber;

    if(max <= 1)
        newRandomNumber = max;
    else
        newRandomNumber = generationNumber(min, max);

    return newRandomNumber;
}

qint32 SimpleRandom::generationNumber(const qint32 min, const qint32 max)
{
    std::mt19937_64 generator;
    std::uniform_int_distribution<qint32> distribution(min,max);
    qint32 newRandomNumber;

    while(true)
    {
        if(newRandomNumber = distribution(generator); checkOnCoincidences(newRandomNumber)){
            saveNewRandomNumber(newRandomNumber);
            break;
        }
    }

    return newRandomNumber;
}

bool SimpleRandom::checkOnCoincidences(const qint32 newRandomNumber)
{
    bool value = true;

    if(!oldRandomNumbers.empty())
        for(auto number: oldRandomNumbers)
            if(newRandomNumber == number){
                value = false;
                break;
            }

    return value;
}

void SimpleRandom::saveNewRandomNumber(const qint32 newRandomNumber)
{
    oldRandomNumbers.push_back(newRandomNumber);
}
