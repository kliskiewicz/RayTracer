#include "utilities.h"
#include "camera.h"
#include "hittable_list.h"
#include "sphere.h"
#include "color.h"
#include "material.h"
#include "texture.h"

int main() {
    hittable_list world;

    auto checker = make_shared<checker_texture>(0.32, color(0.0, 0.0, 0.0), color(1.0, 1.0, 1.0));
    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, make_shared<lambertian>(checker)));

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            auto choose_mat = random_double();
            point3 center(a + 0.9*random_double(), 0.2, b + 0.9*random_double());

            world.add(make_shared<sphere>(center, 0.4*choose_mat, make_shared<dielectric>(1.5)));
        }
    }

    auto material3 = make_shared<metal>(color(0.9, 0.9, 0.9), 0.0);
    world.add(make_shared<sphere>(point3(-1, 1, 0), 1.0, material3));
    camera cam;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 10; //1200
    cam.samples_per_pixel = 50; //500
    cam.max_depth         = 50;

    cam.vfov     = 10;
    cam.lookfrom = point3(15,3,2);
    cam.lookat   = point3(0,0,0);
    cam.vup      = vec3(0,1,0);

    cam.defocus_angle = 0.6;
    cam.focus_dist    = 10.0;

    cam.render(world);
}