def print_row(height: int, bricks: int) -> None:
    print(" " * (height - bricks), end="")
    print("#" * bricks, end="")
    print("  ", end="")
    print("#" * bricks)


def read_height() -> int:
    while True:
        try:
            height = int(input("Height: "))
            if height >= 1 and height <= 8:
                return height
        except ValueError:
            pass


def main() -> None:
    height = read_height()

    for i in range(1, height + 1):
        print_row(height, i)


if __name__ == "__main__":
    main()
