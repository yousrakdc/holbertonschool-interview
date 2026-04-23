#!/usr/bin/python3

"""
0-validate_utf8.py - Contains the validate_utf8 function
"""

def validate_utf8(data):
    """
    Validates if a list of integers represents a valid UTF-8 encoding.

    Args:
        data (list): A list of integers representing bytes.

    Returns:
        bool: True if the data is a valid UTF-8 encoding, False otherwise.
    """
    # Number of bytes in the current UTF-8 character
    num_bytes = 0

    for byte in data:
        # Check if this is the start of a new UTF-8 character
        if num_bytes == 0:
            # Count the number of leading 1s in the byte
            mask = 1 << 7
            while mask & byte:
                num_bytes += 1
                mask >>= 1

            # If no leading 1s, it's a single-byte character
            if num_bytes == 0:
                continue

            # If there are more than 4 leading 1s, it's an invalid UTF-8 character
            if num_bytes > 4:
                return False

        else:
            # Check if this is a continuation byte (starts with '10')
            if not (byte & (1 << 7) and not (byte & (1 << 6))):
                return False

        num_bytes -= 1

    # If we have any remaining bytes, it's an incomplete UTF-8 character
    return num_bytes == 0
