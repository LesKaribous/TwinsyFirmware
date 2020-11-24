#include "Core.h"

enum class Origin{
    RELATIVE,
    ABSOLUTE,
};

template<typename T>
struct Vec2{
    T x,y;

    T dotProduct(Vec2 vecB){
        T product = 0; 
        product += x * vecB.x;
        product += y * vecB.y; 
        return product; 
    }

    T& operator[](int i){
        if     (i == 0) return x;
        else if(i == 1) return y;
        else{
            Debugger::assert("Index out ouf bound", __FILE__, __LINE__);
        }
    }
};

template<typename T>
struct Vec3{
    T x,y,z;

    Vec3<T> crossProduct( Vec3 vecB){
        Vec3<T> result;
        result.x = y * vecB.z - z * vecB.y; 
        result.y = z * vecB.x - x * vecB.z; 
        result.z = x * vecB.y - y * vecB.x; 
        return result;
    }

    T dotProduct(Vec3 vecB){
        T product = 0; 

        product += x * vecB.x;
        product += y * vecB.y; 
        product += z * vecB.z; 

        return product; 
    }

    T& operator[](int i){
        if     (i == 0) return x;
        else if(i == 1) return y;
        else if(i == 2) return z;
        else{
            Debugger::assert("Index out ouf bound", __FILE__, __LINE__);
        }
    }
};
