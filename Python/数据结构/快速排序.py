def quicksort(array):
        if len(array) < 2:
                #基线条件:为空或只包含一个元素的数组
                return array
        else:
                pivot = array[0]

                #由所有小于等于基准值的元素组成的数组
                less = [i for i in array[1:] if i <= pivot]

                #由所有大于基准值的元素组成的数组
                greater = [i for i in array[1:] if i > pivot]

                return quicksort(less) + [pivot] + quicksort(greater)

print(quicksort([10,5,2,3]))
