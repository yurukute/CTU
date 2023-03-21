import json


class NFA:
    def __init__(self, Q, sigma, q0, F, delta):
        self.Q = sorted(Q)
        self.q0 = q0
        self.sigma = sorted(sigma)
        self.F = sorted(F)
        self.delta = delta

    def validate(self, str):
        states = [self.q0]
        for c in str:
            if c not in self.sigma:
                return 'NO'
            next_states = []
            for q in states:
                if q in self.delta and c in self.delta[q]:
                    next_states.extend(self.delta[q][c])
            states = sorted(next_states)
        if set(states) & set(self.F):
            return 'YES'
        return 'NO'


data = json.load(open(input()))
nfa = NFA(data['Q'], data['sigma'], data['q0'], data['f'], data['delta'])
t = []
for i in range(int(input())):
    t.append(input())
for str in t:
    print(nfa.validate(str))
