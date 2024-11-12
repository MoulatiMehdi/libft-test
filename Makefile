# Variables
CC = @gcc
CFLAGS = -Wall -Wextra  -g -O0 
RM = @rm
RMFLAGS = -rf


DIR_FUNC := $(CURDIR)
DIR_TEST = $(HOME)/libft-test
TEST_SRCS = $(DIR_TEST)/srcs
TEST_UTILS = $(DIR_TEST)/utils

SRCS = $(wildcard $(DIR_FUNC)/ft_*.c)
UTILS= $(wildcard $(TEST_UTILS)/*.c)

TEST_FILES = $(wildcard $(TEST_SRCS)/*.c)
TEST_BINS = $(TEST_FILES:.c=.out)

INCLUDES = $(DIR_TEST)/includes $(DIR_FUNC)/

FUNCTIONS = $(patsubst $(TEST_SRCS)/test_%.c,%,$(TEST_FILES))

all : $(TEST_BINS) 

%.out : %.c
	$(CC) $(CFLAGS) $< $(SRCS) $(UTILS) -o $@ $(addprefix -I,$(INCLUDES));
	@$@ ;
	$(RM) $(RMFLAGS) $(TEST_BINS) ;
	$(RM) $(RMFLAGS) $(addsuffix .dSYM,$(TEST_BINS));

# Pattern rule for generating executable from the given function name
define compile_test
$(CC) $(CFLAGS) $(TEST_SRCS)/test_$(1).c $(SRCS) $(UTILS) -o $(1)_test $(addprefix -I,$(INCLUDES))
endef

$(foreach func, $(FUNCTIONS), \
$(eval $(func): ; $(call compile_test,$(func)) ; ./$(func)_test ; rm $(RMFLAGS) ./$(func)_test* ;))



# Rule to clean generated binaries
clean:
	$(RM) $(RMFLAGS) $(TEST_BINS) ;
	$(RM) $(RMFLAGS) $(addsuffix .dSYM,$(TEST_BINS));

.PHONY: clean re all
