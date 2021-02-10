##
## EPITECH PROJECT, 2019
## base_repo
## File description:
## Makefile file
##


SRC				=		src/calloc.c	\
						src/free.c		\
						src/malloc.c	\
						src/realloc.c	\
						src/utils.c

BUILDDIR		=    	build

override OBJ	=		$(SRC:%.c=$(BUILDDIR)/%.o)

TRC				=		NULL

OTRC			=		$(TRC:%.c=%.o)

CFLAGS			=		-fPIC -Wall -Werror -Wextra -std=gnu99

CPPFLAGS		=		-Iinclude

NAME			=		 libmy_malloc.so

LDFLAGS			=		-shared -Wl,-soname,$(NAME)

all: $(NAME) ## hoes mad

$(NAME): $(OBJ)
	$(LINK.o) $^ $(LDLIBS) $(OUTPUT_OPTION)

.SECONDEXPANSION:
$(BUILDDIR)/%.o:    override CPPFLAGS += -MT $@ -MMD -MP -MF $(@:.o=.d)
$(BUILDDIR)/%.o:	%.c | $$(@D)/.
	$(COMPILE.c) $(OUTPUT_OPTION) $<

$(BUILDDIR)/.:
	mkdir $@

$(BUILDDIR)%/.:
	mkdir -p $@

.PRECIOUS:            $(BUILDDIR)/. $(BUILDDIR)%/.

clean: ## rm build obj
	$(RM) -r $(BUILDDIR)

fclean:	clean ## clean + rm $(NAME)
	rm -rf $(NAME)

gclean:	fclean clean ## ?

re: gclean all ## Re

tests_run:	$(OTRC) $(OBJ) ## Run Tests
	gcc -o unit_test $(OTRC) $(OBJ) $(CFLAGS) -lcriterion --coverage
	./unit_test

help:                                                        ## Print every help in the terminal
		@printf "USAGE:\n\n"
		@grep -E "^[a-zA-Z\\_]+:.*## " Makefile | awk 'BEGIN {FS = ":.*## "}; {printf "%-30s\033[36m%s\033[0m\n", $$1, $$2}'

.PHONY:			gclean clean fclean re tests_run all help
