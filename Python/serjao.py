def read_input():
    import sys
    input = sys.stdin.read
    data = input().strip().split('\n')
    
    index = 0
    test_cases = []
    
    while index < len(data):
        # Ignora linhas em branco
        if not data[index].strip():
            index += 1
            continue
        
        # Lê as dimensões do recipiente
        L, C = map(int, data[index].split())
        index += 1
        
        # Lê o recipiente
        container = []
        for _ in range(L):
            container.append(list(data[index].strip()))
            index += 1
        
        # Lê a coluna da bomba
        B = int(data[index])
        index += 1
        
        # Lê os volumes de água
        volumes = []
        while index < len(data):
            volume = int(data[index])
            if volume == 0:
                index += 1
                break
            volumes.append(volume)
            index += 1
        
        # Adiciona o caso de teste à lista
        test_cases.append((L, C, container, B, volumes))
    
    return test_cases

def print_water_levels(water_levels):
    for row in range(len(water_levels) - 1, -1, -1):
        print(" ".join(map(str, water_levels[row])))

def simulate_water_pumping(L, C, container, B, volumes):
    water_levels = [[0] * C for _ in range(L)]
    
    for volume in volumes:
        for _ in range(volume):
            r, c = 0, B
            # Desce até o fundo ou até encontrar um obstáculo
            while r + 1 < L and container[r + 1][c] == '.' and water_levels[r + 1][c] == 0:
                r += 1
            # Se há água embaixo, pode descer mais até atingir o fundo
            while r + 1 < L and container[r + 1][c] == '.' and water_levels[r + 1][c] > 0:
                r += 1
                if r + 1 < L and container[r + 1][c] == 'O':
                    if c - 1 >= 0 and container[r + 1][c - 1] == '.' and water_levels[r][c - 1] == 0:
                        c -= 1
                    elif c + 1 < C and container[r + 1][c + 1] == '.' and water_levels[r][c + 1] == 0:
                        c += 1
            water_levels[r][c] += 1
        
        print_water_levels(water_levels)

if __name__ == "__main__":
    test_cases = read_input()
    for i, (L, C, container, B, volumes) in enumerate(test_cases):
        simulate_water_pumping(L, C, container, B, volumes)
        if i < len(test_cases) - 1:
            print()  # Print an empty line between outputs for diferentes casos de teste
