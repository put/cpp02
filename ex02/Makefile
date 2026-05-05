CXX := c++
CXXFLAGS := -std=c++11 -Wall -Wextra -Werror

NAME := ex02
FILES := Fixed.cpp Fixed.hpp main.cpp
SRCS := Fixed.cpp main.cpp
OBJS := $(SRCS:.cpp=.o)
RM := rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Fixed.o: Fixed.hpp

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re