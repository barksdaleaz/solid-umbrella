numbers = input("Enter numbers here with spaces between: ")
str_arr = numbers.split(' ')
arr = [int(num) for num in str_arr]
target = int(input("Enter the target number: "))

viable = []

for i in range(len(arr)):
    if arr[i] <= target:
        viable.append(arr[i])

buffer = list(viable)

for i in range(len(viable)):
    if (viable[i]) + (buffer[i+1]) == target:
        print(f"{viable[i]} + {buffer[i+1]} = {target}")
        exit()
    else:
        print("No two-sum solutions.")
        exit()
