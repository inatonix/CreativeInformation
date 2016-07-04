# -*- coding: utf-8 -*-
import math

#スペースに囲まれているのが第一オペランド
if __name__ == '__main__':
    f = open("sample.txt")
    line = f.readline()
    while(line):
        st = line.split(" ")
        print(st[1])
        line = f.readline()
