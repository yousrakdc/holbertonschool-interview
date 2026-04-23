#!/usr/bin/python3

"""
Module that validates UTF-8 encoding
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.

    Args:
        data: list of integers, each representing 1 byte

    Returns:
        True if valid UTF-8, False otherwise
    """
    remaining_bytes = 0

    for byte in data:
        # Only keep the 8 least significant bits
        byte = byte & 0xFF

        if remaining_bytes == 0:
            # Determine how many bytes this character uses
            if (byte >> 7) == 0b0:
                # 1-byte character (0xxxxxxx)
                remaining_bytes = 0
            elif (byte >> 5) == 0b110:
                # 2-byte character (110xxxxx)
                remaining_bytes = 1
            elif (byte >> 4) == 0b1110:
                # 3-byte character (1110xxxx)
                remaining_bytes = 2
            elif (byte >> 3) == 0b11110:
                # 4-byte character (11110xxx)
                remaining_bytes = 3
            else:
                # Invalid leading byte
                return False
        else:
            # Expecting a continuation byte (10xxxxxx)
            if (byte >> 6) != 0b10:
                return False
            remaining_bytes -= 1

    # All characters must be complete
    return remaining_bytes == 0
