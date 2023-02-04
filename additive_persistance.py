# AdditivePersistance
# 
# Have the function AdditivePersistence(num) take the num parameter being passed which
# will always be a positive integer and return its additive persistence which is the
# number of times you must add the digits in num until you reach a single digit. For
# example: if num is 2718 then your program should return 2 because 2 + 7 + 1 + 8 =
# 18 and 1 + 8 = 9 and you stop at 9. 
#  
# Optimal: o(n), achieved: o(n)

from functools import reduce
from operator import add
def AdditivePersistence(num):
  
  # code goes here
  cnt = 0
  while num >= 10:
    num = reduce(add, [int(x) for x in str(num)])
    cnt += 1
  return cnt

# keep this function call here 
print(AdditivePersistence(input()))