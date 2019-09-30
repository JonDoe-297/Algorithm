# N = int(input())
N = 3
row_totally = 2**N  # 总行数
col_totally = 2**(N + 1)  # 总列数
triangle_up = [' ', '/', '\\', ' ']
triangle_down = ['/', '_', '_', '\\']

for row_num in range(0, row_totally):  # 层数
    start_position = col_totally
    for col_num in range(0, col_totally):  # 列数
        if col_num < ((row_totally - 1) - row_num) or col_num >= (col_totally - (row_totally - 1) + row_num):
            print('0', end='')
        else:
            if start_position > col_num:
                start_position = col_num
            if row_num % 2 == 0:
                print(triangle_up[(col_num - start_position) % 4], end='')
            else:
                print(triangle_down[(col_num - start_position) % 4], end='')
    print('\n', end="")
