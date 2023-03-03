class DFA:
    def __init__(self, Q, Sigma, F, delta):
        self.Q = list(map(int, Q))
        self.Sigma = Sigma
        self.q0 = self.Q[0]
        self.F = list(map(int, F))
        self.delta = delta

    def validate(self, str):
        state = self.q0
        for ch in str:
            if ch not in self.Sigma:
                return 'NO'
            for transition in self.delta[state]:
                if ch in transition:
                    state = self.delta[state].index(transition)
        if state in self.F:
            return 'YES'
        return 'NO'


n, m = map(int, input().split())
Q, Sigma, F = input().split(), input().split(), input().split()
delta = [[[] for i in range(n)] for j in range(n)]
for i in range(n*m):
    nstart, char, ndest = input().split()
    delta[int(nstart)][int(ndest)].append(char)

dfa = DFA(Q, Sigma, F, delta)
print(dfa.validate(input()))
