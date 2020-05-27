#!/bin/sh

find inc src libft plugins -type f \( -iname "*.c" -or -iname "*.h" \) -exec norminette {} \;
