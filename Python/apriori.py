def powerset(fullset):
    listsub = list(fullset)
    subsets = []
    for i in range(2**len(listsub)):
        subset = []
        for k in range(len(listsub)):
            if i & 1 << k:
                subset.append(listsub[k])
        subsets.append(subset)
    return subsets




set1 = {
    "T1": ["milk", "tea", "cake"],
    "T2": ["eggs", "tea", "pepsi"],
    "T3": ["milk", "eggs", "tea", "pepsi"],
    "T4": ["eggs", "pepsi"],
    "T5": ["juice"]
}

min_sup = 2
min_conf = 0.6



def apriori_algo(transactions, min_sup, min_conf):
    freq = {}
    for each in transactions.values():
        for i in each:
            if i in freq:
                freq[i] += 1
            else:
                freq[i] = 1

    freq = {k: v for k, v in freq.items() if v >= min_sup}

    item_set = powerset(freq.keys())
    item_set = [frozenset(i) for i in item_set if len(i) > 0]

    freq_item_set = {}
    for each in transactions.values():
        for i in item_set:
            if i.issubset(each):
                if i in freq_item_set:
                    freq_item_set[i] += 1
                else:
                    freq_item_set[i] = 1
    freq_item_set = {k: v/len(transactions)
                     for k, v in freq_item_set.items() if v >= min_sup}

    rules = []
    for k, v in freq_item_set.items():
        for each in powerset(k):
            if len(each) is not 0 and len(k.difference(each)) is not 0:
                remain = k.difference(each)
                confidence = v/freq_item_set[remain]
                rules.append(((tuple(each), tuple(remain)), confidence))

  

    freqently_bought_together = []
    for k, v in freq_item_set.items():
        if v*len(transactions) >= min_sup and len(k) == 3:
            freqently_bought_together.append(k)

    freqently_bought_together = {
        frozenset(i) for i in freqently_bought_together}

    return freq_item_set, rules, freqently_bought_together





def prettyPrint(apriori_algo, transactions):
    print("Apriori Algorithm")
    print("-"*40)
    print("Transactions")
    print("-"*40)
    for k, v in transactions.items():
        print(k, ":", v)
    print("\n")
    print("Frequent Itemsets")
    print("-"*40)
    for k, v in apriori_algo[0].items():
        print(tuple(k), ":", v)
    print("\n")
    print("Freqently Bought Together")
    print("-"*40)
    for k in apriori_algo[2]:
        print(tuple(k))
    print("\n")
    print("Rules")
    print("-"*40)
    c = 1
    for each in apriori_algo[1]:
        print(c, ".", each[0][0], "-->", each[0][1], ":", each[1], end=" ")
        if each[1] >= min_conf:
            print("(Rule is Strong)")
        else:
            print("(Rule is Weak)")
        c += 1
    print("\n")


if __name__ == "__main__":
    prettyPrint(apriori_algo(set1, min_sup, min_conf), set1)
