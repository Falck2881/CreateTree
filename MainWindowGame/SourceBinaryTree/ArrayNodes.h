#ifndef ARRAYNODES_H
#define ARRAYNODES_H

#include "SimpleRandom.h"
#include "GraphicsNode.h"
#include <QtGlobal>

    class ArrayNodes
    {
        public:
            ArrayNodes(const QString nameBuilder);
            virtual ~ArrayNodes() = default;
            bool empty();
            virtual GraphicsNode* moveData() = 0;
        private:
            void extractContent(const QString nameBuilder);
        protected:
            void clearOldReferenceOnData(const quint32 index);
            void updateArrayBoundaries(const qint32 min, const qint32 max);
            void updateIndex();
            quint32 getIndex();
            std::vector<GraphicsNode*> nodes;
            qint32 minSizeVector;
            qint32 maxSizeVector;
            quint32 currentIndex;
    };

    class ArrayNodesForRandomTree: public ArrayNodes
    {
        public:
            ArrayNodesForRandomTree(const QString nameBuilder);
        private:
            GraphicsNode* moveData() override final;
            SimpleRandom simplRandom;
    };

    class ArrayNodesForPBTTree: public ArrayNodes
    {
        public:
            ArrayNodesForPBTTree(const QString nameBuilder);
        private:
            void fillArrayAnIndexes(const qint32 leftEdge, const qint32 rightEdge);
            void sortingByInsertion(std::vector<GraphicsNode*>& nodes);
        private:
            GraphicsNode* moveData() override final;
            std::vector<qint32> arrIndex;
    };

    class LinearArrayNodes: public ArrayNodes
    {
        public:
            LinearArrayNodes(const QString nameBuilder);
        private:
            GraphicsNode* moveData() override final;
    };
#endif // ARRAYNODES_H
