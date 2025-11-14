# =========================
# Makefile (42-friendly) - Version ultra-clean
# =========================

# --- Couleurs ANSI ---
RED   := \033[0;31m
GREEN := \033[0;32m
YELLOW:= \033[0;33m
BLUE  := \033[0;34m
NC    := \033[0m # No Color

# --- Configuration ---
NAME   := myprog
CC     := gcc
CFLAGS := -Wall -Wextra -Werror -I$(INCDIR) -MMD -MP
AR     := ar rcs

# --- Chemins ---
SRCDIR := src
INCDIR := header
OBJDIR := obj
LIBDIR := libft
LIBNAME:= libft.a
LIB    := $(LIBDIR)/$(LIBNAME)

# --- Sources et objets ---
SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

# --- Commandes utiles ---
LIBMAKE := $(MAKE) --no-print-directory -C $(LIBDIR)
RM      := rm -rf
MKDIR   := mkdir -p

# --- Phony targets ---
.PHONY: all clean fclean re libs libclean help

# --- Règles ---
all: libs $(NAME)

$(NAME): $(OBJS) $(LIB)
	@echo "$(BLUE)🔗 Linking $@...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBDIR) -l:$(LIBNAME) -o $@
	@echo "$(GREEN)✅ Built $@$(NC)"

libs:
	@echo "$(BLUE)📦 Building library in $(LIBDIR)...$(NC)"
	@$(LIBMAKE)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(MKDIR) $(dir $@)
	@echo "$(YELLOW)🔨 Compiling $< -> $@$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)🧹 Cleaning objects...$(NC)"
	@$(RM) $(OBJDIR)

libclean:
	@echo "$(RED)🧹 Cleaning lib in $(LIBDIR)...$(NC)"
	@$(LIBMAKE) clean

fclean: clean libclean
	@echo "$(RED)🗑️ Removing binary $(NAME) and library $(LIBNAME)...$(NC)"
	@$(RM) $(NAME) $(LIB)

re: fclean all

help:
	@echo "$(BLUE)=== Makefile Help ===$(NC)"
	@echo "$(BLUE)NAME:$(NC) $(NAME)"
	@echo "$(BLUE)SRCS:$(NC) $(SRCS)"
	@echo "$(BLUE)OBJS:$(NC) $(OBJS)"
	@echo "$(BLUE)LIB:$(NC) $(LIB)"
