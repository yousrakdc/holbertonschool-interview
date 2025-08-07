#!/usr/bin/python3

def canUnlockAll(boxes):
    """
    Determines if all boxes can be unlocked using an iterative approach.
    Uses a stack to explore boxes without recursion limits.
    """
    if not boxes:
        return True

    n = len(boxes)
    unlocked = set([0])
    to_explore = [0]

    while to_explore:
        box_num = to_explore.pop()
        
        for key in boxes[box_num]:
            if key < n and key not in unlocked:
                unlocked.add(key)
                to_explore.append(key)
    
    return len(unlocked) == n