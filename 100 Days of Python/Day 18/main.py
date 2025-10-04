from turtle import Turtle, Screen, color, forward, right

mahdi_the_turtle = Turtle()
# for steps in range(100):
#     for c in ('blue', 'red', 'green'):
#         color(c)
#         forward(steps)
#         right(30)

# mahdi_the_turtle.left(90)
# mahdi_the_turtle.forward(200)
# mahdi_the_turtle.right(90)
# mahdi_the_turtle.forward(200)
# mahdi_the_turtle.right(90)
# mahdi_the_turtle.forward(200)
# mahdi_the_turtle.right(90)
# mahdi_the_turtle.forward(200)


for _ in range(15):
    mahdi_the_turtle.forward(10)
    mahdi_the_turtle.color("white")
    mahdi_the_turtle.forward(10)
    mahdi_the_turtle.color("black")

wind_screen = Screen()

wind_screen.exitonclick()

