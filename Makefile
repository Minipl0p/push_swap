# Nom de l'exécutable
NAME = push_swap

# Compilateur et flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Recherche automatique des fichiers .c
SRC = $(shell find -name "*.c")
OBJ = $(SRC:%.c=%.o)

# Commandes
RM = rm -rf

# Règle principale
all: $(LIBFT) $(NAME)

# Compilation de l’exécutable
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -I. -L$(LIBFT_DIR) -o $(NAME)
	@echo "Compilation terminée : $(NAME)"

# Compilation des .o
%.o: %.c
	@$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

# Compilation de la libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Nettoyage des objets
clean:
	@$(RM) %.o
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Fichiers objets supprimés"

# Nettoyage complet
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Tout a été supprimé"

# Recompilation totale
re: fclean all

.PHONY: all clean fclean re

