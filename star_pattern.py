def star_pattern(n):
    for i in range(n):
        for j in range(n - i - 1):
            print(" ", end="")
        for k in range(i+1):
            print("* ", end="")
        print() 

star_pattern(4);