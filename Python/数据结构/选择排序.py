def findSmallest(arr):
        smallest = arr[0] #存储最小的值
        smallest_index = 0 #存储最小元素索引
        for i in range(1,len(arr)):
                if arr[i] < smallest:
                        smallest = arr[i]
                        smallest_index = i
        return smallest_index
        
def selectionSort(arr):  #对数组进行排序
        newArr = []
        for i in range(len(arr)):
                smallest = findSmallest(arr)
                newArr.append(arr.pop(smallest)) #找出最小值添加到新数组
        return newArr

print(selectionSort([5,3,6,2,10]))
