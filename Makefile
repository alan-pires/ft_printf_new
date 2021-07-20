NAME = libftprintf.a
CC = clang
CFLAGS = -Wall -Wextra -Werror

INCLUDESDIR = ./includes
SRCDIR = ./src
OBJDIR = ./build

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft

INCLUDES = -I$(INCLUDESDIR) -I$(LIBFT_PATH)/includes
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

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $@
	@ar rcs $@ $(OBJS)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

$(OBJDIR)/%.o: $(BONUS_SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

clean:
	@make clean -C $(LIBFT_PATH)
	@$(RM) -r $(OBJDIR)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@$(RM) $(NAME)

re: fclean all

bonus: $(LIBFT) $(BONUS_OBJS)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(BONUS_OBJS)
