S, T = input().split(" ")
word1 = [ch for ch in S]
word2 = [ch for ch in T]

# for non-repeated letters
for letter in word2:
    if letter not in word1:
        print(letter)
    # For repeated letters..
    elif word1.count(letter) !=word2.count(letter):
        print(letter)
        break

"""
+------------------------------+
|  8 tests run/ 8 tests passed |
+------------------------------+
"""
