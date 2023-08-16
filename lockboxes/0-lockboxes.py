#!/usr/bin/python3
""" not empty """


def canUnlockAll(boxes):
    boxeLen = len(boxes)
    key = [0]

    for i in key:
        if i < boxeLen:
            for j in boxes[i]:
                if j not in key and j < boxeLen:
                    key.append(j)
    if len(key) == boxeLen:
        return True
    return False
