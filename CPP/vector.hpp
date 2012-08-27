/**
 * @file vector.hpp
 * Contains utility::vector.
 *
 * @details
 * This generic vector (size and type) allows both flexibility and
 * performance when vector algebra is needed. It is a header-only
 * implementation file.
 *
 * @author Jean-Marie Comets
 * @version 0.9
 * 
 * @section LICENSE
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @todo overload array-assignment operator (ex: v[2] = 5)
 * 
 */

//-------------------- Personal quick reference --------------------//

/* Syntax:
 *   "+" = implemented
 *   "-" = not implemented
 *
 * Constructors :
 * 	- vector({ array initializer list }) : parameter constructor
 * 	- vector(const vector &) : copy constructor
 * 
 * Methods :
 * 	+ T coord(int) const : getter
 * 	+ void setCoord(int, T) : setter
 * 	+ void copy(const vector &) : copy from vector
 * 	+ void add(const vector &) : adds with vector
 * 	+ void substract(const vector &) : substracts with vector
 * 	+ void multiply(T) : multiplication
 * 	+ void divide(T) : division
 * 	+ bool equals(const vector &) const : equal
 * 	+ T norm() const : get norm of vector
 * 	+ T dot(const vector &) const : dot-product
 * 	+ T angle(const vector &) const : argument
 * 	+ vector & unit() const : get corresponding unit vector (new one)
 * 
 * Operators :
 * 	+ "+" : add
 * 	+ "-" : substract
 * 	+ "*" : dot-product / multiplication
 * 	+ "/" : division
 * 	+ "^" : angle
 * 	+ "[]" : access
 * 	+ "=" : copy
 * 	+ "==" : equality
 * 	+ "!=" : difference
 *
 * Extra dump() method implemented as well
 * 
 */

//--------------------- Vector implementation ---------------------//

#ifndef VECTOR_H_INCLUDED_
#define VECTOR_H_INCLUDED_

#include <cmath>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <initializer_list>

namespace utility
{

/**
 * @brief generic vector class
 *
 * @tparam T
 * @tparam N
 */
template<class T, unsigned int N>
class vector
{
    private:
        /**
         * @brief array containing the vector's coordinates.
         */
        T _coords [N];
    public:
        /**
         * @brief constructs from iniliatizer list
         *
         * @param coords
         */
        inline vector(std::initializer_list<T> coords)
        {
            copy(coords);
        }

        /**
         * @brief copy constructor
         *
         * @param v
         */
        inline vector(const vector & v)
        {
            copy(v);
        }

        /**
         * @brief destructor
         */
        inline virtual ~vector()
        {
        }

        /**
         * @brief gets coordinates (indexed from 0)
         *
         * @param index
         *
         * @return the index'th coordinate
         */
        inline T coord(unsigned int index) const
        {
            if (index >= N)
            {
                throw std::out_of_range("Given index is out of bounds");
            }
            return _coords[index];
        }

        /**
         * @brief sets coordinates (indexed from 0)
         *
         * @param index
         * @param value
         */
        inline void setCoord(unsigned int index, T value)
        {
            if (index >= N)
            {
                throw std::out_of_range("Given index is out of bounds");
            }
            _coords[index] = value;
        }

        /**
         * @brief copies from initializer list
         *
         * @param coords
         */
        inline void copy(std::initializer_list<T> coords)
        {
            if (coords.size() != N)
            {
                throw std::length_error("Given size is different from vector's");
            }
            std::copy(coords.begin(), coords.end(), _coords);
        }

        /**
         * @brief copies from other vector
         *
         * @param v
         */
        inline void copy(const vector & v)
        {
            for (unsigned int i = 0; i < N; ++i)
            {
                _coords[i] = v._coords[i];
            }
        }

        /**
         * @brief checks equality with other vector
         *
         * @param v
         *
         * @return 
         */
        inline bool equals(const vector & v) const
        {
            for (unsigned int i = 0; i < N; ++i)
            {
                if (_coords[i] != v._coords[i])
                {
                    return false;
                }
            }
            return true;
        }

        /**
         * @brief adds with given vector
         *
         * @param v
         */
        inline void add(const vector & v)
        {
            for (unsigned int i = 0; i < N; ++i)
            {
                _coords[i] += v._coords[i];
            }
        }

        /**
         * @brief substracts with given vector
         *
         * @param v
         */
        inline void substract(const vector & v)
        {
            for (unsigned int i = 0; i < N; ++i)
            {
                _coords[i] -= v._coords[i];
            }
        }

