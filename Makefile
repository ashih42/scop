CC = gcc

TARGET = scop

# GLAD build obtained from https://glad.dav1d.de/
GLAD_LOC := ./GLAD
GLAD_INC := $(GLAD_LOC)/include
GLAD_SRC := $(GLAD_LOC)/src
GLAD_TARGET := $(GLAD_LOC)/glad.o

GLFW_LOC := $(shell brew --prefix glfw)
GLFW_INC := $(GLFW_LOC)/include
GLFW_LINK := -L $(GLFW_LOC)/lib -lglfw

LIBFT := libft
LIBFT_INC := $(LIBFT)/includes
LIBFT_LIB := $(LIBFT)/libft.a

CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address

INCLUDES = includes/
HEADERS = -I $(INCLUDES) -I $(LIBFT_INC) -I $(GLFW_INC) -I $(GLAD_INC)

SRCDIR = srcs/
SRCS = \
copy_triangles_to_gl_data.c \
debug.c \
generate_gl_data.c \
generate_normal.c \
get_triangle_point_v_vt_vn_str.c \
handle_f_line.c \
handle_triangle_point.c \
handle_v_line.c \
handle_vn_line.c \
handle_vt_line.c \
init_open_gl.c \
init_shaders.c \
init_textures.c \
init_vertex_objects.c \
key_callback.c \
light_position_dec.c \
light_position_inc.c \
main.c \
matrix_operations_1.c \
matrix_operations_2.c \
parse_obj_file.c \
parse_ppm_file.c \
percent_texture.c \
process_key_held_input.c \
rotate_dec.c \
rotate_inc.c \
scale_dec.c \
scale_inc.c \
set_transform_matrix.c \
terminate.c \
toggles.c \
translate_dec.c \
translate_inc.c \

OBJDIR = objs/
OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

# all: glfw $(LIBFT_LIB) $(GLAD_TARGET) $(TARGET)
all: $(LIBFT_LIB) $(GLAD_TARGET) $(TARGET)

glfw:
	@echo "\x1b[1mInstalling GLFW library...\x1b[0m"
	@HOMEBREW_NO_AUTO_UPDATE=1 brew install glfw
	@echo

$(LIBFT_LIB):
	@echo "\x1b[1mBuilding $(LIBFT) library...\x1b[0m"
	@make -C $(LIBFT)
	@echo

$(GLAD_TARGET):
	@echo "\x1b[1mBuilding $(GLAD_TARGET)...\x1b[0m"
	gcc $(GLAD_SRC)/glad.c -c -I $(GLAD_INC)
	mv glad.o $(GLAD_LOC)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAGS) $(HEADERS) $< -o $@

$(TARGET): $(OBJS)
	@echo "\x1b[1mBuilding $(TARGET)...\x1b[0m"
	$(CC) -o $(TARGET) $(OBJS) $(GLAD_TARGET) -L$(LIBFT) -lft $(GLFW_LINK) #-fsanitize=address
	@echo "\x1b[1mBuild finished!!\x1b[0m"

clean:
	@echo "\x1b[1mCleaning...\x1b[0m"
#	make -C $(LIBFT) clean
	/bin/rm -rf $(OBJDIR)
	@echo

fclean: clean
	@echo "\x1b[1mFcleaning...\x1b[0m"
	/bin/rm -f $(TARGET)
#	/bin/rm -f $(LIBFT_LIB)
	/bin/rm -f $(GLAD_TARGET)
	@echo

re: fclean all

.PHONY: all clean fclean re glfw
