def binary_search(list,item):
        low = 0
        high = len(list) - 1

        while low <= high:
                mid = (low + high) // 2
                guest = list[mid]

                if guest == item:
                        return mid
                if guest > item:
                        high = mid - 1
                else:
                        low = mid + 1
        return None


my_list = [1,3,5,7,9]
print(binary_search(my_list,3))
print(binary_search(my_list,-1))

