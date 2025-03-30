import random



def func(sum: int, array: list, index: int = 0):
    if index >= len(array):
        return sum
    return func(sum + array[index], array, index + 1)

def quick_sort(array:list):
    if len(array) < 2:
        return array
    else:
        print(f"array是{array}")
        poivt = array[-1]
        less = [i for i in array[:-1] if i <= poivt]
        greater = [i for i in array[:-1] if i > poivt]
        print(f"less是{less},greater是{greater}")
        print(f"poivt是{poivt}")
        print
        return quick_sort(less) + [poivt] + quick_sort(greater)

# 生成一个包含 10000 个随机整数的列表，范围在 1 到 100000 之间
large_list = [random.randint(1, 100) for _ in range(10)]

# 对生成的列表进行排序
sorted_list = quick_sort(large_list)
# 打印排序后的列表的前 10 个元素（避免输出过多内容）
print(sorted_list[:10])
    