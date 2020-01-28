#if !defined(_EXCEPTIONS_)
#define _EXCEPTIONS_
#include <iostream>

namespace GTU_171044024
{
    using std::string;
    using std::cout;
    using std::cerr;
    using std::endl;

    class Exceptions
    {
        public:
        
            Exceptions(const string& error  )
                : errorPhrase( error )
                {
                    /* Intentionally left blank */
                }
                
            const string& getErrorPhrase() const
            {
                return errorPhrase;
            }

        private:

            string errorPhrase;

    };
}

namespace std
{
    class bad_pafram
    {
        public:

            bad_pafram( const string& error )
                : errorPhrase( error )
            {
                /* Intentionally left blank */
            }

            const string& getErrorPhrase() const
            {
                return errorPhrase;
            }

        private:

            string errorPhrase;
    };
}

#endif