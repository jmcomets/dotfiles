/**
 * @file vector.hpp
 * Contains Bundle::Vector.
 *
 * @details
 * This generic vector (size and type) allows both flexibility and
 * performance when vector algebra is needed.
 *
 * @author Jean-Marie Comets
 * @version 1.0
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
 */

#ifndef VECTOR_H_INCLUDED_
#define VECTOR_H_INCLUDED_

#include <cmath>
#include <stdexcept>
#include <iostream>
#include <algorithm>

#ifdef __GXX_EXPERIMENTAL_CXX0X__
#  include <initializer_list>
#endif

namespace Bundle
{

/**
 * @brief generic vector class
 *
 * @tparam T
 * @tparam N
 */
template<class T, std::size_t N>
    class Vector
{
    public:
        /**
         * @breif constructs and initializes to value
         *
         * @param value (default is 0)
         */
        Vector(T value = 0)
        {
            for (std::size_t i = 0; i < N; i++)
            {
                coords_[i] = value;
            }
        }

#ifdef __GXX_EXPERIMENTAL_CXX0X__
        /**
         * @brief constructs from initializer list
         *
         * @param coords
         */
        Vector(std::initializer_list<T> coords)
        {
            Copy(coords);
        }
#endif // __GXX_EXPERIMENTAL_CXX0X__

        /**
         * @brief copy constructor
         *
         * @param v
         */
        Vector(const Vector & v)
        {
            Copy(v);
        }

        /**
         * @brief destructor
         */
        virtual ~Vector()
        {
        }

        /**
         * @brief gets coordinates (indexed from 0)
         *
         * @param index
         *
         * @return the index'th coordinate
         */
        T Coord(std::size_t index)
        {
            if (index >= N)
            {
                throw std::out_of_range("Given index is out of bounds");
            }
            return coords_[index];
        }

        /**
         * @brief const gets coordinates (indexed from 0)
         *
         * @param index
         *
         * @return the index'th coordinate
         */
        T Coord(std::size_t index) const
        {
            if (index >= N)
            {
                throw std::out_of_range("Given index is out of bounds");
            }
            return coords_[index];
        }

        /**
         * @brief copies from other Vector
         *
         * @param v
         */
        void Copy(const Vector & v)
        {
            for (std::size_t i = 0; i < N; ++i)
            {
                coords_[i] = v.coords_[i];
            }
        }

        /**
         * @brief checks equality with other Vector
         *
         * @param v
         *
         * @return
         */
        bool Equals(const Vector & v) const
        {
            for (std::size_t i = 0; i < N; ++i)
            {
                if (coords_[i] != v.coords_[i])
                {
                    return false;
                }
            }
            return true;
        }

        /**
         * @brief adds with given Vector
         *
         * @param v
         */
        void Add(const Vector & v)
        {
            for (std::size_t i = 0; i < N; ++i)
            {
                coords_[i] += v.coords_[i];
            }
        }

        /**
         * @brief substracts with given Vector
         *
         * @param v
         */
        void Substract(const Vector & v)
        {
            for (std::size_t i = 0; i < N; ++i)
            {
                coords_[i] -= v.coords_[i];
            }
        }

        /**
         * @brief multiplies with given parameter (generic)
         *
         * @param c
         */
        void Multiply(T c)
        {
            for (std::size_t i = 0; i < N; ++i)
            {
                coords_[i] *= c;
            }
        }

        /**
         * @brief divides by given parameter (generic)
         *
         * @param c
         */
        void Divide(T c)
        {
            if (c == 0)
            {
                throw std::overflow_error("Cannot divide by zero");
            }
            for (std::size_t i = 0; i < N; ++i)
            {
                coords_[i] /= c;
            }
        }

        /**
         * @brief computes the dot product with given Vector
         *
         * @param v
         *
         * @return the dot product < current | given >
         */
        T Dot(const Vector & v) const
        {
            T dprod = 0;
            for (std::size_t i = 0; i < N; ++i)
            {
                dprod += coords_[i] * v.coords_[i];
            }
            return dprod;
        }

