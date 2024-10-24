import sys

def carregarNum():
    linha = sys.stdin.readline()
    if linha == ' ' or linha == '\n':
        return None

    return int(linha)

def carregarCaso():
    npessoas = carregarNum()

    pessoas = []
    for p in range(npessoas):
        pessoas.append(carregarNum())

    return pessoas

def obeterCandidatos(antes):

    candidatos = []
    l = len(antes)

    if l > 3:
        t1 = antes[1] + antes[0] + antes[l-1] + antes[1]
        t2 = antes[l-1] + antes[0] + antes[l-2] + antes[0]
        if t1 <= t2:
            candidatos = [
                (antes[0], antes[1]), 
                (antes[0],), 
                (antes[l-2], antes[l-1]), 
                (antes[1],)]
        else:
            candidatos = [
                (antes[0], antes[l-2]),
                (antes[0],), 
                (antes[0], antes[l-1]),
                (antes[0],)]  
        antes.pop()
        antes.pop()

    elif l == 3:
        candidatos = [
            (antes[0], antes[1]), 
            (antes[0],), 
            (antes[0], antes[2])]
        antes[:] = []
        
    elif l == 2:
        candidatos = [(antes[0], antes[1])]
        antes[:] = []
    
    else:
        candidatos = [(antes[0],)]
        antes[:] = []

    return candidatos

def teste(pessoas):

    ordem = []
    
    antes = sorted(pessoas)
    
    segundos = 0

    while len(antes):
       
        candidatos = obeterCandidatos(antes)
        for c in candidatos:
            segundos += max(c)
            ordem.append(c)

    return segundos, ordem



casos = carregarNum()

for c in range(casos):
    sys.stdin.readline()

    pessoas = carregarCaso()
    segundos, ordem = teste(pessoas)
    print(segundos)
    for p in ordem:
        print(" ".join(map(str, p)))
        
    if c < casos-1: 
        print('')
