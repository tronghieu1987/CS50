from cs50 import get_int

# prompt for card's numbers
while True:
    print('Input your credit card numbers (13, 15 or 16 digits)!')
    print("Number: ", end='')
    x = get_int()
    if x > 0:
        break

# convert to string and get the size of the numbers string
size = len(str(x))

numbers = list()
divisor = 1
# store digits into a list in reverse order
for i in range(size):
    numbers.append((x // divisor) % 10)
    divisor = divisor * 10

# 1st sum
sum = 0
for i in range(1, size, 2):
    # 2 cases: product < 10 and >=10
    if numbers[i] * 2 < 10:
        sum = sum + numbers[i] * 2
    else:
        sum = sum + (numbers[i] * 2) % 10 + ((numbers[i] * 2) //10) % 10

# 2nd sum
for i in range(0, size, 2):
    sum = sum + numbers[i]

# check the validity of the card number
if (sum % 10) != 0:
    print("INVALID")
else:
    if size == 15 and numbers[size - 1] == 3 and (numbers[size - 2] == 4 or numbers[size - 2] == 7):
        print("AMEX")
    elif size == 16 and numbers[size - 1] == 5 and (numbers[size - 2] == 1 or numbers[size - 2] == 2
    or numbers[size - 2] == 3 or numbers[size - 2] == 4 or numbers[size - 2] == 5):
        print("MASTERCARD")
    elif (size == 13 or size == 16)  and numbers[size - 1] == 4:
        print("VISA")
    else:
        print("INVALID")
