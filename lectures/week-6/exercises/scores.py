scores = []

for i in range(3):
    score = int(input(f"Enter score {i + 1}: "))
    scores.append(score)

print("\n'")

average = round(sum(scores) / len(scores), 2)
print(f"Average: {average}")