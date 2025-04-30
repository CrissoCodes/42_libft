NAME := libft.a

SRCS := ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstadd_back_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstmap_bonus.c \
		ft_lstnew_bonus.c \
		ft_lstsize_bonus.c

DEPS := libft.h
OBJS_DIR := ./objs
OBJS := $(SRCS:%.c=$(OBJS_DIR)/%.o)
BASE_SRCS := $(filter-out %_bonus.c, $(SRCS))
BASE_OBJS := $(BASE_SRCS:%.c=$(OBJS_DIR)/%.o)
BONUS_SRCS := $(filter %_bonus.c, $(SRCS))
BONUS_OBJS := $(BONUS_SRCS:%.c=$(OBJS_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME) $(BASE_OBJS)

$(NAME): $(BASE_OBJS)
	ar rcs $(NAME) $(BASE_OBJS)

bonus: $(BONUS_OBJS) $(NAME)
	ar rcs $(NAME) $(BONUS_OBJS)

$(OBJS_DIR)/%.o: %.c $(DEPS) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p objs

clean:
	rm -f $(OBJS)
	rm -df $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re bonus all
