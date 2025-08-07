#!/usr/bin/python3

def canUnlockAll(boxes):
    if not boxes : 
        return True

    n = len(boxes)
    unlocked = set[0]

    def look(box_num):
        for key in boxes[box_num]:
            if key < n and key not in unlocked:
                unlocked.add(key)
                look(key)
    look(0)
    return len(unlocked) == n