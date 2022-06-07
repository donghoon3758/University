while 1:
    student = []
    count = int(input("Input count:"))
    for i in range(0, count):
        student.append(input("Input student info (name, age, course list): ").split(', '))

    print("Input print options")
    print("\t1: By Name")
    print("\t2: By Age")
    print("\t3: By Courses Count")
    print("\t9: Restart Program")

    while 1:
        option = int(input("Enter the option: "))
        if (option == 1):
            student.sort(key=lambda x: x[0])
            for i in range(0, count):
                print("student",i+1,": (name: " + student[i][0] + ", age:",
                    student[i][1],", course list:", student[i][2:])
        elif (option == 2):
            student.sort(key=lambda x: x[1])
            for i in range(0, count):
                print("student" ,i+1 , ": (name: " + student[i][0] + ", age:",
                    student[i][1],", course list:", student[i][2:])
        elif (option == 3):
            student.sort(key=lambda x: len(x[2:]), reverse=True)
            for i in range(0, count):
                print("student" ,i+1 , ": (name: " + student[i][0] + ", age:",
                    student[i][1],", course list:", student[i][2:])

        elif option == 9:
            break

