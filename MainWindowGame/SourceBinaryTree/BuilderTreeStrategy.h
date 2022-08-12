#ifndef BUILDERTREESTRATEGY_H
#define BUILDERTREESTRATEGY_H

#include "NodeProxy.h"
#include "Tree.h"

class BuilderTreeStrategy
{
    public:
        BuilderTreeStrategy() = default;
        virtual ~BuilderTreeStrategy() = default;
        virtual void createTree(std::vector<std::unique_ptr<NodeProxy>>) = 0;
        virtual const Tree* getTree() const = 0;
};

#endif // BUILDERTREESTRATEGY_H
