# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 09:50:21 by rothiery          #+#    #+#              #
#    Updated: 2024/08/12 14:26:56 by rothiery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	so_long
NAMEB=	so_long_bonus

SRC= 	src/so_long.c			src/parsing/parsing.c		src/parsing/checkcontent.c	\
		src/utils/end_game.c	src/utils/ff_algo.c			src/utils/ff_utils.c		\
		src/utils/ft_itoa.c		src/utils/mlx_aff.c			src/utils/mlx_key.c		  	\
		src/utils/so_long_utils.c														\
		src/utils/gnl/get_next_line_utils.c			src/utils/gnl/get_next_line.c		\

SRCB= 	srcb/so_long.c			srcb/parsing/parsing.c		srcb/parsing/checkcontent.c	\
		srcb/utils/end_game.c	srcb/utils/ff_algo.c			srcb/utils/ff_utils.c	\
		srcb/utils/ft_itoa.c		srcb/utils/mlx_aff.c			srcb/utils/mlx_key.c\
		srcb/utils/so_long_utils.c	srcb/utils/frees.c		srcb/utils/turret_m.c		\
		srcb/utils/gnl/get_next_line_utils.c			srcb/utils/gnl/get_next_line.c	\
		srcb/utils/mlx_init.c 	srcb/utils/turret.c\

OFILES= ${SRC:%.c=obj/%.o}
OFILESB= ${SRCB:%.c=obj/%.o}

CC= 	cc
CFLAGS= -Wall -Wextra -Werror -fsanitize=address -g3 -I includes

MINILIBX = includes/.mlx

RESET = \033[0m
GRAS = \033[1m
ITALIQUE = \033[3m
SOULIGN = \033[4m
UP = \033[A
BLINK = \033[6m

ORANGE = \033[38;5;216m
DARKBLUE = \033[38;5;21m
RED = \033[38;5;130m
DARK_RED = \033[38;5;88m
GREEN = \033[38;5;85m

ifneq ($(filter bonus re_b,$(MAKECMDGOALS)),)
NBR_TOT_FICHIER=17
else
NBR_TOT_FICHIER=13
endif

FICH_COUNT = 0
NBR_COMPILER = ${shell expr 100 \* ${FICH_COUNT} / ${NBR_TOT_FICHIER}}
BAR =  ${shell expr 23 \* ${FICH_COUNT} / ${NBR_TOT_FICHIER}}
REST = ${shell expr 23 - ${BAR}}

all:	${NAME}

bonus:	${NAMEB}

${NAMEB}:			${OFILESB}
	@${MAKE} -C ${MINILIBX} > /dev/null 2>&1
	@${eval FICH_COUNT = ${shell expr ${FICH_COUNT} + 1}}
	@file_name=MINILIBX && \
	echo " ${GRAS}${RED}-> COMPILING${RESET}${GRAS}${GREEN}${RESET}" && \
	printf " ${RED}${GRAS}[${GREEN}%-.${BAR}s${DARK_RED}%-.${REST}s${RED}] [%d/%d (%d%%)] ${GREEN}%s  ✓                         ${DEF_COLOR}" "-----------------------" "-----------------------" ${FICH_COUNT} ${NBR_TOT_FICHIER} ${NBR_COMPILER} $${file_name} && \
	echo "${UP}${UP}${UP}" && \
	echo ""
	@${CC} ${CFLAGS} ${OFILESB} -L${MINILIBX} -lmlx -lX11 -lXext -lm -o ${NAMEB}
	@echo "\n\n${GREEN} [✓] - ${_GREEN}so_long_bonus${GREEN} Successfully Compiled!${RESET}"

${NAME}:		${OFILES}
	@${MAKE} -C ${MINILIBX} > /dev/null 2>&1
	@${eval FICH_COUNT = ${shell expr ${FICH_COUNT} + 1}}
	@file_name=MINILIBX && \
	echo " ${GRAS}${RED}-> COMPILING${RESET}${GRAS}${GREEN}${RESET}" && \
	printf " ${RED}${GRAS}[${GREEN}%-.${BAR}s${DARK_RED}%-.${REST}s${RED}] [%d/%d (%d%%)] ${GREEN}%s  ✓                         ${DEF_COLOR}" "-----------------------" "-----------------------" ${FICH_COUNT} ${NBR_TOT_FICHIER} ${NBR_COMPILER} $${file_name} && \
	echo "${UP}${UP}${UP}" && \
	echo ""
	@${CC} ${CFLAGS} ${OFILES} -L${MINILIBX} -lmlx -lX11 -lXext -lm -o ${NAME}
	@echo "\n\n${GREEN} [✓] - ${_GREEN}so_long${GREEN} Successfully Compiled!${RESET}"

obj/%.o:%.c
	@mkdir -p obj/$(dir $<)
	@${eval FICH_COUNT = ${shell expr ${FICH_COUNT} + 1}}
	@${CC} ${CFLAGS} -c -I . $< -o $@
	@file_name=$(notdir $<) && \
	echo " ${GRAS}${RED}-> COMPILING${RESET}${GRAS}${GREEN}${RESET}" && \
	printf " ${RED}${GRAS}[${GREEN}%-.${BAR}s${DARK_RED}%-.${REST}s${RED}] [%d/%d (%d%%)] ${GREEN}%s  ✓                         ${DEF_COLOR}" "-----------------------" "-----------------------" ${FICH_COUNT} ${NBR_TOT_FICHIER} ${NBR_COMPILER} $${file_name} && \
	echo "${UP}${UP}${UP}" && \
	echo ""

clean:
	@${MAKE} -C ${MINILIBX} clean > /dev/null
	@rm -rf obj
	@echo "${ORANGE}${GRAS}\tNETTOYAGE${RESET}"
	@echo "${RED}${ITALIQUE} -files successfully removed${RESET}"

fclean:	clean
	@rm -f ${NAME}
	@rm -f ${NAMEB}
	@${RM} ${NAME}
	@echo "${RED}${ITALIQUE} -${NAME} is removed${RESET}"

re:	fclean all

re_b: fclean bonus

.PHONY:		all bonus clean fclean re
