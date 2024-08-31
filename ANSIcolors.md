# Regular colors

| Value    | Color  |
| -------- | ------ |
| \e[0;30m | Black  |
| \e[0;31m | Red    |
| \e[0;32m | Green  |
| \e[0;33m | Yellow |
| \e[0;34m | Blue   |
| \e[0;35m | Purple |
| \e[0;36m | Cyan   |
| \e[0;37m | White  |

// example: "\e[0;32mHere's a Green Text\e[0m"

# Substitute '0' for '1' to make it bold
// example: "\e[1;32mHere's a Bold Green Text\e[0m"

# Add 10 at the 30's and remove the '0;' to make it the background color
// example: "\e[42mHere's a Green Background Text\e[0m"

# The 'e' can be replaced by '033'
// example: "\033[0;32mHere's a Green Text\033[0m"

IMPORTANT: Do not remove the '[0m', it makes the color change stop, if you want to switch colors you can't take it off.
