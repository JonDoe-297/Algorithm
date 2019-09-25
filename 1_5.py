num_size = int(input().strip())
data = [int(i) for i in input().strip().split()[:num_size]]


def single_num(data):
    val = 0
    for n in range(len(data)):
        val ^= data[n]
    return val


num = single_num(data)
print(num)
