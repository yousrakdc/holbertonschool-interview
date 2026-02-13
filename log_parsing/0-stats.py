#!/usr/bin/python3
"""Script that reads stdin line by line and computes metrics."""

import sys


def print_stats(total_size, status_counts):
    """Print accumulated statistics."""
    print("File size: {}".format(total_size))
    for code in sorted(status_counts.keys()):
        if status_counts[code] > 0:
            print("{}: {}".format(code, status_counts[code]))


if __name__ == "__main__":
    total_size = 0
    line_count = 0
    valid_codes = {200, 301, 400, 401, 403, 404, 405, 500}
    status_counts = {}

    try:
        for line in sys.stdin:
            try:
                parts = line.split()
                if len(parts) < 7:
                    raise ValueError

                file_size = int(parts[-1])
                status_code = int(parts[-2])

                if (parts[-3] != 'HTTP/1.1"'
                        or parts[-4] != '/projects/260'
                        or parts[-5] != '"GET'):
                    raise ValueError

                total_size += file_size
                if status_code in valid_codes:
                    status_counts[status_code] = \
                        status_counts.get(status_code, 0) + 1

            except (ValueError, IndexError):
                pass

            line_count += 1
            if line_count % 10 == 0:
                print_stats(total_size, status_counts)

    except KeyboardInterrupt:
        pass
    finally:
        print_stats(total_size, status_counts)
        