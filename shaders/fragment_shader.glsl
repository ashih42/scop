#version 400 core

#define				PI 3.141592653589793238462643383279

uniform bool		is_grayscale;
uniform bool		is_smooth_color;
uniform bool		is_default_uv;
uniform bool		is_light_on;
uniform float		percent_texture;
uniform sampler2D	amazing_texture;
uniform vec3		light_position;

uniform float		percent_specular;

in vec2				tex_coords;
in vec3				fixed_color;
in vec3				v_position;
in vec3				v_normal;

out vec4			frag_color;

float				compute_diffuse_intensity()
{
	vec3			vertex_to_light_source;
	float			intensity;

	vertex_to_light_source = light_position - v_position;
	vertex_to_light_source = normalize(vertex_to_light_source);
	intensity = dot(vertex_to_light_source, v_normal);
	intensity = clamp(intensity, 0.0f, 1.0/0.0);
	return intensity;
}

float				compute_specular_intensity()
{
	vec3			vertex_to_light_source;
	vec3			reflected_direction;
	vec3			view_direction;
	float			intensity;

	vertex_to_light_source = light_position - v_position;
	vertex_to_light_source = normalize(vertex_to_light_source);

	reflected_direction = 2.0 * dot(v_normal, vertex_to_light_source) *
		(v_normal - vertex_to_light_source);
	reflected_direction = normalize(reflected_direction);

	view_direction = vec3(0.0, 0.0, 1.0);

	intensity = dot(reflected_direction, view_direction);
	intensity = clamp(intensity, 0.0f, 1.0/0.0);
	return intensity;
}

vec2				compute_uv(vec3 position)
{
	position = normalize(position);
	return vec2(
		0.5 - atan(position.z, position.x) / (2.0 * PI),
		0.5 - asin(position.y) / PI);
}

vec4				compute_smooth_color(vec3 position)
{
	return vec4(normalize(position), 1.0);
}

vec4				compute_grayscale(vec4 color)
{
	float			avg;

	avg = (color.x + color.y + color.z) / 3.0;
	return vec4(avg, avg, avg, 1.0);
}

vec4				compute_shaded_color(vec4 color)
{
	vec4			diffuse_color;
	vec4			specular_color;
	vec4			light_source_color;

	light_source_color = vec4(1.0, 1.0, 1.0, 1.0);
	diffuse_color = compute_diffuse_intensity() * color;
	specular_color = compute_specular_intensity() * light_source_color;
	return diffuse_color + percent_specular * specular_color;
}

void main()
{
	vec4			textured_color;
	vec4			untextured_color;
	
	textured_color = texture(amazing_texture, is_default_uv ? compute_uv(v_position) : tex_coords);
	untextured_color = is_smooth_color ? compute_smooth_color(v_position) : vec4(fixed_color, 1.0);

	frag_color = mix(untextured_color, textured_color, percent_texture);

	if (is_light_on)
		frag_color = compute_shaded_color(frag_color);

	if (is_grayscale)
		frag_color = compute_grayscale(frag_color);
}
