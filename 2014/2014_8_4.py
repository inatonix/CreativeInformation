# -*- coding: utf-8 -*-

if __name__ == '__main__':
    f = open("sample.txt")
    lines = f.readlines()
    cnt = 1
    check = [0] * 100

    for i in range(0,len(lines)-1):
        if(check[i] == 0):
            cnt = 1
            for j in range(i+1,len(lines)):
                if lines[i] == lines[j]:
                    if(cnt == 1):
                        print(lines[i]),
                    cnt += 1
                    check[j] = 1
            if(cnt > 1):
                print(cnt)


    f.close
