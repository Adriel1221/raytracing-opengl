#pragma once

#include "primitives.h"
#include <vector>

struct rt_defines
{
	int sphere_size;
	int plain_size;
	int light_point_size;
	int light_direct_size;
	int iterations;
	vec3 ambient_color;
	vec3 shadow_ambient;
};

typedef struct {
	vec3 color; float __p1;

	vec3 absorb;
	float diffuse;

	float reflect;
	float refract;
	int specular;
	float kd;

	float ks;
    float __padding[3];
} rt_material;

typedef struct {
	rt_material material;
	vec4 obj;
	//vec3 pos;
	//float radius;
} rt_sphere;

struct rt_plain {
	rt_material material;
    vec3 pos; float __p1;
	vec3 normal; float __p2;
};

typedef enum { sphere, light } primitiveType;

struct rt_light_direct {
	vec3 direction; float __p1;
	vec3 color;

	float intensity;
};

struct rt_light_point {
	vec4 pos; //pos + radius
	vec3 color;

	float intensity;
};

typedef struct {
    vec4 quat_camera_rotation;
	vec3 camera_pos; float __p1;

	vec3 bg_color;
	int canvas_width;

	int canvas_height;
	int reflect_depth;
	float __padding[2];

    //float __padding[1];
} rt_scene;

struct rotating_primitive
{
	int index;
	primitiveType type;
	vec4 pos;
	float a;
	float b;
	float current;
	float speed;
};

struct scene_container
{
	rt_scene scene;
	vec3 ambient_color;
	vec3 shadow_ambient;
	std::vector<rt_sphere> spheres;
	std::vector<rt_plain> plains;
	std::vector<rt_light_point> lights_point;
	std::vector<rt_light_direct> lights_direct;
	std::vector<rotating_primitive> rotating_primitives;

	rt_defines get_defines()
	{
		return {static_cast<int>(spheres.size()), static_cast<int>(plains.size()), static_cast<int>(lights_point.size()), static_cast<int>(lights_direct.size()), scene.reflect_depth, ambient_color, shadow_ambient};
	}
};