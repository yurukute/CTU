class DFA:
    def __init__(self, Q, Sigma, F, delta):
        self.Q = Q
        self.Sigma = Sigma
        self.q0 = self.Q[0]
        self.F = F
        self.delta = delta

    def validate(self, str):
        state = self.q0
        for ch in str:
            if ch not in self.Sigma:
                return 'NO'
            state = self.delta[state][ch]
        if state in self.F:
            return 'YES'
        return 'NO'


n, m = map(int, input().split())
Q, Sigma, F = input().split(), input().split(), input().split()
delta = {}
for i in range(n*m):
    nstart, char, ndest = input().split()
    if nstart in delta:
        delta[nstart].update({char: ndest})
    else:
        delta.update({nstart: {char: ndest}})

dfa = DFA(Q, Sigma, F, delta)
print(dfa.validate(input()))
