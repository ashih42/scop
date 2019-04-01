/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 23:04:31 by ashih             #+#    #+#             */
/*   Updated: 2018/10/30 09:25:50 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

// # include <glad/glad.h>
# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include <stdbool.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <float.h>
# include "libft.h"

# define ERROR_OBJ_LINE		"Invalid expression in OBJ file"
# define ERROR_FILE_EXT		"Invalid file format (only accept *.obj)"
# define ERROR_USAGE		"usage: scop model.obj"
# define ERROR_GL			"Some kind of OpenGL error"
# define ERROR_SHADER		"Shader error"
# define ERROR_MEMORY		"Out of memory"
# define ERROR_OPEN_FILE	"Cannot open file"
# define ERROR_CLOSE_FILE	"Cannot close file"

# define SCREEN_WIDTH		800
# define SCREEN_HEIGHT		800
# define ASPECT_RATIO		((float)SCREEN_WIDTH / (float)SCREEN_HEIGHT)
# define FOV_DEGREES		45.0f
# define NEAR_PLANE			0.1f
# define FAR_PLANE			100.0f

# define SCALE_INC			1.02f
# define SCALE_DEC			0.98f
# define ROTATE_INC			2
# define TRANSLATE_INC		0.05f

# define PERCENT_TEX_INC	0.01f

# define NUM_TEXTURES		6
# define TEX_FILE_0			"textures/doge_rainbow.ppm"
# define TEX_FILE_1			"textures/kitten.ppm"
# define TEX_FILE_2			"textures/ponies.ppm"
# define TEX_FILE_3			"textures/unicorn.ppm"
# define TEX_FILE_4			"textures/scop.ppm"
# define TEX_FILE_5			"textures/mlu.ppm"

# define INVALID_VT			-1
# define INVALID_VN			-1

# define SQ(x)				((x) * (x))
# define DEG_TO_RAD(x)		((x) * (float)M_PI / 180.0f)
# define MIN(a, b)			((a) < (b) ? (a) : (b))
# define MAX(a, b)			((a) > (b) ? (a) : (b))
# define CLAMP(x, min, max)	((x) = MIN(MAX((min), (x)), (max)))

# define STRIDE_LEN			14

typedef struct				s_vec3
{
	float					x;
	float					y;
	float					z;
}							t_vec3;

typedef struct				s_vec2
{
	float					x;
	float					y;
}							t_vec2;

typedef struct				s_obj
{
	size_t					line_num;

	t_list					*v_list;
	t_list					*vt_list;
	t_list					*vn_list;
	t_list					*triangle_list;

	float					x_min;
	float					x_max;
	float					y_min;
	float					y_max;
	float					z_min;
	float					z_max;

	int						v_count;
	int						vt_count;
	int						vn_count;
	int						triangle_count;

	t_vec3					*v_array;
	t_vec2					*vt_array;
	t_vec3					*vn_array;

}							t_obj;

typedef struct				s_triangle
{
	int						v_1;
	int						v_2;
	int						v_3;
	int						vt_1;
	int						vt_2;
	int						vt_3;
	int						vn_1;
	int						vn_2;
	int						vn_3;
	t_vec3					my_color;
	t_vec3					my_normal;
}							t_triangle;

typedef struct				s_master
{
	GLFWwindow				*window;
	unsigned int			shader_id;
	char					*path;

	t_obj					obj;
	float					*gl_data;

	int						current_texture_index;
	float					percent_texture;

	int						is_wireframe;
	int						is_perspective;
	int						is_spinning;
	int						is_grayscale;
	int						is_smooth_color;
	int						is_default_uv;
	t_vec3					light_position;
	int						is_light_on;
	float					percent_specular;
	int						is_my_normal;

	unsigned int			texture_id[NUM_TEXTURES];
	unsigned int			is_grayscale_loc;
	unsigned int			percent_texture_loc;
	unsigned int			transform_matrix_loc;
	unsigned int			is_smooth_color_loc;
	unsigned int			is_default_uv_loc;
	unsigned int			light_position_loc;
	unsigned int			is_light_on_loc;
	unsigned int			percent_specular_loc;
	unsigned int			is_my_normal_loc;

	int						degrees_rotate_x;
	int						degrees_rotate_y;
	int						degrees_rotate_z;

	float					scale_x;
	float					scale_y;
	float					scale_z;

	float					translate_x;
	float					translate_y;
	float					translate_z;

}							t_master;

/*
** copy_triangles_to_gl_data.c
*/
int							copy_triangles_to_gl_data(t_master *m, t_obj *obj, t_list *triangle_list);


/*
** debug.c
*/
void						print_triangles(t_obj *obj);


