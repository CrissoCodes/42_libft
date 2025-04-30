NAME :=	libft.a
OBJS_DIR :=	objs


SRCS_LIBFT :=	ft_atoi.c \
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
DEPS_LIBFT :=	libft.h
OBJS_LIBFT :=	$(SRCS_LIBFT:%.c=$(OBJS_DIR)/%.o)


PRINTF_DIR :=	ft_printf
SRCS_PRINTF :=	$(PRINTF_DIR)/ft_printf.c \
				$(PRINTF_DIR)/ft_printf_parsing.c \
				$(PRINTF_DIR)/ft_printf_to_str.c
DEPS_PRINTF :=	libft.h \
				$(PRINTF_DIR)/ft_printf.h \
				$(PRINTF_DIR)/ft_printf_parsing.h \
				$(PRINTF_DIR)/ft_printf_to_str.h
OBJS_PRINTF :=	$(SRCS_PRINTF:%.c=$(OBJS_DIR)/%.o)


GNL_DIR :=	gnl




SRCS := $(SRCS_LIBFT) $(SRCS_PRINTF) $(SRCS_GNL)
OBJS := $(OBJS_LIBFT) $(OBJS_PRINTF) $(OBJS_GNL)

CC = cc
CWARN = -Wall -Wextra -Werror
CINCLUDES = -I. -I$(PRINTF_DIR) -I$(GNL_DIR)
CFLAGS = $(CWARN) $(CINCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): $(OBJS_DIR)/%.o: %.c $(DEPS) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
	mkdir -p $(OBJS_DIR)/$(PRINTF_DIR)
	mkdir -p $(OBJS_DIR)/$(GNL_DIR)

clean:
	rm -f $(OBJS)
	rm -df $(OBJS_DIR)/$(PRINTF_DIR)
	rm -df $(OBJS_DIR)/$(GNL_DIR)
	rm -df $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re bonus all
