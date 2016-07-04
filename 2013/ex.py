# -*- coding: utf-8 -*-
import math

def koch(n,sqrLength):
    totalS = 0
    while(n > 0):
        totalS += (3 * pow(2,n-2)) * triangle(sqrLength / pow(3,n-1))
        print(totalS)
        n -= 1
    return totalS


def triangle(leng):
    S = pow(leng,2) * math.sqrt(3) / 2
    return S

if __name__ == '__main__':
    print(koch(2,10))
