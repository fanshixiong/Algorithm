x = int(1)
for i in range(1, 200):
    x = x * (4 * i - 2) / (i + 1)
    x = int(x)
    # print(x)
    #if i == 31:
    #    print(x)
    #if (x % 2 == 1):
    # if i >= 100:
    print(str(i) + " " + str(x))