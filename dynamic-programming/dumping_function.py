#!/usr/bin/env python3.8

import dis

def func():
    for x in range(0, 10):
        print(x)
    return None
dis.dis(func)
