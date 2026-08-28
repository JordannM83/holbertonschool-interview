#!/usr/bin/python3
"""
Determines if all the boxes can be opened.
Returns True if all boxes can be opened, False otherwise.
"""
def canUnlockAll(boxes):
    """
    Determines if all the boxes can be opened.
    Returns True if all boxes can be opened, False otherwise. 
    """
    result = []
    for i in range(len(boxes)):
        result.append(False)
    result[0] = True
    for boxe in range(len(boxes)-1):
        for box in boxes[boxe]:
            if box < len(result):
                result[box] = True
    if False in result:
        return False
    else:
        return True
