#ifndef THREAD_H
#define THREAD_H

class SimpleBinaryTree;

class Thread
{
    public:
        Thread();
        SimpleBinaryTree* leftThread() const;
        SimpleBinaryTree* rightThread() const;
        void setLeftThread(SimpleBinaryTree* const parent);
        void setRightThread(SimpleBinaryTree* const parent);
    private:
        SimpleBinaryTree* leftReferanceOnParent;
        SimpleBinaryTree* rightReferanceOmParent;

};

#endif //THREAD_H
