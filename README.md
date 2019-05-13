# [42] ft_select

A side project in the Unix branch at 42. This project serves as an introduction to the termcaps library. The goal is to create a basic selection menu, capable of being used in other programs. Bonuses implemented include proper column handling, window resizing, using all arrow keys, color coded files, and a search bar.

### Possible Optimization
Search is currently a naive implementation, where it goes through the list until it finds a matching string. There are many ways to implement stronger search functionality.

## Final Score

125/100

## Usage

### Compilation

Compiler:

```
clang-6.0
```

Dependencies:

```
libft
termcaps
```

### Execution

How to run:

```
./ft_select [arguments ...]
```

## Example

```
./ft_select a b c
a b c
```

## Norme

This project is coded in accordance with the school's norms. A full copy of the norm can be found [here](https://github.com/MagicHatJo/-42-Norm/blob/master/norme.en.pdf).
