# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iltellat <iltellat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 00:34:42 by iltellat          #+#    #+#              #
#    Updated: 2025/03/08 00:19:27 by iltellat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = -Lft_printf -lftprintf
SRVRM = mandatory/server.c
CLNTM = mandatory/client.c mandatory/utils.c
OSM = $(SRVRM:.c=.o)
OCM = $(CLNTM:.c=.o)

SRVRB = bonus/server_bonus.c bonus/utils_bonus.c
CLNTB = bonus/client_bonus.c bonus/utils_bonus.c
OSB = $(SRVRB:.c=.o)
OCB = $(CLNTB:.c=.o)
MAKEFLAGS += --silent

all: signature $(NAME_SERVER) $(NAME_CLIENT)

bonus: signature $(NAME_SERVER)_bonus $(NAME_CLIENT)_bonus

signature:
	@ clear
	@ echo "\033[35mMMMMMMMM               MMMMMMMM  iiii                     iiii          tttt                            lllllll kkkkkkkk           "
	@ echo "M:::::::M             M:::::::M i::::i                   i::::i      ttt:::t                            l:::::l k::::::k           "
	@ echo "M::::::::M           M::::::::M  iiii                     iiii       t:::::t                            l:::::l k::::::k           "
	@ echo "M:::::::::M         M:::::::::M                                      t:::::t                            l:::::l k::::::k           "
	@ echo "M::::::::::M       M::::::::::Miiiiiiinnnn  nnnnnnnn    iiiiiiittttttt:::::ttttttt      aaaaaaaaaaaaa    l::::l  k:::::k    kkkkkkk"
	@ echo "M:::::::::::M     M:::::::::::Mi:::::in:::nn::::::::nn  i:::::it:::::::::::::::::t      a::::::::::::a   l::::l  k:::::k   k:::::k "
	@ echo "M:::::::M::::M   M::::M:::::::M i::::in::::::::::::::nn  i::::it:::::::::::::::::t      aaaaaaaaa:::::a  l::::l  k:::::k  k:::::k  "
	@ echo "M::::::M M::::M M::::M M::::::M i::::inn:::::::::::::::n i::::itttttt:::::::tttttt               a::::a  l::::l  k:::::k k:::::k   "
	@ echo "M::::::M  M::::M::::M  M::::::M i::::i  n:::::nnnn:::::n i::::i      t:::::t              aaaaaaa:::::a  l::::l  k::::::k:::::k    "
	@ echo "M::::::M   M:::::::M   M::::::M i::::i  n::::n    n::::n i::::i      t:::::t            aa::::::::::::a  l::::l  k:::::::::::k     "
	@ echo "M::::::M    M:::::M    M::::::M i::::i  n::::n    n::::n i::::i      t:::::t           a::::aaaa::::::a  l::::l  k:::::::::::k     "
	@ echo "M::::::M     MMMMM     M::::::M i::::i  n::::n    n::::n i::::i      t:::::t    tttttta::::a    a:::::a  l::::l  k::::::k:::::k    "
	@ echo "M::::::M               M::::::Mi::::::i n::::n    n::::ni::::::i     t::::::tttt:::::ta::::a    a:::::a l::::::lk::::::k k:::::k   "
	@ echo "M::::::M               M::::::Mi::::::i n::::n    n::::ni::::::i     tt::::::::::::::ta:::::aaaa::::::a l::::::lk::::::k  k:::::k  "
	@ echo "M::::::M               M::::::Mi::::::i n::::n    n::::ni::::::i       tt:::::::::::tt a::::::::::aa:::al::::::lk::::::k   k:::::k "
	@ echo "MMMMMMMM               MMMMMMMMiiiiiiii nnnnnn    nnnnnniiiiiiii         ttttttttttt    aaaaaaaaaa  aaaallllllllkkkkkkkk    kkkkkkk \033[0m"
	@ echo -n "Loading Minitalk"
	@ for i in 1 2 3; do echo -n ".";sleep 0.7;done;
	@ echo " "

$(NAME_SERVER): $(OSM) FT_PRINTF mandatory/minitalk.h
	@ echo "\033[34mMaking Server...\033[0m"
	@ sleep 0.5
	@ $(CC) $(CFLAGS) $(OSM) $(LIB) -o $(NAME_SERVER) 
	@ echo "\033[32mServer is maked successfully !!\033[0m"
	@ sleep 0.3

$(NAME_CLIENT): $(OCM) FT_PRINTF mandatory/minitalk.h
	@ echo "\033[34mMaking Client...\033[0m"
	@ sleep 0.5
	@ $(CC) $(CFLAGS) $(OCM) $(LIB) -o $(NAME_CLIENT)
	@ echo "\033[32mClient is maked successfully !!\033[0m"
	@ sleep 0.3

$(NAME_SERVER)_bonus: $(OSB) FT_PRINTF bonus/minitalk_bonus.h
	@ echo "\033[35mMaking Server bonus...\033[0m"
	@ sleep 0.5
	@ $(CC) $(CFLAGS) $(OSB) $(LIB) -o $(NAME_SERVER)_bonus
	@ echo "\033[32mServer bonus is maked successfully !!\033[0m"
	@ sleep 0.3

$(NAME_CLIENT)_bonus: $(OCB) $(OUB) FT_PRINTF bonus/minitalk_bonus.h
	@ echo "\033[35mMaking Client bonus...\033[0m"
	@ sleep 0.5
	@ $(CC) $(CFLAGS) $(OCB) $(OUB) $(LIB) -o $(NAME_CLIENT)_bonus
	@ echo "\033[32mClient bonus is maked successfully !!\033[0m"
	@ sleep 0.3

FT_PRINTF:
	@ echo "\033[36mMaking ft_printf...\033[0m"
	@ sleep 0.5
	@ $(MAKE) -C ft_printf --no-print-directory
	@ echo "\033[32mft_printf is ready to use !!\033[0m"
	@ sleep 0.3

clean:
	@ echo "\033[33mCleaning Object files...\033[0m"
	@ sleep 0.5
	@ rm -f $(OSM) $(OCM) $(OSB) $(OCB) $(OUM) $(OUB)
	@ $(MAKE) -C ft_printf clean --no-print-directory
	@ echo "\033[32mCleaned successfully !!\033[0m"
	@ sleep 0.3

fclean: clean
	@ $(MAKE) -C ft_printf fclean --no-print-directory
	@ echo "\033[33mCleaning executables...\033[0m"
	@ sleep 0.5
	@ rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@ rm -f $(NAME_SERVER)_bonus $(NAME_CLIENT)_bonus
	@ echo "\033[32mPerformed full clean !!\033[0m"
	@ sleep 0.3

%.o: %.c 
	@$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

.PHONY: all clean fclean re signature FT_PRINTF