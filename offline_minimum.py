# Off Line Minimum
# 
# Have the function OffLineMinimum(strArr) take the strArr parameter being passed which
# will be an array of integers ranging from 1...n and the letter "E" and return the
# correct subset based on the following rules. The input will be in the following format:
# ["I","I","E","I",...,"E",...,"I"] where the I's stand for integers and the E means
# take out the smallest integer currently in the whole set. When finished, your program
# should return that new set with integers separated by commas. For example: if strArr
# is ["5","4","6","E","1","7","E","E","3","2"] then your program should return 4,1,5.
# 
# Optimal: o(n), achieved: o(n)

import heapq as hq

def OffLineMinimum(str_list):
  # code goes here
  ls = []
  rt = []

  hq.heapify(ls)
  for el in str_list:
    if el != 'E':
      hq.heappush(ls,int(el))
    else:
      rt.append(hq.heappop(ls))

  ret = ''.join([str(i)+',' for i in rt])
  return ret[:-1]

# keep this function call here 
print(OffLineMinimum(input()))