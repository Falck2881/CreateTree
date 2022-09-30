#include "Thread.h"
#include "SimpleBinaryTree.h"

Thread::Thread():leftReferanceOnParent(nullptr),rightReferanceOmParent(nullptr)
{

}

void Thread::setLeftThread(SimpleBinaryTree *const parent)
{
    leftReferanceOnParent = parent;
}

void Thread::setRightThread(SimpleBinaryTree *const parent)
{
    rightReferanceOmParent = parent;
}

SimpleBinaryTree* Thread::leftThread() const
{
    return leftReferanceOnParent;
}

SimpleBinaryTree* Thread::rightThread() const
{
    return rightReferanceOmParent;
}
