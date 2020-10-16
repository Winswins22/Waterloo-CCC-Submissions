streamList = []

for getListInfo in range(int(input())):
    streamList.append(int(input()))

while True:

    split_Join_Or_End = input()

    # check for 99. if 99: (split)
    if split_Join_Or_End == "99":
        # get infos
        streamNum = int(input())
        percentLeft = int(input()) / 100

        # list.pop streamNum-1 (get the thing being splitted)
        beingSplitted = streamList.pop(streamNum - 1)

        # manipulate % of stream left/right
        leftStream = percentLeft * beingSplitted
        rightStream = (1 - percentLeft) * beingSplitted

        # list.insert streamNum-1, (right then left)
        streamList.insert(streamNum - 1, rightStream)
        streamList.insert(streamNum - 1, leftStream)

    # check for 88, if 88: (join)
    if split_Join_Or_End == "88":
        # get infos
        streamNum = int(input())

        # list.pop streamNum-1 x2, add them
        leftStream = streamList.pop(streamNum - 1)
        rightStream = streamList.pop(streamNum - 1)

        total = leftStream + rightStream

        # list.insert streamNum - 1
        streamList.insert(streamNum - 1, total)

    # check for 77. if 77: (end)
    if split_Join_Or_End == "77":
        # break
        break

# output rounded nums in list
for i in range(len(streamList)):
    print(round(streamList[i]), end= " ")