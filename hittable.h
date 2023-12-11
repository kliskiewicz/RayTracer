#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"
#include "utilities.h"

class material;

class hit_record{ 
    // A data structure for ray-object interactions. 
    public:
        point3 p;
        vec3 normal;
        shared_ptr<material> mat;
        double t;
        double u;
        double v;
        bool front_face;

        void set_face_normal(const ray& r, const vec3& outward_normal){
            // Sets the normal vector to always point against the incident ray.
            front_face = dot(r.direction(), outward_normal) < 0;
            normal = front_face ? outward_normal : - outward_normal;
        }
};

class hittable{
    public:
        virtual ~hittable() = default;
        virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};
#endif
