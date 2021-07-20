NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -fPIC
INCLUDESDIR = ./includes
SRCDIR = ./src
OBJDIR = ./objects
LIBFT = ./libft/libft.a
LIBFT_FLAGS = -L ./libft -lft

INCLUDES = -I$(INCLUDESDIR) -I ./libft/includes
SRCS = ft_printf.c ft_printf_unsi_int.c ft_printf_unsi_hex.c \
		ft_printf_point.c ft_printf_char.c  ft_send_format.c \
		ft_printf_str.c ft_printf_int.c ft_printf_utils.c \
		ft_printf_options.c ft_printf_percent.c
OBJS := $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS := $(addprefix $(SRCDIR)/,$(SRCS))

BONUS_SRCDIR = ./bonus
BONUS_SRCS = ft_printf_bonus.c ft_check_flags_bonus.c ft_printf_unsi_int_bonus.c \
		ft_printf_unsi_hex_bonus.c ft_printf_point_bonus.c ft_printf_char_bonus.c \
		ft_send_format_bonus.c ft_printf_str_bonus.c ft_printf_int_bonus.c \
		ft_printf_utils1_bonus.c ft_printf_utils2_bonus.c ft_check_errors_bonus.c \
		ft_printf_options_bonus.c ft_printf_iuxs_bonus.c ft_printf_percent_bonus.c
BONUS_OBJS := $(addprefix $(OBJDIR)/,$(BONUS_SRCS:.c=.o))
BONUS_SRCS := $(addprefix $(BONUS_SRCDIR)/,$(BONUS_SRCS))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C ./libft

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) $(INCLUDES) $< -c -o $@

$(OBJDIR)/%.o: $(BONUS_SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) $(INCLUDES) $< -c -o $@

clean:
	make clean -C ./libft
	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

bonus: $(LIBFT) $(BONUS_OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(BONUS_OBJS)
