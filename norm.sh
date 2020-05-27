#!/bin/sh

find inc src libft plugins -type f \( -iname "*.c" -or -iname "*.h" \) -exec norminette {} \; | grep -B1 -i error
