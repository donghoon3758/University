import turtle

turtle.shape('turtle')
turtle.penup()
turtle.screensize(200,200)
turtle.setup(250,250)
turtle.speed(0)

colors = [0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1]

k=0
turtle.color(0,0,0)
turtle.goto(-100,-100)
color = 0
for i in range(-100,101,20):
    k+=1
    if(color>=1 and k==2):
        color=0.1
    elif(color>=1 and k==3):
        color=0.15
    elif(color>=1 and k==4):
        color=0.2
    elif(color>=1 and k==5):
        color=0.25
    elif(color>=1 and k==6):
        color=0.3
    elif(color>=1 and k==7):
        color=0.45
    elif(color>=1 and k==8):
        color=0.6
    elif(color>=1 and k==9):
        color=0.7
    elif(color>=1 and k==10):
        color=0.8
    for j in range(-100,101,20):
        if(color>=1):
            color=1
        turtle.goto(i,j)
        turtle.color(color,0,0)
        turtle.stamp()
        color+=0.1
