import openpyxl

# 打开Excel文件 excel源文件在本地的路径
workbook = openpyxl.load_workbook('code-train/code/cancanscript/0606.xlsx')

# 获取第四个工作表
sheet = workbook['Sheet1']

# 获取第一行的值
first_row = [cell.value for cell in sheet[1]]

# 计算列数
num_cols = len(first_row)

# 每两列为一组
for start in range(0, num_cols, 2):
    end = start + 2

    # 获取当前组的列名
    col_names = first_row[start:end][0]

    # 打开一个新的TXT文件,文件名为当前组的列名
    filename = col_names + ".txt"
    with open(filename, "w", encoding="gb2312") as f:

        # 遍历工作表从第二行开始
        for row in sheet.iter_rows(min_row=1, values_only=True):
            # 获取当前组的值
            values = row[start:end]
            print(values)

            # 如果这一行不是空白行
            if any(values):
                # 将值写入TXT文件
                f.write("\t".join(map(str, values)) + "\n")

    print(f"数据已成功写入{filename}文件。")