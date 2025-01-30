
NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBC = ar rcs

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlen.c ft_tolower.c \
		ft_toupper.c ft_strlcat.c ft_strlcpy.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
		ft_memchr.c ft_memcmp.c ft_strnstr.c ft_strdup.c ft_calloc.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_printf/*.c
SRCSBONUS = ft_lstnew.c ft_lstsize.c ft_lstadd_front.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
 
OBJS = $(SRCS:.c=.o)

OBJBONUS = $(SRCSBONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(FLAGS) -c $< -o $@

bonus: $(OBJS) $(OBJBONUS) 
	$(LIBC) $(NAME) $(OBJBONUS)

clean: 
	$(RM) $(OBJS) $(OBJBONUS)

fclean: clean
	$(RM) $(NAME) 

re: fclean all
