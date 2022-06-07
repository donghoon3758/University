while 1:
    teamA = input("Input team A scores:")
    teamB = input("Input team B scores:")

    AScore = int(teamA[0])+int(teamA[1])+int(teamA[2])+int(teamA[3])+int(teamA[4])


    BScore = int(teamB[0])+int(teamB[1])+int(teamB[2])+int(teamB[3])+int(teamB[4])
    print(AScore > BScore)
