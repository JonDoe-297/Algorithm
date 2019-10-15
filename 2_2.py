N = int(input())
# N = 3
row_totally = 2**N  # 总行数
col_totally = 2**(N + 1)  # 总列数
stack = [(0, int(col_totally / 2) - 1)]
center_point = [int(col_totally / 2) - 1]
# start_line = 0
# end_line = row_totally
num_list = [([' ']*col_totally) for row in range(row_totally)]


def draw_triangle(top_row, top_col):
    num_list[top_row][top_col] = '/'
    num_list[top_row + 1][top_col - 1] = '/'
    num_list[top_row][top_col + 1] = '\\'
    num_list[top_row + 1][top_col + 2] = '\\'
    num_list[top_row + 1][top_col] = '_'
    num_list[top_row + 1][top_col + 1] = '_'


while stack:
    point = stack.pop()
    draw_triangle(point[0], point[1])
    if point[0] + 2 < row_totally and point[1] - 2 > 0 and point[1] + 2 < col_totally:
        if point[1] - 2 not in center_point:
            stack.append((point[0] + 2, point[1] - 2))
            # center_point.append(point[1] - 2)
        if point[1] + 2 not in center_point:
            stack.append((point[0] + 2, point[1] + 2))
            # center_point.append(point[1] + 2)

for i in range(0, row_totally):
    for j in range(0, col_totally):
        print(num_list[i][j], end='')
    print('\n', end='')


# # N = int(input())
# N = 3
# row_totally = 2**N  # 总行数
# col_totally = 2**(N + 1)  # 总列数
# matrix = [[0] * col_totally] * row_totally
# # print(matrix)
# # def draw_row_line(point1, point2):
# #     for n in range(0, col_totally):
# #         matrix[point1[0]][n] = '_'
# # def draw_slant_line(point1, point2):
#
# # draw_row_line([7, 0], [7, 16])
#
# for i in range(0, row_totally):
#     for j in range(0, col_totally):
#         print(matrix[i][j], end='')
#     print('\n', end='')
# # triangle_up = ['/', '\\']
# # triangle_down = ['/', '_', '_', '\\']
# #
# # for row_num in range(0, row_totally):  # 层数
# #     start_position = col_totally
# #     for col_num in range(0, col_totally):  # 列数
# #         if col_num < ((row_totally - 1) - row_num) or col_num >= (col_totally - (row_totally - 1) + row_num):
# #             print('0', end='')
# #         else:
# #             if start_position > col_num:
# #                 start_position = col_num
# #             if row_num % 2 == 0:
# #                 print(triangle_up[(col_num - start_position) % 2], end='')
# #             else:
# #                 print(triangle_down[(col_num - start_position) % 4], end='')
# #     print('\n', end="")
