#!/usr/bin/python3

import os

for root, dir, files in os.walk("DSA"):
    for file in files:
        if os.path.splitext(file)[1] == '.cpp':
            fullpath = os.path.join(root, file)
            os.system("clang-format -i " + fullpath)
        elif os.path.splitext(file)[1] == '.h':
            fullpath = os.path.join(root, file)
            os.system("clang-format -i " + fullpath)