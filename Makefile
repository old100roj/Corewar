CC := gcc
CFLAGS = -Wall -Wextra -Werror -O3

#**********************Corewar VM*****************************

VM_NAME := corewar
VM_DIR = vm/

VM_SRC_DIR := sources/
VM_INC_DIR := includes/
VM_OBJ_DIR := objects/

VM_SRC_DIR := $(addprefix $(VM_DIR), $(VM_SRC_DIR))
VM_INC_DIR := $(addprefix $(VM_DIR), $(VM_INC_DIR))
VM_OBJ_DIR := $(addprefix $(VM_DIR), $(VM_OBJ_DIR))

VM_LIBFT_DIR := libft/
VM_LIBFT_DIR := $(addprefix $(VM_DIR), $(VM_LIBFT_DIR))
VM_LIBFT := $(VM_LIBFT_DIR)libft.a
VM_LIBFT_INC := $(VM_LIBFT_DIR)inc/

VM_LFT_FLAGS := -lft -L $(VM_LIBFT_DIR)
NCURSES_FLAGS = -lncurses

VM_INC := \
corewar_op.h \
corewar_vm.h \
vm_errors.h \
visu.h

VM_INC := $(addprefix $(VM_INC_DIR), $(VM_INC))

VM_SRC := \
arena_io.c \
carriage.c \
commands/add.c \
commands/aff.c \
commands/and.c \
commands/fork.c \
commands/ld.c \
commands/ldi.c \
commands/lfork.c \
commands/live.c \
commands/lld.c \
commands/lldi.c \
commands/or.c \
commands/st.c \
commands/sti.c \
commands/sub.c \
commands/utils/op_args.c \
commands/utils/op_argtypes.c \
commands/utils/op_utils.c \
commands/xor.c \
commands/zjmp.c \
corewar.c \
corewar_args.c \
corewar_dump.c \
corewar_echo.c \
corewar_error.c \
corewar_op.c \
corewar_options.c \
corewar_utils.c \
cycle_check.c \
cycle_exec_ops.c \
cycle_main.c \
cycle_reset.c \
memory_free.c \
player_parsing.c \
player_validation.c \
vm_setup.c \
visu.c \
visu_utils.c

VM_OBJ := $(addprefix $(VM_OBJ_DIR), $(VM_SRC:.c=.o))

VM_INC_FLAGS := -I$(VM_INC_DIR) -I$(VM_LIBFT_INC) -I$(VM_LIBFT_INC)ft_printf/

#**********************ASM*****************************

ASM_NAME = asm
ASM_DIR = assembler/

ASM_SRC_DIR := src/
ASM_INC_DIR := inc/
ASM_OBJ_DIR := obj/

ASM_SRC_DIR := $(addprefix $(ASM_DIR), $(ASM_SRC_DIR))
ASM_INC_DIR := $(addprefix $(ASM_DIR), $(ASM_INC_DIR))
ASM_OBJ_DIR := $(addprefix $(ASM_DIR), $(ASM_OBJ_DIR))

ASM_LIBFT_DIR := libftprintf/
ASM_LIBFT_DIR := $(addprefix $(ASM_DIR), $(ASM_LIBFT_DIR))
ASM_LIBFT := $(ASM_LIBFT_DIR)libftprintf.a
ASM_LIBFT_INC := $(ASM_LIBFT_DIR)inc/

ASM_LFT_FLAGS := -lftprintf -L$(ASM_LIBFT_DIR)

ASM_INC = \
asm.h \
op.h

ASM_INC := $(addprefix $(ASM_INC_DIR), $(ASM_INC))

ASM_SRC = \
add_dir_or_indir.c \
add_operation.c \
count_operation_size.c \
ft_handle_errors.c \
ft_parse_operations.c \
ft_split_line.c \
main.c \
make_code.c \
make_header.c \
op.c \
parse_line.c

ASM_OBJ := $(addprefix $(ASM_OBJ_DIR), $(ASM_SRC:.c=.o))

ASM_INC_FLAGS := -I$(ASM_INC_DIR) -I$(ASM_LIBFT_INC)

all: $(VM_NAME) $(ASM_NAME)

$(VM_NAME): $(VM_LIBFT) $(VM_OBJ_DIR) $(VM_OBJ)
	@printf "\033[0;33m"
	$(CC) $(VM_OBJ) -o $(VM_NAME) $(VM_INC_FLAGS) $(VM_LFT_FLAGS) $(NCURSES_FLAGS)
	@printf "\033[0;32m$(VM_NAME) compiled\n\033[0m";

$(VM_OBJ_DIR):
	@ mkdir -p $(VM_OBJ_DIR)
	@ mkdir -p $(dir $(VM_OBJ))
$(VM_OBJ_DIR)%.o:$(VM_SRC_DIR)%.c $(VM_INC)
	@printf "\033[0;33m"
	$(CC) $(CFLAGS) -c $< -o $@ $(VM_INC_FLAGS)
$(VM_LIBFT):
	@$(MAKE) -C $(VM_LIBFT_DIR)

$(ASM_NAME): $(ASM_LIBFT) $(ASM_OBJ_DIR) $(ASM_OBJ)
	@printf "\033[0;33m"
	$(CC) $(ASM_OBJ) -o $(ASM_NAME) $(ASM_INC_FLAGS) $(ASM_LFT_FLAGS)
	@printf "\033[0;32m$(ASM_NAME) compiled\n\033[0m";

$(ASM_OBJ_DIR):
	@mkdir -p $(ASM_OBJ_DIR)

$(ASM_OBJ_DIR)%.o:$(ASM_SRC_DIR)%.c $(ASM_INC)
	@printf "\033[0;33m"
	$(CC) $(CFLAGS) -c $< -o $@ $(ASM_INC_FLAGS)
$(ASM_LIBFT):
	@$(MAKE) -C $(ASM_LIBFT_DIR)

clean:
	@ if [ -e $(VM_OBJ_DIR) ] || [ -e $(ASM_OBJ_DIR) ]; \
	then \
		$(RM) -r $(VM_OBJ_DIR); \
		$(RM) -r $(ASM_OBJ_DIR); \
		printf "\033[0;31m$(VM_NAME) objects removed\n\033[0m"; \
		printf "\033[0;31m$(ASM_NAME) objects removed\n\033[0m"; \
	fi;
	@ $(MAKE) clean -C $(VM_LIBFT_DIR)
	@ $(MAKE) clean -C $(ASM_LIBFT_DIR)

fclean: clean
	@ if [ -e $(VM_NAME) ] || [ -e $(ASM_NAME) ]; \
	then \
		$(RM) $(VM_NAME); \
		$(RM) $(ASM_NAME); \
		printf "\033[0;31m$(VM_NAME) removed\n\033[0m"; \
		printf "\033[0;31m$(ASM_NAME) removed\n\033[0m"; \
	fi;
	@ $(MAKE) fclean -C $(VM_LIBFT_DIR)
	@ $(MAKE) fclean -C $(ASM_LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
