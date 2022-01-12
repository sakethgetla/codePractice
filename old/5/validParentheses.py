from pdb import set_trace as bp

def isValid(line):
    stack = []
    for s in line:
        #bp()
        if (s == '{' ):
            stack.append('}')
        elif (s == '[' ):
            stack.append(']')
        elif (s == '('):
            stack.append(')')
        elif (s == '}' or s == ']' or s == ')'):
            if (len(stack) == 0 or stack.pop() != s):
                return False
    return len(stack) == 0

print(isValid('()'))
print(isValid('((})[]{})'))
print(isValid('(()[]{})'))
print(isValid('()'))
