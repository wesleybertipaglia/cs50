change = 0
coins = 0
coin_values = [25, 10, 5, 1]

while True:
    try:
        change = float(input("Change: "))
        if change > 0:
            break
    except ValueError:
        pass

change = int(round(change * 100))

for i in range(4):
    if change >= coin_values[i]:
        coins += change // coin_values[i]
        change = change % coin_values[i]

print(coins)