        /**
         * @brief computes the norm of the Vector
         *
         * @return the norm of the Vector
         */
        T Norm() const
        {
            return std::sqrt(Dot(*this));
        }

        /**
         * @brief computes the angle with given Vector
         *
         * @param v
         *
         * @return the angle (current, given) in radians
         */
        T Angle(const Vector & v) const
        {
            if (Norm() == 0 || v.Norm() == 0)
            {
                throw std::overflow_error("Cannot compute angle with null Vector");
            }
            return std::acos(Dot(v) / (Norm() * v.Norm()));
        }

        /**
         * @brief gets the corresponding unit Vector
         *
         * @return a collinear unit Vector
         */
        Vector Unit() const
        {
            Vector<T, N> v(*this);
            v.Divide(v.Norm());
            return v;
        }

        /**
         * @brief overloads the assignment operator for Vector
         *
         * @param v
         *
         * @return the reference to current Vector
         */
        inline Vector & operator=(const Vector & v)
        {
            if (this != &v)
            {
                copy(v);
            }
            return *this;
        }

        /**
         * @brief overloads the "+=" operator
         *
         * @param v
         *
         * @return the reference to current Vector
         */
        inline Vector & operator+=(const Vector & v)
        {
            Add(v);
            return *this;
        }

        /**
         * @brief overloads the "-=" operator
         *
         * @param v
         *
         * @return the reference to current Vector
         */
        inline Vector & operator-=(const Vector & v)
        {
            Substract(v);
            return *this;
        }

        /**
         * @brief overloads "*=" operator
         *
         * @param a
         *
         * @return the reference to current Vector
         */
        inline Vector & operator*=(T a)
        {
            Multiply(a);
            return *this;
        }

        /**
         * @brief overloads the "/=" operator
         *
         * @param a
         *
         * @return the reference to current Vector
         */
        inline Vector & operator/=(T a)
        {
            Divide(a);
            return *this;
        }

        /**
         * @brief overloads the "*" operator
         *
         * @param v
         *
         * @return the dot product with given Vector
         */
        inline T operator*(const Vector & v) const
        {
            return Dot(v);
        }

        /**
         * @brief overloads the "^" operator
         *
         * @param v
         *
         * @return the angle with given Vector
         */
        inline T operator^(const Vector & v) const
        {
            return Angle(v);
        }

        /**
         * @brief overloads the "[]" operator
         *
         * @param index
         *
         * @return the coordinate asked for
         */
        inline T & operator[](int index)
        {
            return Coord(index);
        }

        /**
         * @brief const overload of the "[]" operator
         *
         * @param index
         *
         * @return the coordinate asked for
         */
        inline T operator[](int index) const
        {
            return Coord(index);
        }

        /**
         * @brief overloads the "==" operator
         *
         * @param v
         *
         * @return if vectors are equal
         */
        inline bool operator==(const Vector & v) const
        {
            return Equals(v);
        }

        /**
         * @brief overloads the "!=" operator
         *
         * @param v
         *
         * @return if vectors are different
         */
        inline bool operator!=(const Vector & v) const
        {
            return !(*this == v);
        }

    private:
        /**
         * @brief array containing the Vector's coordinates.
         */
        T coords_ [N];
};

/**
 * @brief dumps the given Vector in standard output stream
 *
 * @tparam T
 * @tparam N
 * @param v
 */
template<class T, std::size_t N>
    inline void dump(const Vector<T, N> & v)
{
    using std::cout;
    using std::endl;
    cout << "Bundle::Vector at " << &v << " (";
    for (std::size_t i = 0; i < N; ++i)
    {
        cout << v[i];
        if (i < N - 1)
        {
            cout << ", ";
        }
    }
    cout << ")" << endl;
}

}

#endif
