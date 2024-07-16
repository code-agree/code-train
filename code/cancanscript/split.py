def split_text(input_file):
    with open(input_file, 'r', encoding='gb2312') as f:
        lines = f.readlines()

    current_section = []

    for line in lines:
        if line.startswith("断面名称"):
            if current_section:
                section_name = current_section[0].split("：")[1].strip()
                output_file = f"{section_name}.txt"
                with open(output_file, 'w', encoding='gb2312') as output_f:
                    output_f.write(section_name + '\n')
                    last_line = False
                    for idx, item in enumerate(current_section[1:]):
                        columns = item.split(',')[:2]
                        last_line_str = current_section[-1]
                        columns_lst = last_line_str.split(',')[:2]
                        if all(column == '0' for column in columns_lst):
                            # 最后一行为 0
                            last_line = True
                        # 全为0的行 忽略
                        if all(column == '0' for column in columns):
                            continue
                        if idx == len(current_section) - 3 and last_line:
                            output_f.write('\t'.join(item.split(',')[:2]))
                        else:
                            output_f.write('\t'.join(item.split(',')[:2]) + '\n')

            current_section = []
        current_section.append(line)

    if current_section:
        section_name = current_section[0].split("：")[1].strip()
        output_file = f"{section_name}.txt"
        with open(output_file, 'w', encoding='gb2312') as output_f:
            for item in current_section[1:]:
                output_f.write(','.join(item.split(',')[:2]) + '\n')

if __name__ == "__main__":
    input_file = "code-train/code/origin2.txt"  # 输入文件名
    split_text(input_file)