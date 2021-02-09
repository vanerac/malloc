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

BUILDDIR		=    obj

override OBJ	=		$(SRC:%.c=$(BUILDDIR)/%.o)

TRC				=		NULL

OTRC			=		$(TRC:%.c=%.o)

CFLAGS			=		-fPIC -Wall -Werror -Wextra -pedantic

CPPFLAGS		=		-Iinclude

LDFLAGS			=		-shared

NAME			=		 libmy_malloc.so


all: $(NAME)

$(NAME): $(OBJ)
	$(LINK.o) $(OBJ) -o $(NAME)

.SECONDEXPANSION:
$(BUILDDIR)/%.o:    override CPPFLAGS += -MT $@ -MMD -MP -MF $(@:.o=.d)
$(BUILDDIR)/%.o:	%.c | $$(@D)/.
	$(COMPILE.c) $(OUTPUT_OPTION) $<

$(BUILDDIR)/.:
	mkdir $@

$(BUILDDIR)%/.:
	mkdir -p $@

.PRECIOUS:            $(BUILDDIR)/. $(BUILDDIR)%/.

clean:
	$(RM) -r $(BUILDDIR)

fclean:	clean
	rm -rf $(NAME)

gclean:	fclean clean

re: gclean all

tests_run:	$(OTRC) $(OBJ)
	gcc -o unit_test $(OTRC) $(OBJ) $(CFLAGS) -lcriterion --coverage
	./unit_test

.PHONY:			gclean clean fclean re tests_run all
