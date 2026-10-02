import sys
import re


def tokenize(text):
    return re.findall(r'[()\.]|[A-Za-z]+', text)


def split_datasets(tokens):
    datasets = []
    current = []
    for tok in tokens:
        if tok == '.':
            datasets.append(current)
            current = []
        else:
            current.append(tok)
    return datasets


def parse_dataset(tokens):
    nodes = set()
    edges = {}
    idx = 0
    n = len(tokens)
    while idx < n:
        idx += 1
        fun = tokens[idx]
        idx += 1
        nodes.add(fun)
        calls = edges.setdefault(fun, set())
        while tokens[idx] != ')':
            callee = tokens[idx]
            calls.add(callee)
            nodes.add(callee)
            idx += 1
        idx += 1
    for node in nodes:
        edges.setdefault(node, set())
    return nodes, edges


def tarjan_scc(nodes, edges):
    index_counter = [0]
    index = {}
    lowlink = {}
    on_stack = {}
    stack = []
    result = []

    for start in nodes:
        if start in index:
            continue

        index[start] = index_counter[0]
        lowlink[start] = index_counter[0]
        index_counter[0] += 1
        stack.append(start)
        on_stack[start] = True

        work_stack = [(start, iter(edges[start]))]

        while work_stack:
            v, it = work_stack[-1]
            recursed = False
            for w in it:
                if w not in index:
                    index[w] = index_counter[0]
                    lowlink[w] = index_counter[0]
                    index_counter[0] += 1
                    stack.append(w)
                    on_stack[w] = True
                    work_stack.append((w, iter(edges[w])))
                    recursed = True
                    break
                elif on_stack.get(w, False):
                    if index[w] < lowlink[v]:
                        lowlink[v] = index[w]
            if recursed:
                continue

            work_stack.pop()
            if work_stack:
                parent = work_stack[-1][0]
                if lowlink[v] < lowlink[parent]:
                    lowlink[parent] = lowlink[v]

            if lowlink[v] == index[v]:
                comp = []
                while True:
                    w = stack.pop()
                    on_stack[w] = False
                    comp.append(w)
                    if w == v:
                        break
                result.append(comp)

    return result


def modularize(tokens):
    if not tokens:
        return []
    nodes, edges = parse_dataset(tokens)
    if not nodes:
        return []
    sccs = tarjan_scc(nodes, edges)
    modules = [sorted(comp) for comp in sccs]
    modules.sort(key=lambda m: m[0])
    return [' '.join(m) for m in modules]


tokens = tokenize(sys.stdin.read())
datasets = split_datasets(tokens)

out_lines = []
for ds in datasets:
    for line in modularize(ds):
        out_lines.append(line)
    out_lines.append('')

sys.stdout.write('\n'.join(out_lines))
if out_lines:
    sys.stdout.write('\n')