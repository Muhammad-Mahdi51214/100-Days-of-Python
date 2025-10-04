# student_scores = {
#     "Harry": 81,
#     "Ron": 78,
#     "Hermione": 99,
#     "Draco": 74,
#     "Neville": 62,
# }

# student_grades = {}

# for student, score in student_scores.items():
#     if 91 <= score <= 100:
#         student_grades[student] = "Outstanding"
#     elif 81 <= score <= 90:
#         student_grades[student] = "Nice"
#     elif 71 <= score <= 80:
#         student_grades[student] = "Acceptable"
#     elif score <= 70:
#         student_grades[student] = "Fail"

# print(student_grades)



# Nested Lists and dictionary------

# travel_log = [
# {
#   "country": "France",
#   "visits": 12,
#   "cities": ["Paris", "Lille", "Dijon"]
# },
# {
#   "country": "Germany",
#   "visits": 5,
#   "cities": ["Berlin", "Hamburg", "Stuttgart"]
# },
# ]


# def add_new_country(country_name, a , list_of_cities=[]):
#     new_country={
#         "country": country_name,
#         "visits" : int(a),
#         "cities" : list_of_cities
#         }
#     travel_log.append(new_country)

# add_new_country("Russia", 2, ["Moscow", "Saint Petersburg"])
# print(travel_log)


# Challange

import os

# Clearing the Screen

def add_bid():
    name=input("Enter your name : ")
    bid = input("Enter your bid?? $")
    bid_dict[name]=int(bid)

    other=input("If another person want to bid?? yes or no :  ")
    other.lower()
    if (other == 'yes'):
        os.system('cls')
        add_bid()
    elif(other=="no"):
        max=name
        for a in bid_dict:
            if(bid_dict[a]>bid_dict[max]):
                max=a
        os.system('cls')
        print(f"Mr {max} has a big bid of {bid_dict[max]}")
bid_dict={}
add_bid()
