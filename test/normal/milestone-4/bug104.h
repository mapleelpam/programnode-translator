/* THIS FILE IS GENREATED BY pn-translater, you should not modify this file.*/
/* NO LICNESE DECLARE */
// Auther : Unknown
#include <stdio.h>


namespace com{     class Vector2D  
    {
                int get__x( ) const { return _x;	}
        void set__x( int i ){ _x = i;	}

                int get__y( ) const { return _y;	}
        void set__y( int i ){ _y = i;	}

        private: int _x ;
        private: int _y ;
        public: 
        virtual ::com::Vector2D* clone();
        public: 
        virtual ::com::Vector2D* normalize();
        public: 
        static int angleBetween(::com::Vector2D* v1, ::com::Vector2D* v2);

        public: Vector2D()
        {}

    };
} /* com*/
