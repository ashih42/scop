#version 400 core

uniform bool					is_my_normal;
uniform mat4					transform_matrix;

layout (location = 0) in vec3	position;
layout (location = 1) in vec2	tex_coords_uv;
layout (location = 2) in vec3	color;
layout (location = 3) in vec3	my_normal;
layout (location = 4) in vec3	their_normal;

out vec2						tex_coords;
out vec3						fixed_color;
out	vec3						v_position;
out vec3						v_normal;

void main()
{
	gl_Position = transform_matrix * vec4(position, 1.0);
	tex_coords = tex_coords_uv;
	fixed_color = color;
	v_position = position;
	v_normal = is_my_normal ? my_normal : their_normal;
}
