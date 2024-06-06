def meow(number: int):
    for i in range(number):
        print(f"meow {i + 1}")

def main():
    number = 0

    while True:
        try:  
            number = int(input("How many times do you want to meow? "))          
            if number < 0:
                print("Please enter a positive number.")
            else:
                break
        except ValueError:
            print("Please enter a valid number.")
    
    meow(number)

if __name__ == "__main__":
    main()