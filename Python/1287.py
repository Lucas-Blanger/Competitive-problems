def solve(s):
    result = ''
    for char in s:
        if char == 'l':
            result += '1'
        elif char == 'o' or char == 'O':
            result += '0'
        elif char == ',' or char == ' ':
            continue
        else:
            result += char
    return result

def check(s):
    return not all(c.isdigit() for c in s)

def zeros(s):
    return all(c == '0' for c in s)

def overflow(s):
    try:
        x = int(s)
        return x > 2147483647
    except ValueError:
        return True

def take_zeros(s):
    return s.lstrip('0')

def main():
    try:
        while True:
            line = input()
            line = line.rstrip('\n')

            _str = solve(line)
            u = check(_str)
            v = zeros(_str)
            w = overflow(_str)

            if u or w or len(_str) < 1:
                print('error')
            elif v:
                print('0')
            else:
                print(take_zeros(_str))
    except EOFError:
        pass

if __name__ == "__main__":
    main()