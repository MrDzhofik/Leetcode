import randomized_set


def test_success():
    rnd_set = randomized_set.RandomizedSet()
    commands = [
        "RandomizedSet",
        "insert",
        "remove",
        "insert",
        "getRandom",
        "remove",
        "insert",
        "getRandom",
    ]
    values = [[], [1], [2], [2], [], [1], [2], []]

    ans = []
    for i, command in enumerate(commands):
        if command == "RandomizedSet":
            ans.append(None)
        elif command == "insert":
            ans.append(rnd_set.insert(values[i][0]))
        elif command == "remove":
            ans.append(rnd_set.remove(values[i][0]))
        elif command == "getRandom":
            ans.append(rnd_set.getRandom())

    assert ans == [None, True, False, True, 2, True, False, 2]


test_success()
