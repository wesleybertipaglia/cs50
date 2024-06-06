def main():
    card_number = int(input("Number: "))

    if check_luhn(card_number):
        if is_valid_amex(card_number):
            print("AMEX")
        elif is_valid_mastercard(card_number):
            print("MASTERCARD")
        elif is_valid_visa(card_number):
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")


def check_luhn(number):
    total_sum = 0
    alternate = False

    while number > 0:
        digit = number % 10
        if alternate:
            digit *= 2
            if digit > 9:
                digit = (digit % 10) + 1
        total_sum += digit
        alternate = not alternate
        number //= 10

    return (total_sum % 10) == 0


def is_valid_amex(number):
    length = get_length(number)
    first_two_digits = get_first_digits(number, 2)

    return length == 15 and (first_two_digits == 34 or first_two_digits == 37)


def is_valid_mastercard(number):
    length = get_length(number)
    first_two_digits = get_first_digits(number, 2)

    return length == 16 and (51 <= first_two_digits <= 55)


def is_valid_visa(number):
    length = get_length(number)
    first_digit = get_first_digits(number, 1)

    return (length == 13 or length == 16) and first_digit == 4


def get_length(number):
    length = 0
    while number > 0:
        number //= 10
        length += 1
    return length


def get_first_digits(number, digits):
    length = get_length(number)
    for _ in range(length - digits):
        number //= 10
    return number


if __name__ == "__main__":
    main()
