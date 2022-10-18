#ifndef ARRAYNODES_H
#define ARRAYNODES_H

#include "SimpleRandom.h"
#include "GraphicsNode.h"
#include <QtGlobal>

class GameWindow;

    class ArrayNodes
    {
        public:
            ArrayNodes(const QString nameBuilder);
            virtual ~ArrayNodes();
            bool empty();
            virtual GraphicsNode* getData() = 0;
        private:
            void extractContent(const QString nameBuilder);
        protected:
            std::vector<GraphicsNode*> nodes;
    };

    class ArrayNodesForRandomTree: public ArrayNodes
    {
        public:
            ArrayNodesForRandomTree(const QString nameBuilder);
        private:
            GraphicsNode* getData() override final;
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
            GraphicsNode* getData() override final;
            std::vector<qint32> arrIndex;
            std::vector<qint32>::iterator currIndex;
    };

    class LinearArrayNodes: public ArrayNodes
    {
        public:
            LinearArrayNodes(const QString nameBuilder);
        private:
            GraphicsNode* getData() override final;
            std::vector<GraphicsNode*>::iterator currNode;
    };
#endif // ARRAYNODES_H