        /**
         * @brief multiplies with given parameter (generic)
         *
         * @param c
         */
        inline void multiply(T c)
        {
            for (unsigned int i = 0; i < N; ++i)
            {
                _coords[i] *= c;
            }
        }

        /**
         * @brief divides by given parameter (generic)
         *
         * @param c
         */
        inline void divide(T c)
        {	
            if (c == 0)
            {
                throw std::overflow_error("Cannot divide by zero");
            }
            for (unsigned int i = 0; i < N; ++i)
            {
                _coords[i] /= c;
            }
        }

        /**
         * @brief computes the dot product with given vector
         *
         * @param v
         *
         * @return the dot product < current | given >
         */
        inline T dot(const vector & v) const
        {
            T dprod = 0;
            for (unsigned int i = 0; i < N; ++i)
            {
                dprod += _coords[i] * v._coords[i];
            }
            return dprod;
        }

        /**
         * @brief computes the norm of the vector
         *
         * @return the norm of the vector
         */
        inline T norm() const
        {
            return std::sqrt(dot(*this));
        }

        /**
         * @brief computes the angle with given vector
         *
         * @param v
         *
         * @return the angle (current, given) in radians
         */
        inline T angle(const vector & v) const
        {
            if (norm() == 0 || v.norm() == 0)
            {
                throw std::overflow_error("Cannot compute angle with null vector");
            }
            return std::acos(dot(v) / (norm() * v.norm()));
        }

        /**
         * @brief gets the corresponding unit vector
         *
         * @return a new colinear unit vector
         */
        inline vector & unit() const
        {
            std::auto_ptr<vector<T, N>> v(new vector<T, N>(*this));
            v->divide(v->norm());
            return *v;
        }

        /**
         * @brief overloads the assignment operator for initializer list
         *
         * @param coords
         *
         * @return the reference to current vector
         */
        inline vector & operator=(std::initializer_list<T> coords)
        {
            copy(coords);
            return *this;
        }

        /**
         * @brief overloads the assignment operator for vector
         *
         * @param v
         *
         * @return the reference to current vector
         */
        inline vector & operator=(const vector & v)
        {
            if (this != &v)
            {
                copy(v);
            }
            return *this;
        }

        /**
         * @brief overloads the "+=" operator (alias for add())
         *
         * @param v
         *
         * @return the reference to current vector
         */
        inline vector & operator+=(const vector & v)
        {
            add(v);
            return *this;
        }

        /**
         * @brief overloads the "-=" operator (alias for substract())
         *
         * @param v
         *
         * @return the reference to current vector
         */
        inline vector & operator-=(const vector & v)
        {
            substract(v);
            return *this;
        }

        /**
         * @brief overloads "*=" operator (alias for multiply())
         *
         * @param a
         *
         * @return the reference to current vector
         */
        inline vector & operator*=(T a)
        {
            multiply(a);
            return *this;
        }

        /**
         * @brief overloads the "/=" operator (alias for divide())
         *
         * @param a
         *
         * @return the reference to current vector
         */
        inline vector & operator/=(T a)
        {
            divide(a);
            return *this;
        }

        /**
         * @brief overloads the "*" operator (alias for dot())
         *
         * @param v
         *
         * @return the dot product with given vector
         */
        inline T operator*(const vector & v) const
        {
            return dot(v);
        }

        /**
         * @brief overloads the "^" operator (alias for angle())
         *
         * @param v
         *
         * @return the angle with given vector
         */
        inline T operator^(const vector & v) const
        {
            return angle(v);
        }

        /**
         * @brief overloads the "[]" operator (alias for coord())
         *
         * @param index
         *
         * @return the coordinate asked for
         */
        inline T operator[](int index) const
        {
            return coord(index);
        }

        /**
         * @brief overloads the "==" operator (alias for equals())
         *
         * @param v
         *
         * @return if vectors are equal
         */
        inline bool operator==(const vector & v) const
        {
            return equals(v);
        }

        /**
         * @brief overloads the "!=" operator (alias for !equals())
         *
         * @param v
         *
         * @return if vectors are different
         */
        inline bool operator!=(const vector & v) const
        {
            return !equals(v);
        }
}; // class vector

/**
 * @brief dumps the given vector in standard output stream
 *
 * @tparam T
 * @tparam N
 * @param v
 */
template<class T, unsigned int N> inline void dump(const vector<T, N> & v)
{
    using std::cout;
    using std::endl;
    cout << "utility::vector at " << &v << " (";
    for (unsigned int i = 0; i < N; ++i)
    {
        cout << v[i];
        if (i < N - 1)
        {
            cout << ", ";
        }
    }
    cout << ")" << endl;
}

} // namespace utility

#endif // VECTOR_H_INCLUDED_
