NAME		=	a.out
42FLAGS		=	-Wall -Werror -Wextra -std=c++98 -pedantic
LDFLAGS		=	-fsanitize=address
CXXFLAGS 	=	$(42FLAGS)
CXX			=	clang++
SRCS		=	main.cpp
OBJS		=	$(SRCS:.cpp=.o)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

all:			$(NAME)

re:				fclean all

clean:			
				@rm -f *.o

fclean:			clean
				@rm -fr .vscode
				@rm -f $(NAME)

.phony:			all re clean fclean
				
