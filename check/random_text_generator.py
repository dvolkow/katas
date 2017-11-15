""" Generates random text for reverse task """
import sys
from random import randrange
from string import ascii_lowercase, ascii_uppercase


symbols = ascii_lowercase + ascii_uppercase + " \n\t"
n_symbols = len(symbols)


def generate_random_text(length):
    generator = (symbols[randrange(n_symbols)] for _ in range(length))
    return "".join(generator)


def main():
    length = int(sys.argv[1]) if len(sys.argv) == 2 else 4096
    random_text = generate_random_text(length)
    print(random_text)


if __name__ == "__main__":
    main()
