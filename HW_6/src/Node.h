#if !defined(_Node_)
#define _Node_

#include <iostream>
#include <memory>

namespace GTU_171044024
{
    using std::shared_ptr;
    
    template<typename T>
    class Node
    {
        public:
            
            Node( shared_ptr< Node<T> > outNext  , shared_ptr< Node<T> > outPrevious )
                : next(outNext) , previos(outPrevious)
            { /* Intentionall left blank */}

            T data;
            shared_ptr< Node<T> > next;
            shared_ptr< Node<T> > previos;
    };
}

#endif