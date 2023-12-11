# Read Me

To generate photorealistic images, there's no need to simulate self-propagating electromagnetic waves. Instead, a more computationally efficient approach is to leverage equations developed in the 16th and 17th century that model light as particles traveling along rays. This repository contains a simple ray tracer based on a few fundamental physical laws.

The rendering algorithm begins by generating viewing rays that originate from the camera and pass through each pixel of the image. Rays impart colour to pixels based on their interactions with objects in the environment that one wishes to capture. Each object in the scene holds information regarding its appearance, how light interacts with its surface, as well as the nature of the reradiated or scattered light.

# Notes

**vec3 3D Vector Class:**
Used for representing locations, directions, offsets, and colors in the project.
Implements double precision for enhanced accuracy and a wider numerical range.
Consider using floats for memory optimization (half the size of doubles) if memory constraints are a concern.

**hit_record for Ray Interaction:**
Utilizes the hit_record structure as a convenient way to encapsulate and manage information about each ray interaction.
Streamlines the process of storing and retrieving details related to ray-object intersections.

**Lambertian Objects:**
Lambertian objects in the project scatter light based on their albedo.
Albedo is specified during their construction but is a private variable, enhancing encapsulation.
Color Averaging for Softening Edges:

To soften the harsh lines of an object, the colour of a given pixel is determined by averaging the colours of a small square region centred on the pixel.

# Usage
1. Clone the repository:
```
git clone https://github.com/kliskiewicz/RayTracer.git
cd ray_tracer
```
2. Compile with Cmake:
```
cmake --build build
```
3. Render ppm image:
```
build/ray_tracer.exe > image.ppm
```
