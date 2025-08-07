#!/usr/bin/python3

"""
    Determines if all boxes can be opened using DFS approach.
    
    Args:
        boxes: List of lists where each inner list contains keys for other boxes
    
    Returns:
        bool: True if all boxes can be opened, False otherwise
"""
    
def canUnlockAll(boxes):
    if not boxes : 
        return True

    n = len(boxes)
    unlocked = set([0])

    def look(box_num):
        for key in boxes[box_num]:
            if key < n and key not in unlocked:
                unlocked.add(key)
                look(key)
    look(0)
    return len(unlocked) == n