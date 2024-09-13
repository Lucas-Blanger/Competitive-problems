def is_vowel(c):
    c = c.lower()
    return c in 'aeiou'

def follows_ana_rules(word):
    length = len(word)
    if length == 1:
        return True
    elif length <= 5:
        return not is_vowel(word[0]) and is_vowel(word[-1])
    else:
        return is_vowel(word[0]) and is_vowel(word[-1])

def check_paragraph(paragraph):
    words = paragraph.split()
    for word in words:
        if not follows_ana_rules(word):
            return False
    return True

def main():
    n = int(input())
    results = []

    for _ in range(n):
        paragraph = input().strip()
        if check_paragraph(paragraph):
            results.append("SIM")
        else:
            results.append("NAO")

    for result in results:
        print(result)


main()
