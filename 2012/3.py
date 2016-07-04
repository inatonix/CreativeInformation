# -*- coding: utf-8 -*-
import math
import linecache
arr = [["syokika",0]]

#スペースに囲まれているのが第一オペランド
if __name__ == '__main__':
    f = open("sample.txt")
    line = linecache.getline("sample.txt", 1)
    line_num = 1
    while(line):
        chara = line.strip().split(" ")
        if(chara[0] == "SET"):
            arr.append([chara[1],chara[2]])
        if(chara[0] == "ADD"):  #ADD 3 x
            for elem in arr:
                if(elem[0] == chara[2]):
                    elem[1] = str(int(elem[1]) + int(chara[1]))
        if(chara[0] == "PRN"):  #PRN x y
            for elem in arr:
                if(chara[1] == elem[0]):
                    print(elem[1]),
            for elem in arr:
                if(chara[2] == elem[0]):
                    print(elem[1])
        if(chara[0] == "CMP"):
            for elem in arr:
                if(chara[1] == elem[0]):
                    a = elem[1]
            for elem in arr:
                if(chara[2] == elem[0]):
                    b = elem[1]
            if(a == b):
                line_num += 1
                print("OK")

        if(chara[0] == "JMP"):
            line_num += int(chara[1])
            
        print(arr)
        line_num += 1
        line = linecache.getline("sample.txt", line_num)
    print(arr)
