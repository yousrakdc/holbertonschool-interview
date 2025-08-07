#!/usr/bin/python3

"""
    Determines if all boxes can be opened using DFS approach.
    
    Args:
        boxes: List of lists where each inner list contains keys for other boxes
    
    Returns:
        bool: True if all boxes can be opened, False otherwise
"""
    
def canUnlockAll(boxes):
    if not boxes:
        return True

    n = len(boxes)
    unlocked = set([0])
    to_visit = [0]

    while to_visit:
        print(f"Current box: {to_visit[-1]}, Unlocked boxes: {unlocked}")
        current_box = to_visit.pop()
        
        for key in boxes[current_box]:
            if key < n and key not in unlocked:
                unlocked.add(key)
                to_visit.append(key)
    
    return len(unlocked) == n