/*
** generate_gl_data.c
*/
int							generate_gl_data(t_master *m, t_obj *obj);

/*
** generate_normal.c
*/
t_vec3						generate_normal(t_vec3 *v1, t_vec3 *v2, t_vec3 *v3);

/*
** get_triangle_point_v_vt_vn_str.c
*/
int							get_triangle_point_v_vt_vn_str(char *str, char **v_str, char **vt_str, char **vn_str);

/*
** handle_f_line.c
*/
int							handle_f_line(char *line, t_obj *obj);

/*
** handle_triangle_point.c
*/
int							handle_triangle_point(char *str, int *v, int *vt, int *vn);

/*
** handle_v_line.c
*/
int							handle_v_line(char *line, t_obj *obj);

/*
** handle_vn_line.c
*/
int							handle_vn_line(char *line, t_obj *obj);

/*
** handle_vt_line.c
*/
int							handle_vt_line(char *line, t_obj *obj);

/*
** init_open_gl.c
*/
int							init_open_gl(t_master *m);

/*
** init_shaders.c
*/
int							init_shaders(t_master *m);

/*
** init_textures.c
*/
int							init_textures(t_master *m);

/*
** init_vertex_objects.c
*/
int							init_vertex_objects(t_master *m);

/*
** key_callback.c
*/
void						reset_scop_params(t_master *m);
void						key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

/*
** light_position_dec.c
*/
void						dec_light_position_x(t_master *m);
void						dec_light_position_y(t_master *m);
void						dec_light_position_z(t_master *m);

/*
** light_position_inc.c
*/
void						inc_light_position_x(t_master *m);
void						inc_light_position_y(t_master *m);
void						inc_light_position_z(t_master *m);

/*
** matrix_operations_1.c
*/
void						print_matrix(float m[4][4]);
void						matrix_multiply(float a[4][4], float b[4][4]);
void						init_identity_matrix(float m[4][4]);
void						init_orthographic_projection_matrix(float m[4][4]);
void						init_perspective_projection_matrix(float m[4][4]);

/*
** matrix_operations_2.c
*/
void						init_scaling_matrix(float m[4][4], float scale_x, float scale_y, float scale_z);
void						init_translation_matrix(float m[4][4], float translate_x, float translate_y, float translate_z);
void						init_rotation_x_matrix(float m[4][4], float radians);
void						init_rotation_y_matrix(float m[4][4], float radians);
void						init_rotation_z_matrix(float m[4][4], float radians);

/*
** parse_obj_file.c
*/
int							parse_obj_file(char *filename, t_obj *obj);

/*
** parse_ppm_file.c
*/
unsigned char				*parse_ppm_file(char *path, char *filename, int *width, int *height);

/*
** percent_texture.c
*/
void						inc_percent_texture(t_master *m);
void						dec_percent_texture(t_master *m);

/*
** process_key_held_input.c
*/
void						inc_rotate_x(t_master *m);
void						inc_rotate_y(t_master *m);
void						inc_rotate_z(t_master *m);
void						process_key_held_input(t_master *m);

/*
** rotate_dec.c
*/
void						clamp_degrees(int *degrees);
void						dec_rotate_x(t_master *m);
void						dec_rotate_y(t_master *m);
void						dec_rotate_z(t_master *m);

/*
** rotate_inc.c
*/
void						inc_rotate_x(t_master *m);
void						inc_rotate_y(t_master *m);
void						inc_rotate_z(t_master *m);

/*
** scale_dec.c
*/
void						dec_scale_x(t_master *m);
void						dec_scale_y(t_master *m);
void						dec_scale_z(t_master *m);
void						dec_scale_universal(t_master *m);

/*
** scale_inc.c
*/
void						inc_scale_x(t_master *m);
void						inc_scale_y(t_master *m);
void						inc_scale_z(t_master *m);
void						inc_scale_universal(t_master *m);

/*
** set_transform_matrix.c
*/
void						set_transform_matrix(t_master *m);

/*
** terminate.c
*/
void						terminate(t_master *m);

/*
** toggles.c
*/
void						toggle_wireframe_mode(t_master *m);
void						toggle_grayscale(t_master *m);
void						toggle_smooth_color(t_master *m);
void						toggle_default_uv(t_master *m);
void						toggle_light_on(t_master *m);
void						toggle_my_normal(t_master *m);

/*
** translate_dec.c
*/
void						dec_translate_x(t_master *m);
void						dec_translate_y(t_master *m);
void						dec_translate_z(t_master *m);

/*
** translate_inc.c
*/
void						inc_translate_x(t_master *m);
void						inc_translate_y(t_master *m);
void						inc_translate_z(t_master *m);

#endif
