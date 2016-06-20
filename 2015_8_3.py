# -*- coding: utf-8 -*-

if __name__ == '__main__':
    f_1 = open('sample.txt')
    f_2 = open('sample.txt')
    line = f_1.readline() # 1行を文字列として読み込む(改行文字も含まれる)
    next_line = f_2.readline()
    tmp_line = ""


    while next_line:
        next_line = f_2.readline()
        if (line == next_line and line != tmp_line):
            tmp_line = line
            print(line)
        line = f_1.readline()
    f_1.close;f_2.close
