#ifndef SIMPLERANDOM_H
#define SIMPLERANDOM_H

#include <QtGlobal>
#include <vector>

class SimpleRandom
{
    public:
        SimpleRandom();
        qint32 getNumber(const qint32 min, const qint32 max);
        quint32 quantityOfGeneratedNumbers() const;
    private:
        qint32 generationNumber(const qint32 min, const qint32 max);
        bool checkOnCoincidences(const qint32 newRandomNumber);
        void saveNewRandomNumber(const qint32 newRandomNumber);
    private:
        std::vector<qint32> oldRandomNumbers;
};

#endif // SIMPLERANDOM_H
