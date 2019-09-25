line_num, a, b = map(int, input().split())
output_num = []


def fibonacci(n):
    fn1, fn2 = 1, 1
    for i in range(1, n):
        fn2, fn1 = fn1, 4 * fn1 + 5 * fn2
    return fn2


for n in range(line_num):
    input_num = int(input())
    num = fibonacci(input_num + 1)
    output_num.append(num % 2013)

for m in output_num:
    print(m)
