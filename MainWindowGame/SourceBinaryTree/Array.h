#ifndef ARRAYNODES_H
#define ARRAYNODES_H

#include "SimpleRandom.h"
#include "GraphicsNode.h"
#include <QtGlobal>

class GameWindow;

    class Array
    {
        public:
            Array(const QString nameBuilder);
            virtual ~Array();
            bool empty();
            virtual GraphicsNode* getData() = 0;
        protected:
            std::vector<GraphicsNode*> arrItems;
    };

    class ArrayForRandomTree: public Array
    {
        public:
            ArrayForRandomTree(const QString nameBuilder);
        private:
            GraphicsNode* getData() override final;
            SimpleRandom simplRandom;
    };

    class ArrayForPBTTree: public Array
    {
        public:
            ArrayForPBTTree(const QString nameBuilder);
        private:
            void fillArrayAnIndexes(const qint32 leftEdge, const qint32 rightEdge);
            void sortingByInsertion(std::vector<GraphicsNode*>& nodes);
        private:
            GraphicsNode* getData() override final;
            std::vector<qint32> arrIndex;
            std::vector<qint32>::iterator currIndex;
    };

    class LinearArray: public Array
    {
        public:
            LinearArray(const QString nameBuilder);
        private:
            GraphicsNode* getData() override final;
            std::vector<GraphicsNode*>::iterator currItem;

    };
#endif // ARRAYNODES_H
