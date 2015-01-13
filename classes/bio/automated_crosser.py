import sys
import re


'''
    Evaluates a punnet square from a cross. Two modes:

        Simple mode (run by adding the parameter 'simple').
        The two parents delineated by square brackets. Traits occur
        in same order for both parents, and have two alleles. Alleles
        must be represented as one character. Example valid inputs:
            [AaBb][AABB]
            [AACCBB][aaccBb]

        Multichar mode (run by having no parameters, default).
        Two parents delineated by square brackets. Traits delineated
        by parentheses, have two alleles, and be listed in same 
        order for both parents. Alleles may be represented by more
        than one character, and are comma seperated. Example valid inputs:
            [(A,a)(B,b)][(A,a)(B,b)]
            [(A,A)(Xc,Y)][(a,A)(Xc,Xc)]
'''


def convert_to_gamete(binary_str, parent):

    binary_str = binary_str[2:]
    binary_str = '0'*(len(parent)-len(binary_str)) + binary_str

    if len(binary_str) is not len(parent):
        print 'Size of binary conversion string wrong!'
        sys.exit(0)

    out = tuple()
    for i, c in enumerate(binary_str):
        if c == '1': out += (parent[i][1],)
        else: out += (parent[i][0],)

    return out

def convert_gamete_str(fset):
    out = ''
    for c in fset:
        out += c
    return out

def main(simple):
    print 'Traits need to be in same order for both parents. Type quit to exit program.'
    raw_in = raw_input("Please enter your cross: ")
    if raw_in.lower() == 'quit': return True

    parent_one = raw_in.split(']')[0][1:]
    parent_two = raw_in.split(']')[1][1:]

    if not simple:
        parent_one = [x for x in re.split(r'[()]', parent_one) if x is not '']
        parent_one = [sorted(trait.split(',')) for trait in parent_one]

        parent_two = [x for x in re.split(r'[()]', parent_two) if x is not '']
        parent_two = [sorted(trait.split(',')) for trait in parent_two]

    else:
        if len(parent_one) % 2 != 0 or len(parent_two) != len(parent_one):
            print 'Parents do not have correct number of traits'
            sys.exit(0)

        parent_one = [sorted([i,j]) for i,j in zip(parent_one[0::2], parent_one[1::2])]
        parent_two = [sorted([i,j]) for i,j in zip(parent_two[0::2], parent_two[1::2])]


    if len(parent_two) is not len(parent_one):
        print 'Parents do not have same number of traits!'
        sys.exit(0)

    for i, trait in enumerate(parent_one):
        if len(trait) is not 2:
            print 'Parents do not have two alleles for trait', trait
            sys.exit(0)

    for i, trait in enumerate(parent_two):
        if len(trait) is not 2:
            print 'Parents do not have two alleles for trait', trait
            sys.exit(0)

    gametes_one = set()
    gametes_two = set()
    for i in xrange(2**len(parent_one)):
        gametes_one.add(convert_to_gamete(bin(i), parent_one))
        gametes_two.add(convert_to_gamete(bin(i), parent_two))

    print ''
    print '\t'+'\t'.join([convert_gamete_str(gamete) for gamete in gametes_one])
    for gamete_i in gametes_two:
        sys.stdout.write("".join(gamete_i))
        sys.stdout.write('\t')
        for gamete_j in gametes_one:
            child = "".join([gamete_j[i]+gamete_i[i] for i in range(len(gamete_i))])
            sys.stdout.write(child)
            sys.stdout.write('\t')
        sys.stdout.write('\n')
    print ''

    return False
    
if __name__ == '__main__':

    if len(sys.argv) == 1:
        simple = False
    elif len(sys.argv) == 2 and sys.argv[1] == 'simple':
        simple = True
    else:
        print 'Incorrect usage of program parameters. \'simple\' is the only parameter'
        sys.exit(0)

    exit = False
    while(not exit):
        exit = main(simple)

