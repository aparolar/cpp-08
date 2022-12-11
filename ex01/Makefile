NAME		=	a.out

LDFLAGS		=	-fsanitize=address
42FLAGS		=	-Wall -Werror -Wextra -std=c++98 -pedantic
CXXFLAGS 	=	$(42FLAGS)
CXX			=	clang++
SRCS		=	main.cpp span.cpp
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

git_push:		fclean
				git status ; sleep 3
				git add .
				git commit -m "update"
				git push

.phony:			all re clean fclean
				
