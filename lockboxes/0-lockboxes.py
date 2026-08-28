#!/usr/bin/python3

def canUnlockAll(boxes):
    result = []
    for i in range(len(boxes)):
        result.append(False)
    result[0] = True
    for boxe in range(len(boxes)-1):
        for box in boxes[boxe]:
            result[box] = True
    if False in result:
        return False
    else:
        return True
