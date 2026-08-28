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
    if not boxes:
        return True

    unlocked = {0}
    boxes_to_visit = [0]

    while boxes_to_visit:
        current_box = boxes_to_visit.pop()
        for key in boxes[current_box]:
            if 0 <= key < len(boxes) and key not in unlocked:
                unlocked.add(key)
                boxes_to_visit.append(key)

    return len(unlocked) == len(boxes)
